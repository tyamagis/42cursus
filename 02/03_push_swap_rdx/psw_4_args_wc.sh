#! /bin/bash

./push_swap 1 2 3 4 | wc -l
./push_swap 1 2 4 3 | wc -l
./push_swap 1 3 2 4 | wc -l
./push_swap 1 3 4 2 | wc -l
./push_swap 1 4 2 3 | wc -l
./push_swap 1 4 3 2 | wc -l
./push_swap 2 1 3 4 | wc -l
./push_swap 2 1 4 3 | wc -l
./push_swap 2 3 1 4 | wc -l
./push_swap 2 3 4 1 | wc -l
./push_swap 2 4 1 3 | wc -l
./push_swap 2 4 3 1 | wc -l
./push_swap 3 1 2 4 | wc -l
./push_swap 3 1 4 2 | wc -l
./push_swap 3 2 1 4 | wc -l
./push_swap 3 2 4 1 | wc -l
./push_swap 3 4 1 2 | wc -l
./push_swap 3 4 2 1 | wc -l
./push_swap 4 1 2 3 | wc -l
./push_swap 4 1 3 2 | wc -l
./push_swap 4 2 1 3 | wc -l
./push_swap 4 2 3 1 | wc -l
./push_swap 4 3 1 2 | wc -l
./push_swap 4 3 2 1 | wc -l