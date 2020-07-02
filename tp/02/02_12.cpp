#include <iostream>
#include <algorithm>
typedef long double ld;

using namespace std;

int main(){
    ld x; cin >> x;
    ld diff; cin >> diff;
    ld ans = 5.0L;
    ld fact = 1.0L;
    ld up = 1.0L;

    ld prev;
    long i = 0;
    do{
        prev = ans;
        ans += up/fact - up*x/(fact*ld(i+1));
        cout << ans << " " << prev << endl;
        i+=2;
        fact *= ld(i-1)*ld(i);
        up *= x*x;
    }while(ans-prev > diff);
    printf("e^(-x)=%.65Lf\n", ans);
    return 0;
}
