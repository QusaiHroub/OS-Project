/*
 * This file is part of OS Project.
 *
 * Authors
 * Qusai Hroub
 * Mohammad Abureesh
 *
 * C++ program for implementation of FCFS algorithm
 * this file, declaration for "FCFS.hpp"
 */


#include <algorithm>
#include "fcfs.hpp"

/*
This constructor receives an array of Processes, context Switch (CS), 
and the size of the operations, and if the array equals nullptr, 
it returns and does not implement the algorithm. Otherwise, it calls the function that implements the algorithm init().
*/
FCFS::FCFS(Process *processes, int cs, int processesSize): ProcessManagement(processes, cs, processesSize) {
    if (processes == nullptr) {
        return;
    }

    //call this function for implements FCFS algorithm
    init(); 
}

//deconstructor
FCFS::~FCFS() {
}

//this function return true, when the arrival time of the first process is less than the arrival time of the second process.
bool FCFS::comp(Process &p1, Process &p2) {
    return p1.getArrivalTime() < p2.getArrivalTime();
}

//this function work on implementation <FCFS> algorithm 
void FCFS::init() {
    
    //getProcesse() function defined in the <ProcessManagement> class return array of Processes
    Process *processes = getProcesses(); 
    
    //Arrange the Processes based on the arrival time before starting the calculations
    sort(processes, processes + getProcessesSize(), comp);

 //these functions are defined in the <ProcessManagement> class.   
    
    calcCompletionTime();
    calcTurnAroundTime();
    calcWaitingTime();
    
    //As long as this variable equals true means that the algorithm has been implemented
    is_init = true;
}
