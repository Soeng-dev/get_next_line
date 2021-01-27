#!/bin/bash
rm ./a.out
	gcc bonus_test.c ../get*_bonus.? -D BUFFER_SIZE=$1 
./a.out | cat -e
rm ./a.out
