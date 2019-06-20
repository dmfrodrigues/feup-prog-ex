#include <iostream>

using namespace std;

int gcd(int a, int b){
    return (b? gcd(b, a%b) : a);
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}

bool readFracc(int& numerator, int& denominator){
    char s[256]; cin >> s;
    auto i = sscanf(s, "%d/%d", &numerator, &denominator);
    if(i == EOF){
        numerator = denominator = 0;
        return false;
    }else return true;
}

void writeFracc(int numerator, int denominator){
    char s[256]; sprintf(s, "%d/%d", numerator, denominator);
    cout << s;
}

void reduceFracc(int &numerator, int &denominator){
    int n = gcd(numerator, denominator);
    numerator /= n;
    denominator /= n;
}

void sum(int n1, int d1, int n2, int d2, int& n, int& d){
    d = lcm(d1, d2);
    int c1 = d/d1;
    int c2 = d/d2;
    n = n1*c1+n2*c2;
    reduceFracc(n, d);
}

void sub(int n1, int d1, int n2, int d2, int& n, int& d){
    sum(n1, d1, -n2, d2, n, d);
}

void mul(int n1, int d1, int n2, int d2, int& n, int& d){
    n = n1*n2;
    d = d1*d2;
    reduceFracc(n, d);
}

void div(int n1, int d1, int n2, int d2, int& n, int& d){
    n = n1*d2;
    d = d1*n2;
    reduceFracc(n, d);
}

int main(){
    int n1, n2, d1, d2, n, d;
    while(true){
        cout << "frac1:"; readFracc(n1, d1);
        cout << "frac2:"; readFracc(n2, d2);
        sum(n1, d1, n2, d2, n, d);
        writeFracc(n1,d1); cout << " + "; writeFracc(n2,d2); cout << " = "; writeFracc(n,d); cout << endl;
        sub(n1, d1, n2, d2, n, d);
        writeFracc(n1,d1); cout << " - "; writeFracc(n2,d2); cout << " = "; writeFracc(n,d); cout << endl;
        mul(n1, d1, n2, d2, n, d);
        writeFracc(n1,d1); cout << " * "; writeFracc(n2,d2); cout << " = "; writeFracc(n,d); cout << endl;
        div(n1, d1, n2, d2, n, d);
        writeFracc(n1,d1); cout << " / "; writeFracc(n2,d2); cout << " = "; writeFracc(n,d); cout << endl;
    }
    return 0;
}
