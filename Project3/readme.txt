Hunter Damron
Graham McDonald
Reed Segars

Part 1 - Regular File IO
------
To compile:
gcc reg_io.c

To run:
./a.out FILENAME


Part 1 - Memory Mapped File IO
------
To compile:
gcc mmf_io.c

To run:
./a.out FILENAME


Team Contributions:
  Hunter Damron worked on:
      Part 2

  Graham McDonald worked on:
      Readme/Report

  Reed Segars worked on:
      Part 1


Description:
The regular file IO program took 0.068s to run on the Anna.txt sample file. The memory mapped file IO took 0.015s, approximately 4.5x faster.

/proc is a filesystem in that it contains information about the system at the runtime of the process, but it does not store actual files.
/proc/$PID/cmdline
/proc/$PID/cpu
/proc/$PID/root
/proc/$PID/stat
/proc/$PID/environ
Yes, you can write to /proc/$PID/mem

Loadable Kernel Modules are used for device drivers, filesystem drivers, system calls, network drivers, executable interpreters, and other drivers. It is possible to implement Project 2 using LKM.


Sources:
http://tldp.org/LDP/Linux-Filesystem-Hierarchy/html/proc.html
https://lwn.net/Articles/433326/
http://tldp.org/HOWTO/Module-HOWTO/x73.html
