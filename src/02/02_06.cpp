#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long a; cin >> a;
    long LIM = sqrt(a)+2;
    for(int i = 2; i < LIM; ++i){
        if(a%i == 0){
            cout << false << endl;
            return 0;
        }
    }
    cout << true << endl;
    return 0;
}
