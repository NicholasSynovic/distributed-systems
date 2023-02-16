#!/bin/bash

astyle --style=allman $1
g++ -std=c++17 $1 -o hw1.out
./hw1.out
