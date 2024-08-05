#!/bin/sh
#
# https://ogiekako.vercel.app/blog/find_mkdir_tc
#

mkdir -p d/x
find d/x -regextype posix-extended -regex 'd(/x){0,29}' -execdir mkdir x/x \;
find d -regextype posix-extended \
    -regex 'd((/x){15})+' -printf "fizzbuzz\n" -o \
    -regex 'd((/x){5})+' -printf "buzz\n" -o \
    -regex 'd((/x){3})+' -printf "fizz\n" -o \
    -regex 'd(/x)+' -printf "%d\n"
rm -rf d
