#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    double a; cin >> a;
    if(a < 500.0){
        cout << 5.0 << endl;
    }else if(a < 1000.0){
        cout << 5.0+(a-500.0)*1.5/100.0 << endl;
    }else{
        cout << 12.5+(a-1000)*5/250.0 << endl;
    }
    return 0;
}
