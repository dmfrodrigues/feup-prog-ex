#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float s = 0, m = 1e9, M = -1e9; int c = 0;
    float x;
    std::string line;
    while (cin >> x){
        s += x;
        m = min(m, x);
        M = max(M, x);
        ++c;
    }
    cout << "Soma=" << s << endl;
    cout << "Media=" << s/float(c) << endl;
    cout << "Min=" << m << endl;
    cout << "Max=" << M << endl;
    return 0;
}
