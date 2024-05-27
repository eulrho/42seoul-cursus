#!/bin/sh

file_name=infile
s1=a
s2=aaaa

make all
./ex04 $file_name $s1 $s2

diff $file_name $file_name.replace

make fclean
rm $file_name.replace