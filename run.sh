#!/bin/bash
# Script to compile and run word search C program

if [ "$#" -lt "2" ]
then
	echo "Error! Not enough arguments passed! Check README for instructions on how to use program."
else
	gcc a2.c -o a2
	./a2 $@
fi
