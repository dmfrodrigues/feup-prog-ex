#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long a){
    long LIM = sqrt(a)+2;
    for(int i = 2; i < LIM; ++i)
        if(a%i == 0)
            return false;
    return true;
}

int main(){
    long a; cin >> a;
    bool ans = isPrime(a);
    cout << ans << endl;
    return 0;
}
