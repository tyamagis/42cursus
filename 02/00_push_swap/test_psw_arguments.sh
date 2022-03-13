#! /bin/bash

# NO Argument
echo -e "\n./push_swap"
read
./push_swap

# duplicate
echo -e "\n./push_swap 1 2 3 4 5 1"
read
./push_swap 1 2 3 4 5 1

# non-INT INT_MAX + 1
echo -e "\n./push_swap 2147483648"
read
./push_swap 2147483648

# non-INT INT_MIN - 1
echo -e "\n./push_swap -2147483649"
read
./push_swap -2147483649

# non-Int string
echo -e "\n./push_swap 1 3 5 7 42 ft"
read
./push_swap 1 3 5 7 42 ft

# OK
echo -e "\n./push_swap 1 10 100 1000 10000 100000 1000000 10000000"
read
./push_swap 1 10 100 1000 10000 100000 1000000 10000000

echo -e "\n./push_swap -2147483648 2147483647 99999 -99999 0"
read
./push_swap -2147483648 2147483647 99999 -99999 0
