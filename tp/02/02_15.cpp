#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    int a = 1+rand()%9;
    int b = 1+rand()%9;
    int ans;
    cout << a << "*" << b << "=";
    time_t t1 = time(NULL);
    cin >> ans;
    time_t t2 = time(NULL);
    if(ans != a*b){
        cout << "Muito Mau" << endl;
    }else{
        time_t Dt = t2-t1;
        if(Dt < 5){
            cout << "Bom" << endl;
        }else if(Dt <= 10){
            cout << "Satisfaz" << endl;
        }else{
            cout << "Insuficiente" << endl;
        }
    }
    return 0;
}
