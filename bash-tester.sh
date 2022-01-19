#! /bin/bash
x=1
max=0
make
while [ $x -le 100 ]
do
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
	result=$(./push_swap $ARG | wc -l)
	if [ $result -gt $max ]
	then
		max=$result
	fi
	x=$(( $x + 1 ))
done
echo "max number: $max" > result.txt
