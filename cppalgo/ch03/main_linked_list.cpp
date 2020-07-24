#include "Number.hpp"
#include "Linked_List.hpp"

using namespace std;

template<class T>
Algo::LinkedNode<T> dblnode(Algo::LinkedNode<T>* N) {
    return Algo::LinkedNode<T>(N->item + N->item);
};


template<class T>
T dbl(const T& v) {
    return v + v;
};

using ITEM_TYPE = Algo::Number;

int main() {
    Algo::Number N1(8);
    Algo::Number N2(9);
    Algo::Number N3(18);
    bool eq = N1 == N2;
    // explicit conversion from 9 to Number
    bool gt = 9 > N1;
    // arithmetic
    N3 = N1 + N2;
    cout << "N1 + N2 = " << N3 << endl;

    // cout << 4 + N1() << endl;
    // cout <<  eq << endl;
    // cout <<  gt << endl;
    Algo::LinkedNode<ITEM_TYPE> LNode1(N1);
    Algo::LinkedNode<ITEM_TYPE> LNode2(N2);

    cout << "doubled N2 = " << dblnode(&LNode2).item << endl;


    Algo::LinkedList<ITEM_TYPE> link {N1, N2, N3};
    // Algo::LinkedList<ITEM_TYPE> link {4.5, 2.3, 7.8};
    // Algo::LinkedNode<Algo::Number>* last = link.last_parent();
    // Algo::LinkedNode<Algo::Number>* child = link.last_child();
    // Algo::LinkedNode<Algo::Number>* first = link.first();
    // cout << "first : " << first->item << endl;

    Algo::LinkedNode<ITEM_TYPE>* first = link.first();
    cout << "first : " << first->item << endl;
    Algo::LinkedNode<ITEM_TYPE>* child = link.last();
    cout << "last child: " << child->item << endl;

    Algo::LinkedList<ITEM_TYPE> link2 {link};
    cout << "link2: " << link2 << endl;

    link2.remove();
    cout << "removed link2: " << link2 << endl;

    Algo::Number N4(28);
    Algo::Number N5(48);

    link.insert(N4);
    link.insert(N5);
    cout << "Link: " << link << endl;

    link2 = link;
    cout << "After link2: " << link2 << endl;

    cout << "move construction" << endl;
    Algo::LinkedList<ITEM_TYPE> link3 = move(link);
    cout << "Link: " << link << endl;
    cout << "Link3 : " << link3 << endl;

    cout << "move operation" << endl;
    link2 = move(link3);
    cout << "Link2: " << link2 << endl;
    cout << "Link3 : " << link3 << endl;

    cout << "remove operation" << endl;
    link2.remove();
    link2.remove();
    cout << "Link2: " << link2 << endl;

    // for each
    link2.forEach(&dbl);
    cout << "Link2: " << link2 << endl;


    // Algo::LinkedList<ITEM_TYPE> link3;
    // Algo::LinkedNode<ITEM_TYPE>* parent= link.last_parent();
    // cout << "last parent: " << parent->item << endl;
}