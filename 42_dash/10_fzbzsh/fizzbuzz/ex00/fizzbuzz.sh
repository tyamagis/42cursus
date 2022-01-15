#!/bin/bash
for ((i=1;i<=$1;i++))
do
	if (( $i%15 ));then echo fizzbuzz
	elif (( $i%5 ));then echo buzz
	elif (( $i%3 ));then echo fizz
 else
  echo $i
 fi
done

# SHELL SCRIPT ZENZEN WAKARAN
