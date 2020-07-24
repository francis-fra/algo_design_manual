#ifndef _NUMBER_H
#define _NUMBER_H

#include <iostream>
using namespace std;

namespace Algo {

    // Numerical class
    class Number {
        public:
            // constructor
            constexpr Number(float v=0.0): value{v} {};

            // copy constructor
            constexpr Number(const Number &F): value{F.get()} {};


            void set(float v) {
                value = v;
            };

            // accessor
            constexpr float get() const {
                return value;
            };

            void clear() {
                value = 0.0;
            };

            // access the private name 
            friend std::ostream& operator<<(std::ostream& os, const Number& N);

            // copy assignment
            Number& operator=(const Number& N) {
                value = N.get();
                return *this;
            };

            // same as get
            float operator()() {
                return this->get(); 
            };


        private:
            float value;

    }; // end Number

    bool operator==(const Number& N1, const Number& N2);
    bool operator>(const Number& N1, const Number& N2);
    bool operator<(const Number& N1, const Number& N2);
    bool operator>=(const Number& N1, const Number& N2); 
    bool operator<=(const Number& N1, const Number& N2);
    bool operator!=(const Number& N1, const Number& N2);
    Number operator+(const Number& N1, const Number& N2);


};


#endif