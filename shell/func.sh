#!/bin/bash

echo $res
# функция должна быть объявленна до её вывода
function f1() 
{
    local res=666
    echo $1
    echo $2
    echo $3
    echo "res $res"
    echo "Всего параметров $1 $2 $3"
}


f1 123 ыа "Эыав"

