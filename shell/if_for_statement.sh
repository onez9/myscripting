#!/bin/bash


for file in *
do
    if [ -x "$file" ]; then
        echo "Этот файл исполняемый $file"
    fi
done
