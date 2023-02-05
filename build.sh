#!/bin/bash

#Program: grandChild_ fork
#Author: Joseph Eggers

#Purpose: script file to run the program files together.
#Clear any previously compiled outputs
rm *.o
rm *.lis
rm *.out

echo "compile driver.cpp using the g++ compiler standard 2017"
gcc -c -Wall -m64 -no-pie -o grandchild.o grand_child.c -std=c11

echo "Link object files using the gcc Linker standard 2017"
gcc -m64 -no-pie -o final.out grandchild.o -std=c11

echo "Run the Float Comparator Program:"
./final.out

rm *.o
rm *.lis
rm *.out