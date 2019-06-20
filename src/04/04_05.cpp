#include <iostream>

using namespace std;

int gcd(int a, int b){
    return (b? gcd(b, a%b) : a);
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}

struct Fraction{
private:
    int n, d;
    static void reduceFracc(Fraction& f){
        int n = gcd(f.n, f.d);
        f.n /= n;
        f.d /= n;
    }
public:
    bool readFracc(){
        char s[256]; cin >> s;
        auto i = sscanf(s, "%d/%d", &n, &d);
        if(i == EOF){
            n = d = 0;
            return false;
        }else return true;
    }
    void writeFracc(){
        char s[256]; sprintf(s, "%d/%d", n, d);
        cout << s;
    }
    void sum(Fraction f1, Fraction f2){
        d = lcm(f1.d, f2.d);
        int c1 = d/f1.d;
        int c2 = d/f2.d;
        n = f1.n*c1+f2.n*c2;
        reduceFracc(*this);
    }
    void sub(Fraction f1, Fraction f2){
        f2.n *= -1;
        sum(f1, f2);
    }
    void mul(Fraction f1, Fraction f2){
        n = f1.n*f2.n;
        d = f1.d*f2.d;
        reduceFracc(*this);
    }

    void div(Fraction f1, Fraction f2){
        n = f1.n*f2.d;
        d = f1.d*f2.n;
        reduceFracc(*this);
    }
};

int main(){
    Fraction f1, f2, f;
    while(true){
        cout << "f1:"; f1.readFracc();
        cout << "f2:"; f2.readFracc();
        f.sum(f1, f2);
        f1.writeFracc(); cout << " + "; f2.writeFracc(); cout << " = "; f.writeFracc(); cout << endl;
        f.sub(f1, f2);
        f1.writeFracc(); cout << " + "; f2.writeFracc(); cout << " = "; f.writeFracc(); cout << endl;
        f.mul(f1, f2);
        f1.writeFracc(); cout << " + "; f2.writeFracc(); cout << " = "; f.writeFracc(); cout << endl;
        f.div(f1, f2);
        f1.writeFracc(); cout << " + "; f2.writeFracc(); cout << " = "; f.writeFracc(); cout << endl;
    }
    return 0;
}
