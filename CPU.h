#ifndef CPU_H
#define CPU_H
#include <queue>
#include <deque>
#include <string>
#include "process.hpp"

using namespace std;

class CPU
{
public:
    //Checks to see if the CPU is being used or not
    bool isVacant();
    
    //Return size of processes
    int getSize();
    
    //Add new process to ready queue named processes
    void addProcess(process input);
    
    //Shows the next process in ready queue
    process nextProcess();
    
    //Deletes whatever is in front (being used by the CPU) and moves on to the next
    void deleteProcess();
    
    //Shows all processes waiting for the CPU, with their priority, mem size, and PID
    void displayProcesses();
    
    //Checks to see if the currently running process needs to be preempted
    void preempt(process input);
    
    //In the case of preempting after a process has gone to a disk, it will check to see if
    // the ready-queue needs to be preempted
    void preempt();
    
private:
    //Starts out as true since CPU is not occupied in the beginning of simulation
    bool vacant = true;

    std::deque<process> processes;
};

#endif

