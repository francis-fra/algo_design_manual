#ifndef _ACTOR_H 
#define _ACTOR_H

#include <iostream>
using namespace std;

namespace Algo {

    template<class T>
    class Actor {

        public:
            Actor<T>():
                f{[](T& x) -> void {}} {};

            void operator()(T& value) {
                return (*f)(value);
            };

            void set(void (*g) (T&)) {
               f = g; 
            };

        private:
            void (*f) (T& a);

    };
};


#endif