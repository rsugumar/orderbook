Usage:
------
./orderBook <valid_input_filename>

Requirement:
------------
a) g++ 5.0 and above => Compiled and tested using C++14 std
b) google test framework => Unit testing purpose

Compilation:
------------
Compilation of source code:
    Step 0: cd OrderBook/
    Step 1: 'make clean' -> To clear any residual/old obj/bin files
    Step 2: 'make' -> Compiles the source code and links all obj to get the binary file 'orderBook'

Compilation of unit test code:
    Step 0.a: Compile the source code (refer above steps)
    Step 0.b: cd OrderBook/test/
    Step 2: 'make clean' -> To clear any residual/old obj/bin files
    Step 3: 'make' -> Compiles the test source code and links all obj to get the binary file 'testAll'

    NOTE: 'OrderBook/test/resources' directory contains the input files for unit/integration testing purpose