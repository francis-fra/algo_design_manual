cmake -H. -Bbuild
cmake --build build
./build/runHeapTests

./build/run
./build/runTests
# ./build/runLinkedNodeTests

cmake --build build; ./build/run
cmake --build build; ./build/runHeapTests

# g++ main.cpp Number.cpp