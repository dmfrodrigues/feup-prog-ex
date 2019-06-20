#include <iostream>

using namespace std;

bool sequenceSearch(string s, int nc, char c){
    for(unsigned i = 0; i+nc-1 < s.size(); ++i){
        bool b = true;
        for(unsigned j = 0; j < (unsigned)nc; ++j) if(s[i+j] != c){ b = false; break; }
        if(b) return true;
    }
    return false;
}

int main(){
    cout << sequenceSearch("abaaaabaaaaabccccc", 5, 'a') << endl;
    cout << sequenceSearch("abaaaabaaaaabccccc", 6, 'a') << endl;
    return 0;
}
