#!/bin/sh
# file : fit-gyro.sh
# author : Inubushi Takayuki (2014)
# brief : gyroの零点、標準偏差を計算する

mode=0  #0 = all, 1 = one file
name=""
plot="fit-gyro.gpi"

if [ $# != 1 ]; then
    echo "Command num error!"
    exit
fi

if [ $1 = "all" ]; then
    mode=0
else
    mode=1
    name=$1
fi

if [ $mode = 0 ]; then
    for INP in *.log
    do
        newname=`basename $INP .log`
        #9minまでのデータは温度収束しておらずよろしくないので消す
        sed -e "/^CAN Recieve timeout /d" $INP > _tmp.log
        grep "^5[456789][0123456789][0123456789][0123456789]" _tmp.log > _tmp2.log 
        /usr/bin/gnuplot ${plot}
        ## post-filename-modification
        mv _tmp.png $newname.png
        mv _tmp2.png ${newname}_fit.png
        mv _tmp2.log ${newname}_last.txt
        echo "$INP completed"
    done
else
    INP=$name
    newname=`basename $INP .log`
    #9minまでのデータは温度収束しておらずよろしくないので消す
    sed -e "/^CAN Recieve timeout /d" $INP > _tmp.log
    grep "^6[012345][0123456789][0123456789][0123456789]" _tmp.log > _tmp2.log 
    /usr/bin/gnuplot ${plot}
    ## post-filename-modification
    mv _tmp.png $newname.png
    mv _tmp2.png ${newname}_fit.png
    mv _tmp2.log ${newname}_last.txt
    echo "$INP completed"
fi

rm _tmp*

