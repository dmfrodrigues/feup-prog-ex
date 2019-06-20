#include <iostream>
#include <cmath>

using namespace std;

double integrateTR(double f(double), double a, double b, int n){
    double ans = 0.0L;
    double h = (b-a)/double(n);
    double x1 = a, x2 = a+h;
    for(int i = 1; i <= n; i++, x1+=h, x2+=h)
        ans += h*(f(x1)+f(x2))/2.0L;
    return ans;
}

double f1(double n){ return n*n; }
double f2(double n){ return sqrt(4-n*n); }

int main(){
    for(int n = 2, i = 0; i < 10; ++i, n*=2){
        cout << integrateTR(f1, 0, 10, n) << "    " << integrateTR(f2, -2, 2, n) << endl;
    }
    return 0;
}
