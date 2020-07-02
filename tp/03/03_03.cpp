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

ld mysqrt(ld n, ld delta, int maxIt){
    ld rq, rqn;
    rq = 1.0L;
    for(int i = 0; i < maxIt; ++i){
        rqn = (rq+n/rq)/2.0L;
        if(equal(rq, rqn, delta)) break;
        rq = rqn;
    }
    return rqn;
}

int main(){
    ld delta; cout << "delta:"; cin >> delta;
    int nMaxIter; cout << "nMaxIter:"; cin >> nMaxIter;
    ld n; cout << "n:"; cin >> n;
    ld myrqn = mysqrt(n, delta, nMaxIter);
    ld rqn   = sqrt(n);
    cout << setprecision(20);
    cout << "est.=" << myrqn     << endl;
    cout << "real=" << rqn       << endl;
    cout << "diff=" << rqn-myrqn << endl;
    return 0;
}
