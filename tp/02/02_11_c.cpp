#include <iostream>
#include <algorithm>
typedef long double ld;

using namespace std;

int main(){
    ld x; cin >> x;
    ld ans = 0.0L;
    ld fact = 1.0L;
    ld up = 1.0L;
    for(int i = 0; i < 100000; i+=2, fact *= ld(i-1)*ld(i), up *= x*x)
        ans += up/fact - up*x/(fact*ld(i+1));
    printf("e^(-x)=%.65Lf\n", ans);
    return 0;
}
