#! /bin/bash

################### Variables to modify ###################
nbiterations=2500
nbmaxmoves=700
listsize=100
checker="checker_Mac"
erroutfile="errout.txt"
overlimitfile="overlimit.txt"
resultsfile="maxargs.txt"
tempfile="temp.txt"
############### End of variables to modify ###############

x=1
max=0
maxargs=0
moy=0
make
echo -e "Starting tests\n"
while [ $x -le $nbiterations ]
do
	echo -e "\033[1A\r\033[0K\033[1;37m$x / $nbiterations, current max: $max"
	ARG=`ruby -e "puts (1..$listsize).to_a.shuffle.join(' ')"`
	echo "$(./push_swap $ARG)" > $tempfile
	valid=$(cat $tempfile | ./$checker $ARG)
	result=$(cat $tempfile | wc -l | grep -oe "[0-9]\+")
	moy=$(( $moy + $result ))
	if [ $result -gt $max ]
	then
		max=$result
		maxargs=$ARG
	fi
	if [ $valid != 'OK' ]
	then
		echo -e "\033[1;31mERROR, RESULT IS INVALID, SEE $erroutfile FOR ARGS"
		echo "ERROR ON:" >> $erroutfile
		echo "$ARG" >> $erroutfile
		rm -rf $tempfile
		exit 1
	fi
	if [ $result -gt $nbmaxmoves ]
	then
		echo -e "\033[1A\r\033[0K\033[1;31mWarning, over $nbmaxmoves, found $result moves. See $overlimitfile for args.\n"
		echo "Number of moves: $result" >> $overlimitfile
		echo "$ARG" >> $overlimitfile
	fi
	x=$(( $x + 1 ))
done
rm -rf $tempfile
moy=$(( $moy / $nbiterations ))
echo "Max number of moves: $max" >> $resultsfile
echo "$maxargs" >> $resultsfile
echo -e "\033[1;37mFinished tests, number of tests: $nbiterations, average number of moves: $moy, max number of moves: $max, for list of size $listsize. See $resultsfile for args of max number of moves found."
exit 0
