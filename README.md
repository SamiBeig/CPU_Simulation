WELCOME! This project was for my Operating Systems class in my Undergraduate studies. The purpose of this program was to mimic how a CPU handles processes and how it interacts with I/O devices.

Scheduling: I created this program by implementing preemptive priority CPU-scheduling. This means that if a process with higher priority arrives than the one currently being executed by the CPU, the CPU will effectively swap the two processes, so the process with the highest priority is always being handled. Higher numbers mean higher priority.

All I/O-queues are First Come First Serve!

Each process in this program is represented by its own PCB (obviously!). We do not want to move around the whole PCBs. So we store all PCBs in a process table and we move around only the indexes of processes in that table.

At the start, this program asks the user three questions:

How much RAM memory is there on the simulated computer? Your program receives the number in bytes (no kilobytes or words). I can enter any number up to 4000000000 (4 billions). Make sure you use datatypes that will not be overflown by such value. How many hard disks does the simulated computer have? The enumeration of the hard disks starts with 0.

After these questions are answered, the simulation begins. You program constantly listens for the user inputs. You should NOT ask for a confirmation to enter another input. The user inputs signal some system events. Your program simulates the corresponding system behavior. The possible inputs are:

A priority memory_size: ‘A’ input means that a new process has been created. This process has a priority priority and requires memory_size bytes of memory.

When choosing a PID for a new process start from 1 and go up. Do NOT reuse PIDs of the terminated processes.

't': The process that is currently using the CPU terminates. It leaves the system immediately. Make sure you release the memory used by this process in your simulation. Pay attention, once the process is gone from the system it is also gone from the memory.

'd' number file_name: The process that currently uses the CPU requests the hard disk #number. It wants to read or write the file file_name.

'D' number: The hard disk #number has finished the work for one process.

'S r': Shows a process currently using the CPU and processes waiting in the ready-queue. For each process I need to see its PID and priority. Make sure that the process using the CPU is obvious (mark it somehow).

'S i': Shows what processes are currently using the hard disks and what processes are waiting to use them. For each busy hard disk show the process that uses it and show its I/O-queue. Make sure to display the filenames (from the d command) for each process. The enumeration of hard disks starts from 0. Processes in I/O-queue should be displayed in the correct queue order. Remember that our I/O-queues are FCFS.

This project was very helpful to impliment while taking Operating Systems. Not only did it help me visualize and understand the concept of a CPU, it helped me realize how important the CPU really is in computers!
