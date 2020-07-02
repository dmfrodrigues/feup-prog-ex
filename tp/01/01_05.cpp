#include <iostream>

using namespace std;

int main(){
    int h1, m1, s1, h2, m2, s2;
    cout << "Tempo 1 (horas minutos segundos) ? "; cin >> h1 >> m1 >> s1;
    cout << "Tempo 2 (horas minutos segundos) ? "; cin >> h2 >> m2 >> s2;
    int d=0, h=0, m=0, s=0;
    s+= s1+s2; m += s/60; s %= 60;
    m+= m1+m2; h += m/60; m %= 60;
    h+= h1+h2; d += h/24; h %= 24;
    cout << "Soma dos tempos: " << d << " dias, " << h << " horas, " << m << " minutos e " << s << " segundos" << endl;
    return 0;
}
