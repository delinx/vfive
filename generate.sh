rm -rf build
compiler="/bin/clang"
 
if [ "$1" == "DEBUG" ]; then
    echo -e "\nGenerating Debug build system:"
    cmake -DCMAKE_C_COMPILER=$compiler -B build/debug -G "Ninja" -DCMAKE_BUILD_TYPE=Debug .
    cp build/debug/compile_commands.json .
    cp leaks_blacklist build/debug
elif [ "$1" == "RELEASE" ]; then
    echo -e "\nGenerating Release build system:"
    cmake -DCMAKE_C_COMPILER=$compiler -B build/release -G "Ninja" -DCMAKE_BUILD_TYPE=Release .
    cp leaks_blacklist build/release
elif [ "$1" == "UNIT" ]; then
    echo -e "\nGenerating Unit Test build system:"
    cmake -DCMAKE_C_COMPILER=$compiler -DUNIT_TEST=true -B build/unit -G "Ninja" -DCMAKE_BUILD_TYPE=Debug .
    cp leaks_blacklist build/unit
elif [ "$1" == "ALL" ]; then
    echo -e "\nGenerating Unit Test build system:"
    cmake -DCMAKE_C_COMPILER=$compiler -DUNIT_TEST=true -B build/unit -G "Ninja" -DCMAKE_BUILD_TYPE=Debug .
    echo -e "\nGenerating Debug build system:"
    cmake -DCMAKE_C_COMPILER=$compiler -B build/debug -G "Ninja" -DCMAKE_BUILD_TYPE=Debug .
    echo -e "\nGenerating Release build system:"
    cmake -DCMAKE_C_COMPILER=$compiler -B build/release -G "Ninja" -DCMAKE_BUILD_TYPE=Release .
    cp leaks_blacklist build/debug
    cp leaks_blacklist build/release
    cp leaks_blacklist build/unit
    cp leaks_blacklist build/debug
else
  echo "Invalid argument. Please specify DEBUG, RELEASE, UNIT or ALL."
fi
