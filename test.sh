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

#GCC FOR DRIVER, OURS FOR THE DEFAULT FILE
#THEN LINKEM
compiler_test="./compiler_tests"
working_dir="${compiler_test}/working_dir"
mkdir -p ${working_dir}

for test_type_dir in compiler_tests/*; do
    #testname=$(basename ${i} _test.txt)

    echo ${test_type_dir}
    for test in ${test_type_dir}/*; do
        testname_ext=$(basename ${test});
        testname=$(basename ${testname_ext} .c);
        #echo ${b}
        if [[ $testname == *"_driver" ]]; # * is used for pattern matching
        then #compile with gcc, then link, then compare
            echo "true"

            testname_no_driver=$(basename ${testname} _driver);
            #I then use GCC to assemble the generated assembly program (test_program.s), like so: puts our assembly into the working directory as an object
            mips-linux-gnu-gcc -mfp32 -o "${working_dir}/${testname_no_driver}.o" -c "${working_dir}/${testname_no_driver}.s" > /dev/null 2>&1

            #link
            mips-linux-gnu-gcc -mfp32 -static -o "${working_dir}/${testname_no_driver}" "${working_dir}/${testname_no_driver}.o" "${test_type_dir}/${testname_ext}" > /dev/null 2>&1

            #Tidy up the working directory
            #rm -rf "${working_dir}/*"

            qemu-mips "${working_dir}/${testname_no_driver}"
            # if [[ "$OK" -eq "0" ]]; then
            # PASSED=$(( ${PASSED}+1 ));
            # fi

            # CHECKED=$(( ${CHECKED}+1 ));
        else #compile with ours
            #echo "false"
            bin/c_compiler -S "${test_type_dir}/${testname_ext}" -o "${working_dir}/${testname}.s" > /dev/null 2>&1
        fi

        
        #mips-linux-gnu-gcc -mfp32 -o test_program.o -c test_program.s


    done
    # mkdir -p working/$b

    # PARAMS=$(head -n 1 $i/in.params.txt | ${DOS2UNIX} );

    # echo "==========================="
    # echo ""
    # echo "Input file : ${i}"
    # echo "Testing $b"


    # bin/c_compiler $i/in.code.txt \
    #     > working/$b/compiled.txt

    # bin/vm working/$b/compiled.txt ${PARAMS}  \
    #   < $i/in.input.txt \
    #   > working/$b/compiled.output.txt \
    #   2> working/$b/compiled.stderr.txt

    # GOT_RESULT=$?;

    # echo "${GOT_RESULT}" > working/$b/compiled.result.txt

    # OK=0;

    # REF_RESULT=$(head -n 1 $i/ref.result.txt | ${DOS2UNIX} );

    # if [[ "${GOT_RESULT}" -ne "${REF_RESULT}" ]]; then
    #     echo "  got result : ${GOT_RESULT}"
    #     echo "  ref result : ${REF_RESULT}"
    #     echo "  FAIL!";
    #     OK=1;
    # fi

    # GOT_OUTPUT=$(echo $(cat working/$b/compiled.output.txt | ${DOS2UNIX} ))
    # REF_OUTPUT=$(echo $(cat $i/ref.output.txt | ${DOS2UNIX} ))

    # if [[ "${GOT_OUTPUT}" != "${REF_OUTPUT}" ]]; then
    #     echo "  got output : ${GOT_OUTPUT}"
    #     echo "  ref output : ${REF_OUTPUT}"
    #     echo "  FAIL!";
    #     OK=1;
    # fi



    # echo ""
done
rm -rf "${working_dir}/*"
echo "########################################"
echo "Passed ${PASSED} out of ${CHECKED}".
echo ""















