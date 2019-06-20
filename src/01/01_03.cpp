#include <iostream>

using namespace std;

const float pi = 3.14159265359;

int main(){
    float rho, r;
    cout << "rho / (kg/m^3): "; cin >> rho;
    cout << "r   / (     m): "; cin >> r;
    float M = (4.0/3.0)*rho*pi*r*r*r;
    cout << "M   / (    kg): " << M << endl;
    return 0;
}
