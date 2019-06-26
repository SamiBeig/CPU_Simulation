#ifndef PROCESS_H
#define PROCESS_H


class process
{
public:
    //Constructor takes in two ints, first is priority and second is memory
    process(int p, int m);
    
    //get function for priority
    int getProcessPriority();
    
    //get function for memory size
    long long getProcessMemSize();
    
    //returns PID of process
    int getPID();
    
    //Set function to set PID
    void setPID(int input);
    
private:
    int priority;
    int memory_size;
    int PID;
    
    
};

#endif

