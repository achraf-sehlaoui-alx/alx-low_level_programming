#!/bin/bash
gcc -fPIC -c *.c
gcc -shared *.c -o liball.so
