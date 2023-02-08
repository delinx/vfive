c#!/bin/bash

# This script is used to run an executable with a specified mode.
# Usage: ./run.sh ./<executable_name> <mode>
# <executable_name> is the name of your program
# <mode> can be either RELEASE, DEBUG, or UNIT

if [ -z "$1" ]; then
  echo "Error: No executable name provided."
  exit 1
fi

if [ "$2" == "RELEASE" ]; then
    cd build/release
    clear
    echo "Running in RELEASE mode."
    ninja && LSAN_OPTIONS=suppressions=leaks_blacklist $1
elif [ "$2" == "DEBUG" ]; then
    cd build/debug
    clear
    echo "Running in DEBUG mode."
    ninja && LSAN_OPTIONS=suppressions=leaks_blacklist $1
elif [ "$2" == "UNIT" ]; then
    cd build/unit
    clear
    echo "Running in UNIT test mode."
    ninja && LSAN_OPTIONS=suppressions=leaks_blacklist $1
else
  echo "Invalid argument: $2"
fi
