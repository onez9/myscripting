#!/bin/bash 
function fuctorial() 
{ 
 local res=1 
 for i in $(seq 1 $1) 
 do 
    res=$(($res*$i)) 
 done 
 echo "Факториал числа $1 равен $res." 
} 
 
fuctorial 1 
fuctorial 2 
fuctorial 3 
fuctorial 4 
fuctorial 5 
