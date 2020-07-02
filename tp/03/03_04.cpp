#include <iostream>
#include <cmath>

using namespace std;

double round(double x, unsigned n){
    double tens = pow(10, n);
    return floor(x*tens + 0.5)/tens;
}

int main(){
    double x; unsigned n;
    while(true){
        cin >> x >> n;
        cout << round(x,n) << endl;
    }
    return 0;
}
