#ifndef _COMPARATOR_H 
#define _COMPARATOR_H

#include <iostream>
using namespace std;

namespace Algo {

    template<class T>
    class Comparator {
        public:
            Comparator<T>(bool ascending=true): 
                lt{[](const T& x, const T& y) { return x<y;}},
                gt{[](const T& x, const T& y) { return x>y;}}
            {
                if (ascending) 
                    cmp = lt;
                else
                    cmp = gt;
            };

        bool operator()(const T& N1, const T& N2) {
            return (*cmp)(N1, N2);
        }

        // TODO: static comparator?
        private:    
            bool (*gt) (const T& a, const T& b);
            bool (*lt) (const T& a, const T& b);
            bool (*cmp) (const T& a, const T& b);
    };

};


#endif