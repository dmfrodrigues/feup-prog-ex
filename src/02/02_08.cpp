#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n; float q, j;
    cout << "n ? "; cin >> n;
    cout << "q ? "; cin >> q;
    cout << "j%? "; cin >> j;
    cout << q*pow(1.0+j/100.0, n) << endl;
    return 0;
}
