#!/bin/bash
while true; do
    make vmlinux 2>&1 |grep "No rule to make target 'arch/x86/"
    if [ $? -eq 0 ]
    then
        file=`make vmlinux 2>&1 |awk "/No rule to make target 'arch\/x86\//{print $1}" |cut -d"'" -f2`
        prefix=`echo $file |cut -d"." -f1`
        suffix=`echo $file |cut -d"." -f2`
        if [ "$suffix" = "o" ]; then
            src="../linux-2.6.39.4/${prefix}.c"
            new="${prefix}.c"
            if [ ! -e $src ]; then
                src="../linux-2.6.39.4/${prefix}.S"
                new="${prefix}.S"
                if [ ! -e $src ]; then
                    exit 1
                fi
            fi
            touch $new
        else
            exit 1
        fi
    else
        exit 1
    fi
done
