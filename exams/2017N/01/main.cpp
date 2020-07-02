#include <iostream>
#include <string>
#include <fstream>
#include "simplify.h"

using namespace std;

int main(){
    ifstream is("people1.txt");
    if(!is){ cerr << "people1.txt not found" << endl; return 1; }
    ofstream os("people2.txt");
    string n, sn;
    getline(is, n);
    while(is){
        simplify(n,sn);
        os << sn << endl;
        getline(is, n);
    }
    return 0;
}
