#include <iostream>
#include "Date.h"

using namespace std;

int main(){
    Date d1, d2;
    try{
        cout << "Date1 (yyyy:mm:dd)? "; cin >> d1;
        cout << "Date2 (yyyy:mm:dd)? "; cin >> d2;
    }catch(exception &e){
        cout << e.what() << endl;
        return 1;
    }
    if     (d1 < d2) cout << "before"  << endl;
    else if(d2 < d1) cout << "after" << endl;
    else             cout << "equal"  << endl;
    return 0;
}
