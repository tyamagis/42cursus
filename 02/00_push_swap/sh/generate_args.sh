#! /bin/bash

for ((i=1; i<100; i++))
do
	ARG=$(ruby -e "puts (0..199).to_a.shuffle.join(' ')")
	echo $ARG >> test_psw_200_args.sh
done

for ((i=1; i<100; i++))
do
	ARG=$(ruby -e "puts (0..299).to_a.shuffle.join(' ')")
	echo $ARG >> test_psw_300_args.sh
done

for ((i=1; i<100; i++))
do
	ARG=$(ruby -e "puts (0..399).to_a.shuffle.join(' ')")
	echo $ARG >> test_psw_400_args.sh
done

for ((i=1; i<100; i++))
do
	ARG=$(ruby -e "puts (0..499).to_a.shuffle.join(' ')")
	echo $ARG >> test_psw_500_args.sh
done