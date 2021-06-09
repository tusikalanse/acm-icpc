#!/bin/bash
g++ my.cpp -o my
g++ std.cpp -o std
g++ data.cpp -o data
while true; do
    ./data > data.in
    ./std <data.in >std.out
    ./my <data.in >my.out
    if diff std.out my.out; then
        printf "AC\n"
    else
        cat data.in
        printf "Wa\n"
        exit 0
    fi
done
