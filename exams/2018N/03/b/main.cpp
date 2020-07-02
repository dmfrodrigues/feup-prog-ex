#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> v = {"12", "31", "32", "7"};
    if(find(v.begin(), v.end(), "31") != v.end()) cout << "Encontrei!" << endl;
    else cout << "Não encontrei" << endl;
    return 0;
}
