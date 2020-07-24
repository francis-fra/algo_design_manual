#include "Number.hpp"
#include "BST.hpp"
#include <type_traits>
#include <typeinfo>
#include <string>

using namespace std;
using namespace Algo;

// template<class T>
// Algo::LinkedNode<T> dblnode(Algo::LinkedNode<T>* N) {
//     return Algo::LinkedNode<T>(N->item + N->item);
// };
// template <typename T> std::string type_name();

template<class T>
T dbl(const T& v) {
    return v + v;
};

using ITEM_TYPE = Algo::Number;

int main() {
    Algo::Number N1(8);
    Algo::Number N2(9);
    Algo::Number N3(18);

    BSTNode<ITEM_TYPE> B{N1};

    // comparator
    auto lt = [](Number x, Number y) { return x<y;};
    auto gt = [](Number x, Number y) { return x>y;};

    cout << "N1 is less than N2: " << lt(N1, N2) << endl;
    cout << "N1 is greater than N2: " << gt(N1, N2) << endl;


    bool (*pF) (Number a, Number b) = lt;
    cout << "N1 is greater than N2: " << (*pF)(N1, N2) << endl;

    NumFunctor F;
    cout << "N1 is greater than N2: " << F(N1, N2) << endl;
    F.set_descending();
    cout << "N1 is greater than N2: " << F(N1, N2) << endl;
    // cout << typeid(lt).name() << endl;
    // cout << type_name<decltype(lt)>() << endl;
};