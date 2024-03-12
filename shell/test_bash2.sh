#!/bin/bash 
{ 
read a 
read b 
} < outfile.txt 
echo "Из файла считаны строки:" 
echo "1) $a" 
echo "2) $b" 
