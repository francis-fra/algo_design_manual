#include <iostream>
#include <vector>
#include "sort.hpp"

using namespace std;

void test_case_01() {
    // vector<int> vec;
    vector<int> vec {5,3,2};
    // vec.add(5);
    // vec.add(15);

    // FIXME
    selection_sort(vec);
    print_container(vec);
}

int main(void) {
    test_case_01();
    // test_case_02();
}