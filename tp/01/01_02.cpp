#include <iostream>

using namespace std;

int main(){
    float A, B, C;
    cout << "A ? "; cin >> A;
    cout << "B ? "; cin >> B;
    cout << "C ? "; cin >> C;
    float media = (A+B+C)/3.0;
    cout << "media   = " <<   media << endl;
    cout << "A-media = " << A-media << endl;
    cout << "B-media = " << B-media << endl;
    cout << "C-media = " << C-media << endl;
    return 0;
}
