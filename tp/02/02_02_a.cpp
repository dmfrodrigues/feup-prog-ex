#include <iostream>

using namespace std;

int main(){
    float a, b, c;
    cin >> a >> b >> c;
    float m = min(a,min(b,c));
    float M = max(a,max(b,c));
    cout << m << endl;
    cout << M << endl;
    return 0;
}
