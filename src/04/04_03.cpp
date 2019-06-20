#include <iostream>

using namespace std;

bool isup(char c){ return ('A' <= c && c <= 'Z'); }
bool islo(char c){ return ('a' <= c && c <= 'z'); }

void decompose(string s){
    while(!s.empty()){
        if(isup(s[0])){
            if(s.size() > 1 && islo(s[1])){
                cout << s.substr(0,2) << " "; s = s.substr(2);
            }else{
                cout << s.substr(0,1) << " "; s = s.substr(1);
            }
        }else s = s.substr(1);
    }
}

int main(){
    decompose("H2O"); cout << endl;
    decompose("KOH"); cout << endl;
    decompose("H2O2"); cout << endl;
    decompose("NaCl"); cout << endl;
    decompose("NaOH"); cout << endl;
    decompose("C9H8O4"); cout << endl;
    decompose("MgOH"); cout << endl;
    return 0;
}
