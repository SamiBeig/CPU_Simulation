#include "CPU.h"
#include "process.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//Returns size of Ready Queue
int CPU::getSize(){
    return processes.size();
}

//Adding a new process to the CPU ready-queue
void CPU::addProcess(process input){
    processes.push_back(input);
}

//Returns the next process in CPU ready queue
process CPU::nextProcess(){
    return processes.front();
    //return processes.back();
}

//Terminates the process in front, if there is anything
void CPU::deleteProcess(){
    
    //if the queue is empty already, statement will be outputted
    if(processes.empty()){
        cout<<"There are no processes in the ready-queue. "<<endl;
    }
    //Will pop a process, and will check to see if vacant needs to be modified
    else{
        processes.pop_front();
        //processes.pop_back();
        
        if(processes.size()==0){
            vacant=true;
        }
    }
    
}

//Displays everything in Ready-Queue
void CPU::displayProcesses(){
    
    for(int i=0; i < processes.size(); i++){
        cout<<"Process "<<i<<": "<<"  ";
        cout<<"Priority is: "<< processes[i].getProcessPriority()<<"   ";
        cout<<"Memory size is: "<<processes[i].getProcessMemSize()<<"   ";
        cout<<"PID is: "<<processes[i].getPID()<<"    ";
        if(i==0){
            cout<<endl<<"^This Process is in the CPU^";
        }
        if(i != 0){
	    cout<<endl<<"^This is in the Ready-Queue!^";
	}
        cout<<endl;

    }
}

//If newly inputted process into ready-queue has higher priority, it will be put into the CPU
void CPU::preempt(process input){
    if(processes.front().getProcessPriority() < processes.back().getProcessPriority()){

        processes.push_front(input);
        processes.pop_back();
    }
}


void CPU::preempt(){
    if(processes.front().getProcessPriority() < processes.back().getProcessPriority()){
        process temp = processes.front();
        processes.pop_front();
        processes.push_front(processes.back());
        processes.pop_back();
        processes.push_back(temp);
    }
}


