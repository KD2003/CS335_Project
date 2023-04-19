#!/bin/bash

for i in `seq 1 10`; 
do 
    echo test_$i
    ./milestone4 --input ../tests/test_$i.java;
done