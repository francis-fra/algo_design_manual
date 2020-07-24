#include "../algo/Number.hpp"
#include "../algo/Str.hpp"
#include "../algo/Profile.hpp"
#include <iostream>

using namespace std;
using namespace Algo;


using ITEM_TYPE = Algo::Number;

int main() {
    Algo::Number N1(8);
    Algo::Str S1("nestor");
    Algo::Str S2("sheryl");
    Algo::Str S(S2);

    S1.set("hello");

    cout << N1 << endl;
    cout << S1 << endl;
    cout << S2 << endl;
    cout << S << endl;

    cout << (S1 > S2) << endl;
    cout << (S1 == S1) << endl;
    cout << (S1 < S2) << endl;
    cout << (S1 != S1) << endl;


    Algo::Profile P1(S1.get(), 10, "chatswood", 2);
    Algo::Profile P2(S2.get(), 10, "chatswood", 1);

    cout << P1 << endl;
}