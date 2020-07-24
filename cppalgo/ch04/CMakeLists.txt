cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests Str.test.cpp ../algo/Str.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_executable(runHeapTests Heap.test.cpp ../algo//Number.cpp)
target_link_libraries(runHeapTests ${GTEST_LIBRARIES} pthread)

# add_executable(runBSTTests BST.test.cpp Number.cpp)
# target_link_libraries(runBSTTests ${GTEST_LIBRARIES} pthread)

add_executable(run main_heap.cpp ../algo/Number.cpp ../algo/Str.cpp ../algo/Profile.cpp)
