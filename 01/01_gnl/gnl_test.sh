#!/bin/bash

echo
echo ======================
echo GNL_tester by tyamagis
echo ======================
echo 

files=('./get_next_line.c' './get_next_line_utils.c' './get_next_line.h' './gnl_main.c')
bfiles=('get_next_line_bonus.c' 'get_next_line_utils_bonus.c' 'get_next_line_bonus.h' 'gnl_main_bonus.c')
flag='-Werror -Wextra -Wall -g -fsanitize=address'

f=('./txts/41_no_nl' './txts/41_with_nl' './txts/42_no_nl' './txts/42_with_nl' './txts/43_no_nl' './txts/43_with_nl' './txts/alternate_line_nl_no_nl' './txts/alternate_line_nl_with_nl' './txts/big_line_no_nl' './txts/big_line_with_nl' './txts/empty' './txts/multiple_line_no_nl' './txts/multiple_line_with_nl' './txts/multiple_nlx5' './txts/nl')

echo =================
echo test 1 /
echo compile with BUFFER_SIZE = 0
echo =================
echo 
read

make b0

echo cat ${f[1]}
read
echo ------------------
cat ${f[1]}
echo ------------------
read
echo ./a.out ${f[1]}
echo ------------------
./a.out ${f[1]}
echo ------------------

read

echo =================
echo test 2 /
echo compile with BUFFER_SIZE = 1
echo =================
echo 
read

make b1

for i in {0..13}
do
echo
echo === $i / 14 ===
echo
echo cat ${f[i]}
read
echo ------------------
cat ${f[i]}
echo ------------------
read
echo ./a.out ${f[i]}
read
echo ------------------
./a.out ${f[i]}
echo ------------------
read
done

echo =================
echo test 3 /
echo compile with BUFFER_SIZE = 42
echo =================
echo 
read

make b2

for i in {0..13}
do
echo
echo === $i / 14 ===
echo
echo cat ${f[i]}
read
echo ------------------
cat ${f[i]}
echo ------------------
read
echo ./a.out ${f[i]}
read
echo ------------------
./a.out ${f[i]}
echo ------------------
read
done

echo =================
echo test 4 /
echo compile with BUFFER_SIZE = 1024
echo =================
echo 
read

make b3

for i in {0..13}
do
echo
echo === $i / 14 ===
echo
echo cat ${f[i]}
read
echo ------------------
cat ${f[i]}
echo ------------------
read
echo ./a.out ${f[i]}
read
echo ------------------
./a.out ${f[i]}
echo ------------------
read
done

