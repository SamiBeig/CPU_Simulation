#ifndef Disk_hpp
#define Disk_hpp

#include "process.hpp"
#include <iostream>
#include <queue>
#include <deque>

using namespace std;


class Disk
{
public:
    
    //Adding a process to the I/O Queue
    void add(process input);

    //Based on user input, disk will be prompted to read a certain file name
    void setFileName(string input);
    
    //Returns filename
    string getFileName();
    
    //Deletes whatever is being used by the Disk (front of the I/O Queue
    void deleteNext();
    
    //Displays the processes in the I/O Queue
    void display();
    
    //Checks to see if IO_Queue is empty
    bool isEmpty();
    
    //Returns the process using the IO Queue at the moment
    process currentProcess();
    
private:
    std::deque<process> IO_Queue;
    string file_name;
};

#endif
