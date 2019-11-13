#!/bin/bash

i=0
j=0
n=5
while (( $i < $n ))
do
	if(( $i%2 != 0 ))
	then
		j=0
		while (( $j < $n ))
		do
			if(( $j%2 == 0 ))
			then
				echo -n " "
			else
				echo -n "*"
			fi
		j=` expr $j + 1 `
		done
	echo " "
	else
		if(( $i == 0 || $i == 4 ))
		then
			echo  "  *  "
		elif(( $i == 2 ))
		then
			echo "* * *"
		fi
	fi
 i=` expr $i + 1 `
done
