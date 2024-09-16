#!/bin/bash
if cmake -S source/ -B build/ ; then
    cd build
    if make ; then
        while getopts ":e" option ; do
            case $option in
                e)launch="build/bin/RAP"
            esac
        done
    fi

    cd ..
    $launch
else
    echo "Build failed"
fi
