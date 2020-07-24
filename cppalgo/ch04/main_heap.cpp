#include "../algo/Number.hpp"
#include "../algo/Str.hpp"
#include "Heap.hpp"
#include "../algo/Comparator.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace Algo;

using ITEM_TYPE = Algo::Number;

int main() {
    Algo::Number N1(8);
    // Algo::Str S1("nestor");
    // Algo::Str S2("sheryl");
    // Algo::Str S(S2);


    Algo::Heap<ITEM_TYPE> H(5);
    H.insert(1492);
    H.insert(1776);
    H.insert(1941);
    H.insert(1783);
    H.insert(1865);
    H.show();

    // H.test_swap(1, 0);
    // H.show();

    Algo::Heap<ITEM_TYPE> Hp{1492, 1776, 1941, 1783, 1865, 1600};
    Hp.show();

    Algo::Number item = Hp.extract_root();
    cout << "item = " << item << endl;
    Hp.show();

    // copy constructor
    // Algo::Heap<ITEM_TYPE> Hclone{Hp};
    // Hclone.show();

    Algo::Heap<ITEM_TYPE> Hr(5, false);
    Hr.insert(1492);
    Hr.insert(1776);
    Hr.insert(1941);
    Hr.insert(1783);
    Hr.insert(1865);
    Hr.show();

    // sorting
    vector<ITEM_TYPE> v {1492, 1776, 1941, 1865};
    Algo::heapsort(v);
    for (auto item: v) {
        cout << item << ", ";
    }
    cout << endl;
}