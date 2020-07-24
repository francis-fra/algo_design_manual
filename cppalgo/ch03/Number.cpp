/*
*   Fundamental Storage Object
*
*
*/ 
#include <iostream>
#include "Number.hpp"
using namespace std;

namespace Algo {


    std::ostream& operator<<(std::ostream& os, const Number& N) {
        os << N.get();
        return os;
    };


    // comparision
    bool operator==(const Number& N1, const Number& N2) {
        return N1.get() == N2.get();
    };
    bool operator>(const Number& N1, const Number& N2) {
        return N1.get() > N2.get();
    }
    bool operator<(const Number& N1, const Number& N2) {
        return N1.get() < N2.get();
    }
    bool operator>=(const Number& N1, const Number& N2) {
        return N1.get() >= N2.get();
    }
    bool operator<=(const Number& N1, const Number& N2) {
        return N1.get() <= N2.get();
    }
    bool operator!=(const Number& N1, const Number& N2) {
        return N1.get() != N2.get();
    }

    // arithmetic
    Number operator+(const Number& N1, const Number& N2) {
        return Number(N1.get() + N2.get());
    }
}