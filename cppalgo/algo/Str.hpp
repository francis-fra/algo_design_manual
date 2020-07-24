#ifndef _STR_H
#define _STR_H

#include <iostream>
#include <string>
using namespace std;

namespace Algo {

    // Numerical class
    class Str {
        public:
            // default constructor
            Str(std::string s=""): value{s} {};

            // Str(char* c): value{c} {};
            
            // copy constructor
            Str(const Str& S): value{S.value} {};

            // move constructor - no difference from copy
            Str(Str&& S): value{S.value} {};

            // copy assginment
            Str& operator=(const Str& S) {
                value = S.value;
                return *this;
            };

            // move assginment - no difference from copy
            Str& operator=(Str&& S) {
                value = S.value;
                return *this;
            };

            // accessor - make sure there is a const!!
            std::string get() const {
                return value;
            };

            void set(const std::string& s) {
                value = s;
            };


            friend std::ostream& operator<<(std::ostream& os, const Str& S);
            // friend bool operator>(const Str& S1, const Str& S2);
            // friend bool operator==(const Str& S1, const Str& S2);
            // friend bool operator<(const Str& S1, const Str& S2);
            // friend bool operator!=(const Str& S1, const Str& S2);


        private:
            std::string value;

    }; // end class

    bool operator>(const Str& S1, const Str& S2);
    bool operator==(const Str& S1, const Str& S2);
    bool operator<(const Str& S1, const Str& S2);
    bool operator!=(const Str& S1, const Str& S2);

}  // end  Algo

#endif