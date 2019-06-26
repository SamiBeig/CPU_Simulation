#include "Disk.hpp"
#include "process.hpp"
#include <iostream>

using namespace std;

//Adds input to the I/O Queue
void Disk::add(process input){
    IO_Queue.push_back(input);
}

//Set function for string file_name
void Disk::setFileName(string input){
    file_name=input;
}

string Disk::getFileName(){
    return file_name;
}

//Deletes the Process currently using the Disk (front of I/O Queue)
void Disk::deleteNext(){
    IO_Queue.pop_front();
}

//Displays everything in the Disk, with the front of the I/O Queue being used by the Disk
void Disk::display(){
    for(int i=0; i < IO_Queue.size(); i++){

        cout<<"Process "<<i<<": "<<"  ";
        cout<<"Priority is: "<< IO_Queue[i].getProcessPriority()<<"   ";
        cout<<"Memory size is: "<<IO_Queue[i].getProcessMemSize()<<"   ";
        cout<<"PID is: "<<IO_Queue[i].getPID()<<"    ";
        cout<<"File Name is: "<<file_name<<"    ";
        	
	if(i==0){
            cout<<endl<<"^This Process is currently using the Disk!";
        }
        if(i != 0){
	    cout<<endl<<"^This is waiting in the I/O-Queue!";
	}
        cout<<endl;

    }
}

//Returns true if IO_Queue is empty
bool Disk::isEmpty(){
    if(IO_Queue.empty()){
        return true;
    }
    else{
        return false;
    }
}

//Returns the process being currently used by the IO Queue
process Disk::currentProcess(){
    return IO_Queue.front();
}




