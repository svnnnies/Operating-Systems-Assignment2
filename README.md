# Operating-Systems-Assignment2
Contains code for Banker's Algorithm for Operating Systems at Kent State 

Question Overview:
Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. 
Suppose at time t0 following snapshot of the system has been taken:
| Process | Allocation | Max | Available |
| --- | --- | --- | --- |
| P0 | 0 1 0 | 7 5 3 | 3 3 2 |
| P1 | 2 0 0 | 3 2 2 |  |
| P2 | 3 0 2 | 9 0 2 |  |
| P3 | 2 1 1 | 2 2 2 |  |
| P4 | 0 0 2 | 4 3 3 |  |

Implement the Banker’s algorithm to answer the following question： 
Is the system in a safe state? If Yes, then what is the safe sequence?

# Assignment Overview:
This project implements the Banker's Algorithmm, a traditional resource allocation and deadloch avoidance algorithm, to determine the safety of a system state, ensuring process completion withoud deadlock. 

This program reads:
- The current allocation of resources.
- The maximum demand of each process.
- THe currently available resources.

The project contains three main files: (no executable/.o files were commited/added)
- safety.hpp 
- bankers.cpp 
- input.txt 

The following program modifies the given table to a text file titled input.txt, which contains the system's resource allocation, maximum demands, and available resources. The banker's algorithm is primarily implemented in the safety.hpp file and the bankers.cpp file. 

# Compilation 

In this assignment I used the same method as the last assignment whiuch is wasp on vscode as it already has all the packages that we need to use already preinstalled (worked perfectly fine for me and its the most convenient option). So in order to compile this project I can go through a quick rundown on how I did it on my vscode.

1- cd OS //open the OS folder

2- cd Assignment2 //opens the subfolder that's inside the OS folder

Assingnment2 contains all the files and code necessaery for the Banker's . Now in order to compile and run the program you open up the terminal and use this command. (I used pthread again because we used it in the previous assignment).

```bash
g++ banker.cpp -pthread -o banker
./banker
```
# Output 

```bash
Allocated Resources: 
P0: 0 1 0 
P1: 2 0 0 
P2: 3 0 2 
P3: 2 1 1 
P4: 0 0 2 

Maximum Demand: 
P0: 7 5 3 
P1: 3 2 2 
P2: 9 0 2 
P3: 2 2 2 
P4: 4 3 3 

Available Resources: 3 3 2 

The system is in a safe state. Safe sequence is: 1 3 4 0 2
```
If you want a better visualization you can check the example.txt file (conatins the output that I got in my vscode terminal). 
