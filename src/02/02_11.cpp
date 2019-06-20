#include <iostream>
#include <algorithm>
typedef long double ld;

using namespace std;

int main(){
    ld pi = 0;
    for(int i = 1; i < 10000000; i += 4)
        pi += 4.0L/ld(i)-4.0/ld(i+2);
    printf("pi=%.65Lf\n", pi);
    ld fact = 1.0L;
    ld e = 0.0L;
    for(int i = 0; i < 1000000; ++i, fact *= ld(i))
        e += 1.0L/fact;
    printf("e =%.65Lf\n", e);
    return 0;
}
