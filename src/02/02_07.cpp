#include <iostream>
#include <cmath>
#define PI 3.14159265359

using namespace std;

int main(){
    double l, r, step;
    cout << "l r ? "; cin >> l >> r;
    cout << "step ? "; cin >> step;
    cout << "\tang\tsen\t\tcos\t\ttan" << endl;
    for(double i = l; i <= r; i += step){
        printf("\t%.0f\t%f\t%f\t%f\n", i, sin(i*PI/360.0), cos(i*PI/360.0), tan(i*PI/360.0));
    }
    return 0;
}
