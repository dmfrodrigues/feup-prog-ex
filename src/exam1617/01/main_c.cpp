#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include "simplify.h"

using namespace std;

int main(){
    ifstream is("people1.txt");
    if(!is){ cerr << "people1.txt not found" << endl; return 1; }
    ofstream os("people2.txt");
    multiset<string> ms;
    string n, sn;
    getline(is, n);
    while(is){
        simplify(n,sn);
        ms.insert(sn);
        getline(is, n);
    }
    for(const string &s:ms){
        os << s << endl;
    }
    return 0;
}
