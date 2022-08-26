// #include <cstdio>
#include <stdlib.h>
#include <iostream>
using namespace std;


auto sq = [](auto x) { return x*x;} ;
auto dev_sq = [](auto x) { return 2*x; } ;

// find f(x) = y
float find_root(float (*f) (float), float y, float step=1e-2, float tolerance=1e-3) {
    // trap at global local
    // float x = 0.0;
    float x = 1.0;
    float error = f(x) - y;
    int counter = 0;
    while ( abs(error) > tolerance) {
        counter++;
        x = x - step * error * dev_sq(x);
        // debug print
        printf("%d: x=%7.3f, error:%7.3f \n", counter, x, error);
        error = f(x) - y;
    }
    return x;
}


int main() {

    float answer = find_root(sq, 2.0);
    cout << answer << endl;
    return 0;
}