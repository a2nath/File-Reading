#!/bin/sh

INPUT="input.txt"

if [ "$1" -ge "-1" ]; then
	./benchmark_io $INPUT
else 
	echo "Add the input file parameter or place the input.txt file in the current directory"
fi


