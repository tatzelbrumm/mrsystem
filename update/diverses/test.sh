#!/bin/sh

INDEX=1
while [ "$INDEX" != "10" ] ; do
	echo $INDEX
	sleep 1
	INDEX=`expr $INDEX + 1`
done
