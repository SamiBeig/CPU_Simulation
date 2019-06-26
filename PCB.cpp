#include "process.hpp"
#include "PCB.h"
#include <vector>

using namespace std;

//Add process to PCB_Table
void PCB::addProcess(process input){
	PCB_Table.push_back(input);
}
