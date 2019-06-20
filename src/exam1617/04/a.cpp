#include <iostream>
#include <string>

using namespace std;

int readNumber(string msg){
    int number;
    cout << msg; cin >> number;
    return number;
}

void readNumber(string msg, int &number){
    cout << msg; cin >> number;
}

int main(){
    return 0;
}
