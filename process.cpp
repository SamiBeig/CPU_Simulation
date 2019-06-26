#include "process.hpp"
#include <iostream>

using namespace std;

//Set priority and memory_size to variables passed
process::process(int p, int m){
    
    priority=p;
    memory_size=m;
}

//get function for priority
int process::getProcessPriority(){
    return priority;
}

//get function for mem size
long long process::getProcessMemSize(){
    return memory_size;
}

//Returns PID of process
int process::getPID(){
    return PID;
}

//Set PID to int passed in
void process::setPID(int input){
    PID=input;
}

