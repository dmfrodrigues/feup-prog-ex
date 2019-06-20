#include <iostream>
#include <cstring>

using namespace std;

bool isHydroxide(char compound[]){
    int sz = strlen(compound);
    if(sz < 2) return false;
    return (compound[sz-2] == 'O' && compound[sz-1] == 'H');
}

bool isHydroxide(string compound){
    int sz = compound.size();
    if(sz < 2) return false;
    return (compound[sz-2] == 'O' && compound[sz-1] == 'H');
}

int main(){
    string s;
    s = "KOH";
    cout << s << ": " << isHydroxide(s) << endl;
    s = "H2O2";
    cout << s << ": " << isHydroxide(s) << endl;
    s = "NaCl";
    cout << s << ": " << isHydroxide(s) << endl;
    s = "NaOH";
    cout << s << ": " << isHydroxide(s) << endl;
    s = "C9H8O4";
    cout << s << ": " << isHydroxide(s) << endl;
    s = "MgOH";
    cout << s << ": " << isHydroxide(s) << endl;
}
