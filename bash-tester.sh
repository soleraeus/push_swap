#! /bin/bash
x=1
max=0
maxargs=0
min=10000
minargs=0
make
while [ $x -le 10000 ]
do
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
	result=$(./push_swap $ARG | wc -l)
	if [ $result -gt $max ]
	then
		max=$result
		maxargs=$ARG
	fi
	if [ $result -lt $min ]
	then
		min=$result
		minargs=$ARG
	fi
	x=$(( $x + 1 ))
done
echo "max number: $max"
echo "$maxargs" > maxargs2.txt
echo "min number: $min"
echo "$minargs" > minargs2.txt
