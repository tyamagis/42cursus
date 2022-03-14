#! /bin/bash

echo -e "=========="
echo -e "push_swap 3 args"
echo -e "=========="
echo -e "\n"
echo -e "----------"
echo -e "./push_swap 0 1 2"
echo -e "----------"
read
./push_swap 0 1 2

echo -e "\n"
echo -e "----------"
echo -e "./push_swap 0 2 1"
echo -e "----------"
read
./push_swap 0 2 1

echo -e "\n"
echo -e "----------"
echo -e "./push_swap 1 0 2"
echo -e "----------"
read
./push_swap 1 0 2

echo -e "\n"
echo -e "----------"
echo -e "./push_swap 1 2 0"
echo -e "----------"
read
./push_swap 1 2 0

echo -e "\n"
echo -e "----------"
echo -e "./push_swap 2 0 1"
echo -e "----------"
read
./push_swap 2 0 1

echo -e "\n"
echo -e "----------"
echo -e "./push_swap 2 1 0"
echo -e "----------"
read
./push_swap 2 1 0

