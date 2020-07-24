#include "Str.hpp"
#include <iostream>

namespace Algo {

    std::ostream& operator<<(std::ostream& os, const Str& S) {
        os << S.value;
        return os;
    }

    // comparators
    // no const??
    bool operator>(const Str& S1, const Str& S2) {
        return (S1.get()> S2.get());
    };

    bool operator<(const Str& S1, const Str& S2) {
        return (S1.get()< S2.get());
    };

    bool operator==(const Str& S1, const Str& S2) {
        return (S1.get()== S2.get());
    };

    bool operator!=(const Str& S1, const Str& S2) {
        return (S1.get()!= S2.get());
    };
}