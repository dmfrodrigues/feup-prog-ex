#include <iostream>
#include <iomanip>
#include <cmath>
typedef long double ld;

using namespace std;

bool equal(ld n1, ld n2, ld delta){
    ld diff = n2-n1;
    if(diff < 0) diff = -diff;
    return (diff < delta);
}

int main(){
    ld delta; cout << "delta:"; cin >> delta;
    int nMaxIter; cout << "nMaxIter:"; cin >> nMaxIter;
    ld n; cout << "n:"; cin >> n;

    ld rq, rqn;
    rq = 1.0L;
    for(int i = 0; i < nMaxIter; ++i){
        rqn = (rq+n/rq)/2.0L;
        if(equal(rq, rqn, delta)) break;
        rq = rqn;
    }
    int prec = -abs(floor(log10(delta)));
    cout << "sqrt_(" << n << ")=" << setprecision(prec) << rqn << endl;
    cout << "sqrt (" << n << ")=" << setprecision(prec) << sqrt(n) << endl;

    return 0;
}
