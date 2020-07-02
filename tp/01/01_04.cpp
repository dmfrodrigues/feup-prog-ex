#include <iostream>

using namespace std;

int main(){
    float a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    float x = (c*e - b*f)/(a*e - b*d);
    float y = (a*f - c*d)/(a*e - b*d);
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    return 0;
}
