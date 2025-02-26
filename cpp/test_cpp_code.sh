#!/bin/bash

g++ -std=c++20 cses.cpp -o code_file

# $? - stores the status of last executed command, -ne is not equal
if [ $? -ne 0 ]; then 
    echo "compliation failed, check your code!"
    exit 1
fi

# path to test folder
test_folder="/Users/lokeshwar777/Downloads/tests"

all_tests_passed=true

# Loop through all the input files
for input_file in "$test_folder"/*.in; do
    # get the test number from file name
    test_number=$(basename "$input_file" .in)
    
    # Generate the output file name
    expected_output="${test_folder}/${test_number}.out"
    
    # timeout for linux and gtimeout for macOS
    timeout 1s ./code_file < "$input_file" > logs.txt

    exit_code=${PIPESTATUS[0]}

    # TL check
    if [ $exit_code -eq 124 ] || [ $exit_code -eq 137 ]; then
        echo -e "\n==================================================================\n"
        echo -e "Test $test_number FAILED \033[38;2;255;0;0m (TLE) \033[0m"
        all_tests_passed=false
        continue    
    fi

    # memory check
    if [ $exit_code -eq 139 ] || [ $exit_code -eq 11 ]; then
        echo -e "\n==================================================================\n"
        echo -e "Test $test_number FAILED \033[38;2;255;0;0m (MLE) \033[0m"
        all_tests_passed=false
        continue
    fi  
    
    if ! diff -u logs.txt "$expected_output" > /dev/null; then
        echo -e "\n==================================================================\n"
        echo -e "Test $test_number FAILED \033[1;31m (WA) \033[0m"
        echo -e "\n Your Output : \033[38;2;255;0;0m $(cat logs.txt) \033[0m"
        echo -e "\n Expected Output : \033[1;32m$(cat "$expected_output") \033[0m"
        all_tests_passed=false
    fi
done

if $all_tests_passed; then
    # use '\033' or '\x1b', [1;32m-start, [0m-reset formatting, 1-bold, 33-greed
    echo -e "\n\033[1;32m✅ All tests PASSED. You can submit your code now.\033[0m"
fi

# clean up and delet the temp output file
rm logs.txt 

