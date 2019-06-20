#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string s; cin >> s;
    string s_ = s; reverse(s_.begin(), s_.end());
    cout << (s==s_) << endl;
    return 0;
}
