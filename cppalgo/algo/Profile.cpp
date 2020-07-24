#include "Profile.hpp"
#include <iostream>

namespace Algo {

    std::ostream& operator<<(std::ostream& os, const Profile& P) {
        os << "/******** Profile **(****/" << std::endl;
        os << "name: " << P.name() << std::endl;
        os << "age: " << P.age() << std::endl;
        os << "address : " << P.address() << std::endl;
        os << "rank: " << P.rank() << std::endl;
        os << "/***********************/" << std::endl;
        return os;
    }

    // TODO: comparators


};