#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    float in[3];
    cin >> in[0] >> in[1] >> in[2];
    sort(in, in+3);
    cout << in[0] << " " << in[1] << " " << in[2] << endl;
    return 0;
}
