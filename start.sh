#! /bin/bash

target_name=""

case "$1" in
    -t)
        target_name="tests"
        ;;
    -g)
        target_name="app"
        ;;
    *)
        echo "$0: use -t for tests and -g (gui) for graphic interface app"
        exit 1
        ;;
esac

if [[ -d build ]] 
then 
    rm -rf build
fi 

mkdir build
cd build
cmake ..
make

./$target_name
