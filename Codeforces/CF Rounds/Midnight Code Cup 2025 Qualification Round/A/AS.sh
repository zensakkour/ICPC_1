#!/bin/bash

# 1) Compile the solution.
g++ -std=c++17 -O2 -o solution A.cpp

# Check if compilation succeeded
if [ $? -ne 0 ]; then
    echo "Compilation failed. Exiting."
    exit 1
fi

# 2) For each test from 1 to 12 (zero-padded),
#    run the program on inputsA/<test>.in --> <test>.out
for i in $(seq -w 1 12); do
    
    in_file="inputsA/${i}"
    out_file="${i}.out"
    
    # Check if the input file exists
    if [ ! -f "${in_file}" ]; then
        echo "Input file ${in_file} not found. Skipping."
        continue
    fi
    
    echo "Running on input ${in_file} ..."
    ./solution < "${in_file}" > "${out_file}"
done

# 3) Zip all .out files into submission.zip
echo "Creating submission.zip..."
zip -r submission.zip *.out

echo "All done. Created submission.zip with the .out files."
