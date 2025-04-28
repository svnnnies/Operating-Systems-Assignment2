// Layth Alabed

#ifndef SAFETY_HPP_
#define SAFETY_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <pthread.h>

using std::cout;
using std::endl;

// These are the constants for the number of processes and resources
const int NUM_PROCESSES = 5; //processes 
const int NUM_RESOURCES = 3; //resources 

// A bool function to check system safety using Banker's Algorithm
bool checkSystemSafety(int processIDs[], int availableResources[], int maxDemand[][NUM_RESOURCES], int allocatedResources[][NUM_RESOURCES]) {
    
    int neededResources[NUM_PROCESSES][NUM_RESOURCES];

    // Calculates the needed resources for each one of the processes
    for (int i = 0; i < NUM_PROCESSES; i++) 
        for (int j = 0; j < NUM_RESOURCES; j++) 
            neededResources[i][j] = maxDemand[i][j] - allocatedResources[i][j];

    bool finishedProcesses[NUM_PROCESSES] = {0};  // Tracks the finished processes
    int safeSequence[NUM_PROCESSES];              // Stores safe execution sequence

    int workResources[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; i++) 
        workResources[i] = availableResources[i]; // Initialize work with available resources

    int completedCount = 0; // Counter to count the number of completed processes 
    while (completedCount < NUM_PROCESSES) {
        bool foundProcess = false;
        for (int p = 0; p < NUM_PROCESSES; p++) {
            if (!finishedProcesses[p]) { // Process is not finished yet 
                int j;
                for (j = 0; j < NUM_RESOURCES; j++) 
                    if (neededResources[p][j] > workResources[j]) 
                        break;

                // If all needed resources are available
                if (j == NUM_RESOURCES) {
                    for (int k = 0; k < NUM_RESOURCES; k++) 
                        workResources[k] += allocatedResources[p][k]; // Release resources

                    safeSequence[completedCount++] = p; // Add process to safe sequence
                    finishedProcesses[p] = true;
                    foundProcess = true;
                }
            }
        }

        // If no process could be found, system is unsafe
        if (!foundProcess) {
            cout << "The system is not in a safe state." << endl; //Prints the not safe state sequence
            return false;
        }
    }

    // Safe state found, print the sequence
    cout << "The system is in a safe state. Safe sequence is: "; //Prints the safe state sequence 
    for (int i = 0; i < NUM_PROCESSES; i++) 
        cout << safeSequence[i] << ' ';
    cout << endl;
    return true;
}

#endif
