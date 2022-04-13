#! /bin/bash

for ((i=0; i<501; i++))
do
	./a.out $i > args/$i.txt
done