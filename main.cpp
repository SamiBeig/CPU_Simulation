/*
Name: Sami Beig
 CSCI 340 Home Project
 Instructor: Pavel Shostak
 
This project simulates how the Operating System works with processes. Whether it is adding processes to the Ready-Queue, waiting to use the CPU, or a process is being used by an I/O-Queue, the Operating System is in charge of all of these tasks. By pressing different commands, the simulation will act accordingly.
*/
#include <iostream>
#include "process.hpp"
#include "CPU.h"
#include "Disk.hpp"
#include "PCB.h"
#include <string>
#include <deque>
#include <sstream>

using namespace std;

int main(){
    
    
    CPU boss;
    PCB table;
    long long memory;    

    string input;
    
    int PID_COUNTER=1;

    cout<<"How much RAM memory is there on the simulated computer?"<<endl;
    cin>>memory;
    
    int SIZE;
    cout<<"How many disks are in this program?"<<endl;
    cin>>SIZE;
    
    Disk disks[SIZE];
    
    
    
    while(input!="Exit"){
        
        getline(cin, input);
        
        //If user inputs A, a process will be added to the Queue.
        if(input[0]=='A'){
	    
            input.erase(0,2);	

            int x;
            int y;
	    long long input2;
	    int count=0;
            
	    istringstream input1(input);

	    while(input1 >> input2){
		if(count == 0){
			x = input2;
			count++;
		}
		if(count == 1){
			y = input2;
		}

            }

            process A(x, y);
            A.setPID(PID_COUNTER);
            PID_COUNTER++;
            boss.addProcess(A);
            
            if(boss.getSize() > 1){
                boss.preempt(A);
            }
            
	    table.addProcess(A);
        }
        
        //If user inputs t, the process being used by the CPU will be deleted
        if(input[0]=='t'){
            boss.deleteProcess();
            if(boss.getSize() > 1){
                boss.preempt();
            }
        }
    
        //Displaying the processes in the ready queue
        if(input[0]=='S' && input[2]=='r'){
            boss.displayProcesses();
        }
        
        //Putting the process in the CPU
        if(input[0]=='d'){
            input.erase(0,2);
            int diskNumber = stoi (input.substr(0,1));
            disks[diskNumber].add(boss.nextProcess());
            input.erase(0,2);
            disks[diskNumber].setFileName(input);
            
            boss.deleteProcess();
        }
    
        //Displaying all disks
        if(input[0]=='S' && input[2]=='i'){
            for(int i=0; i < SIZE; i++){
                cout<<"This is Disk "<<i<<endl;
                if(disks[i].isEmpty()){
                    cout<<"This is empty!"<<endl;
                }
                disks[i].display();
            }
        }
        
        //Deletes the currently running process in selected disk number, and will
        //transfer that same process into the ready-queue, preempting if needed
        if(input[0]=='D'){
            input.erase(0,2);
            int diskNumber= stoi(input);
            process current = disks[diskNumber].currentProcess();
            disks[diskNumber].deleteNext();
            boss.addProcess(current);
            boss.preempt();
        }
    }
    
    return 0;
}

