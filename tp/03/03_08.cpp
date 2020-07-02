#include <iostream>

using namespace std;

int gcd(int a, int b){
    return (b? gcd(b, a%b) : a);
}

int main(){
    int a, b;
    while(true){
        cin >> a >> b;
        cout << "gcd(" << a << ", " << b << ")=" << gcd(a,b) << endl;
    }
}
