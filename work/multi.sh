#!/usr/bin/env bash


filelist="./fzd/short.lis"
while read -r filename
do
	echo "Running on $filename"
	echo ./run.sh 25 "${filename}" >& LOG
	./run.sh 25 "${filename}" >& LOG
	
	suffix=${filename:11}

	echo mv hijingana.root results_${suffix}.root
	mv hijingana.root results_${suffix}.root
	echo mv LOG "log_${suffix}.log"
	mv LOG "log_${suffix}.log"

done < "$filelist"