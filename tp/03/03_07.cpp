#include <iostream>

using namespace std;

int factorial_ite(int n){
    if(n <= 1) return 1;
    return n*factorial_ite(n-1);
}

int factorial_rec(int n){
    int ret = 1;
    for(int i = 2; i <= n; ++i)
        ret *= i;
    return ret;
}

int main(){
    for(int i = 0; i <= 10; ++i){
        cout << i << "! = " << factorial_ite(i) << " = " << factorial_rec(i) << endl;
    }
    return 0;
}
