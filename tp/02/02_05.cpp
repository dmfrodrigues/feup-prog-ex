#include <iostream>
#include <cmath>
#define PRECISION 0.0000001L

using namespace std;

int main(){
    double a, b, c;
    cout << "Introduza os coeficientes (a b c): ";
    cin >> a >> b >> c;
    double D = b*b-4.0L*a*c;
    if(abs(D) < PRECISION){
        double r = -b/(2.0*a);
        cout << "A equação tem 2 raízes reais iguais: " << r << " e " << r << endl;
    }else if(D < 0.0){
        double r = -b/(2.0*a);
        double i1 = +sqrt(-D);
        double i2 = -sqrt(-D);
        printf("A equação tem 2 raízes complexas diferentes: %f%+fi e %f%+fi\n", r, i1, r, i2);
    }else{
        double r1 = (-b+sqrt(D))/(2.0*a);
        double r2 = (-b-sqrt(D))/(2.0*a);
        cout << "A equação tem 2 raízes reais diferentes: " << r1 << " e " << r2 << endl;
    }

    return 0;
}
