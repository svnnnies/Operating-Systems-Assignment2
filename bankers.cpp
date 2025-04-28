// Layth Alabed
#include "safety.hpp"

int main() {
    int processIDs[NUM_PROCESSES];
    for (int i = 0; i < NUM_PROCESSES; i++)
        processIDs[i] = i; // Initialize process IDs

    std::ifstream inputFile("input.txt", std::ios_base::in);
    if (!inputFile) {
        std::cout << "Failed to open input.txt." << std::endl;
        return EXIT_FAILURE;
    }

    int maxDemand[NUM_PROCESSES][NUM_RESOURCES];
    int allocatedResources[NUM_PROCESSES][NUM_RESOURCES];
    int availableResources[NUM_RESOURCES];

    // Read allocated resources and maximum demand from file
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        for (int j = 0; j < NUM_RESOURCES; ++j) 
            inputFile >> allocatedResources[i][j];
        for (int j = 0; j < NUM_RESOURCES; ++j) 
            inputFile >> maxDemand[i][j];
    }

    // Read available resources from file
    for (int j = 0; j < NUM_RESOURCES; ++j)
        inputFile >> availableResources[j];

    // Debug: Print allocated resources
    cout << "Allocated Resources: " << endl;
    for (int i = 0; i < NUM_PROCESSES; ++i){
        cout << "P" << i << ": ";
        for (int j = 0; j < NUM_RESOURCES; ++j) 
            cout << allocatedResources[i][j] << ' ';
        cout << "\n";
    }
    cout << endl;

    // Debug: Print maximum demands
    cout << "Maximum Demand: " << endl;
    for (int i = 0; i < NUM_PROCESSES; ++i){
        cout << "P" << i << ": ";
        for (int j = 0; j < NUM_RESOURCES; ++j) 
            cout << maxDemand[i][j] << ' ';
        cout << "\n";
    }
    cout << endl;

    // Debug: Print available resources
    cout << "Available Resources: ";
    for (int i = 0; i < NUM_RESOURCES; ++i) 
        cout << availableResources[i] << ' ';
    cout << "\n" << endl;

    // Performs the safety check
    checkSystemSafety(processIDs, availableResources, maxDemand, allocatedResources);
}
