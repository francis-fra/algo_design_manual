#ifndef _PROFILE_H
#define _PROFILE_H

#include <iostream>
#include "../algo/Number.hpp"
#include "../algo/Str.hpp"

using namespace std;

namespace Algo {

    // Numerical class
    class Profile {
        public:
            Profile(std::string name="", 
                    int age=-1, 
                    std::string adr="", 
                    int rank=0): _name{name}, _age{age}, _address{adr}, _rank{rank} {};


            // copy constructor
            Profile(const Profile& P):
                _age{P._age}, _rank{P._rank}, _address{P._address}, _name{P._name} {};


            // move constructor
            Profile(Profile&& P):
                _age{P._age}, _rank{P._rank}, _address{P._address}, _name{P._name} {};

            // copy assignment
            Profile& operator=(const Profile& P) {
                this->_age = P.age();
                this->_rank = P.rank();
                this->_address = P.address();
                this->_name = P.name();
                return *this;
            }

            // move assignment
            Profile& operator=(Profile&& P) {
                this->_age = P.age();
                this->_rank = P.rank();
                this->_address = P.address();
                this->_name = P.name();
                return *this;
            }

            Number age() const {
                return _age;
            }

            Number rank() const {
                return _rank;
            }

            Str address() const {
                return _address;
            }

            Str name() const {
                return _name;
            }


            friend std::ostream& operator<<(std::ostream& os, const Profile& P);

        private:
            Str _name;
            Number _age;
            Str _address;
            Number _rank;

    };


}; // Algo

#endif