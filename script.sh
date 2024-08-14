#!/bin/bash

cc -o x-base-converter x_base_converter.c

if [ $? -eq 0 ]; then
    cp x-base-converter  ~/.local/bin #You can replace the bin directory for one that belongs to $PATH, case this doesn't
    cd ~/.local/bin
    chmod +x x-base-converter

    echo "Nice, compilation was succsessful  :))"
    echo "The x-base-converter must receive 2 arguments to work: the number to convert and the desired base"
    echo "Try to convert 3 to binary base"
    echo "Run: x-base-converter 3 01"

else
    echo "Compilation failed. Please try to fix any errors before running the program :("
fi
