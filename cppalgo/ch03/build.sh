cmake -H. -Bbuild
cmake --build build
./build/runBSTTests
./build/run_reverse

./build/run
# ./build/runTests
# ./build/runLinkedNodeTests

cmake --build build; ./build/run
cmake --build build; ./build/runTests
cmake --build build; ./build/runBSTTests
cmake --build build; ./build/run_reverse

cmake --build build; ./build/runLinkedNodeTests
# g++ main.cpp Number.cpp