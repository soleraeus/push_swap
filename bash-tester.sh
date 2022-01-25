#! /bin/bash
tot=10
x=1
max=0
maxargs=0
moy=0
make
while [ $x -le $tot ]
do
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
	result=$(./push_swap $ARG | wc -l)
	valid=$(./push_swap $ARG | ./checker_Mac $ARG)
	moy=$(( $moy + $result ))
	if [ $result -gt $max ]
	then
		max=$result
		maxargs=$ARG
	fi
	if [ $valid != 'OK' ]
	then
		echo "ERROR, RESULT IS INVALID"
		break
	fi
	x=$(( $x + 1 ))
done
moy=$(( $moy / $tot ))
echo "moyenne: $moy" >> maxargsnew.txt
echo "max number: $max" >> maxargsnew.txt
echo "$maxargs" >> maxargsnew.txt
