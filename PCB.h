#ifndef PCB_H
#define PCB_H

#include "process.hpp"
#include <iostream>
#include <vector>

class PCB{
public: 
	//Add process into PCB table
	void addProcess(process input);
		

private: 
	std::vector<process> PCB_Table;

};

#endif


