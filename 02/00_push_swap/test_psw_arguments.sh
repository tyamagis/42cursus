#! /bin/bash

echo -e "\n ==========\n  NG tests\n ==========\n"

# NO Argument
echo -e "\n"
echo -e "----------"
echo -e "./push_swap"
echo -e "----------"
read
./push_swap

# duplicate
echo -e "\n"
echo -e "----------"
echo -e "./push_swap 1 2 3 4 5 1"
echo -e "----------"
read
./push_swap 1 2 3 4 5 1

# non-INT INT_MAX + 1
echo -e "\n"
echo -e "----------"
echo -e "./push_swap 2147483648"
echo -e "----------"
read
./push_swap 2147483648

# non-INT INT_MIN - 1
echo -e "\n"
echo -e "----------"
echo -e "./push_swap -2147483649"
echo -e "----------"
read
./push_swap -2147483649

# non-INT INT_MAX * 2 + N
echo -e "\n"
echo -e "----------"
echo -e "./push_swap 4294967296"
echo -e "----------"
read
./push_swap 4294967296

# non-INT INT_MIN * 2 - N
echo -e "\n"
echo -e "----------"
echo -e "./push_swap -4294967298"
echo -e "----------"
read
./push_swap 4294967296

# non-Int string
echo -e "\n"
echo -e "----------"
echo -e "./push_swap 1 3 5 7 42 ft"
echo -e "----------"
read
./push_swap 1 3 5 7 42 ft


echo -e "\n ==========\n  OK tests\n ==========\n"
# OK
echo -e "\n"
echo -e "----------"
echo -e "./push_swap 1 10 100 1000 10000 100000 1000000 10000000"
echo -e "----------"
read
./push_swap 1 10 100 1000 10000 100000 1000000 10000000

echo -e "\n"
echo -e "----------"
echo -e "./push_swap -2147483648 2147483647 99999 -99999 0"
echo -e "----------"
read
./push_swap -2147483648 2147483647 99999 -99999 0
