#! /bin/bash

# NO Argument
./push_swap

# duplicate
./push_swap 1 2 3 4 5 1

# non-INT INT_MAX + 1
./push_swap 2147483648

# non-INT INT_MIN - 1
./push_swap -2147483649

# non-Int string
./push_swap 1 3 5 7 42 ft

./push_swap 1 10 100 1000 10000 100000 1000000 10000000
