#! /bin/bash

x=500
while [ $x -gt 0 ]
do
	echo -n "$x " >> list.txt
	x=$(( $x - 1))
done
exit 0
