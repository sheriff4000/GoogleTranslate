#!/bin/bash

# Try to find a portable way of getting rid of
# any stray carriage returns
if which dos2unix ; then
    DOS2UNIX="dos2unix"
elif which fromdos ; then
    DOS2UNIX="fromdos"
else
    >&2 echo "warning: dos2unix is not installed."
    # This should work on Linux and MacOS, it matches all the carriage returns with sed and removes
    # them.  `tr` is used instead of `sed` because some versions of `sed` don't recognize the
    # carriage return symbol.  Something similar could be implemented with `sed` if necessary or
    # worst case it could be disabled by substituting it with `cat`.  One other thing to note is
    # that there are no quotes around the \r, which is so that it gets converted by bash.
    DOS2UNIX="tr -d \r"
    # DOS2UNIX="sed -e s/\r//g"
    # DOS2UNIX="cat"
fi
echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean


echo "========================================"
echo " Force building compiler"
make bin/c_compiler &> /dev/null
if [[ "$?" -ne "0" ]]; then #if return code not equal to 0
    echo "Error while building compiler."
    exit 1;
fi

echo "========================================="

PASSED=0
CHECKED=0
chosen_test=$1
#GCC FOR DRIVER, OURS FOR THE DEFAULT FILE
#THEN LINKEM
compiler_test="./compiler_tests"
working_dir="${compiler_test}/working_dir"
mkdir -p ${working_dir}

for test_type_dir in compiler_tests/*; do
    #testname=$(basename ${i} _test.txt)

    #echo ${test_type_dir}
    for test in ${test_type_dir}/*; do


        testname_ext=$(basename ${test});
        testname=$(basename ${testname_ext} .c);
        
        
        #echo "${chosen_test}_driver"

        if [ "${testname}" == "${chosen_test}" ] || [ "${testname}" == "${chosen_test}_driver" ] || [ "${chosen_test}" == "all" ]
        then
            #echo "Stages" 
            true
        else
            continue
            
        fi

        if [[ $testname == *"_driver" ]];
        then #compile with gcc, then link, then compare

            testname_no_driver=$(basename ${testname} _driver);
            #I then use GCC to assemble the generated assembly program (test_program.s), like so: puts our assembly into the working directory as an object
            mips-linux-gnu-gcc -mfp32 -o "${working_dir}/${testname_no_driver}.o" -c "${working_dir}/${testname_no_driver}.s" &> /dev/null

            #link
            #echo "Linking"
            mips-linux-gnu-gcc -mfp32 -static -o "${working_dir}/${testname_no_driver}" "${working_dir}/${testname_no_driver}.o" "${test_type_dir}/${testname_ext}" &> /dev/null

            #Tidy up the working directory
            #rm -rf "${working_dir}/*"

            qemu-mips "${working_dir}/${testname_no_driver}" &> /dev/null
            if [[ $? -eq "0" ]]; then
            PASSED=$(( ${PASSED}+1 ));
            echo ${testname_no_driver}
            fi

            CHECKED=$(( ${CHECKED}+1 ));

        else #compile with ours
            #echo "false"
            bin/c_compiler -S "${test_type_dir}/${testname_ext}" -o "${working_dir}/${testname}.s" &> /dev/null
        fi

        



    done
done
make clean
rm -rf "${working_dir}/*"
echo "########################################"
echo "Passed ${PASSED} out of ${CHECKED}".
echo ""















