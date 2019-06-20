#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float x1, y1,
          x2, y2,
          x3, y3;
    cin >> x1 >> y1
        >> x2 >> y2
        >> x3 >> y3;
    float a = sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
    float b = sqrt(pow(x1-x3, 2.0) + pow(y1-y3, 2.0));
    float c = sqrt(pow(x2-x3, 2.0) + pow(y2-y3, 2.0));
    float s = (a+b+c)/2.0;
    float area = sqrt(s*(s-a)*(s-b)*(s-c));
    cout << "area=" << area << endl;
    return 0;
}
