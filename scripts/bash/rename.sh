#!/bin/sh
#--------------------------------------------------------------
# rename.sh
# Author: Rajeev Kumar Jeevagan
# Created on: 4 October 2012
# Last Modified: 4 October 2012
# Renames files in a given folder with a given name or the
# folder name with the suffix 00 which increments 
# plus .extension
# Usage : ./rename.sh [folder_name] [prefix_name (optional)]
#
#--------------------------------------------------------------
cnt=0
if [ $# -eq 2 ]; then
	newname=$2
elif [ $# -eq 1 ]; then
	if [ "$1" = "-h" ] || [ "$1" = "--help" ]; then #  || test "$1"=="--help"; then
		echo 
		echo "rename.sh"
		echo
		echo "./rename.sh [folder_name] [prefix_name]"
		echo "folder_name is the name of the folder you want to order"
		echo "prefix_name is the prefix you want to give to the file names"
		echo "prefix_name is optional and the default value is the folder name itself"
		echo
		exit 1
	else
		newname=${1%/*}
	fi
else
	echo "Specify folder name"
	exit 1
fi
for i in `ls $1`
do
d0=`expr $cnt % 10`
d1=`expr $cnt / 10 % 10`
d2=`expr $cnt / 100 % 10`
d3=`expr $cnt / 1000`
cnt=`expr $cnt + 1`
i=`echo $i | tr ' ' '\ '`
ext=${i#*.}
mv "${1%/*}/$i" "${1%/*}/$newname$d3$d2$d1$d0.$ext"
echo "${1%/*}/$i renamed to ${1%/*}/$newname$d3$d2$d1$d0.$ext"
done
