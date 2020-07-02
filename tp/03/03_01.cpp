#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2){
    double dx = x2-x1;
    double dy = y2-y1;
    return sqrt(dx*dx + dy*dy);
}

double area(double x1, double y1, double x2, double y2, double x3, double y3){
    double a = distance(x1, y1, x2, y2);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x2, y2, x3, y3);
    double s = (a+b+c)/2.0;
    double d = sqrt(s*(s-a)*(s-b)*(s-c));
    return d;
}

int main(){
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << area(x1, y1, x2, y2, x3, y3) << endl;
    return 0;
}
