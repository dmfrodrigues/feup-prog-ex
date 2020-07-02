#include <iostream>
#include <vector>
#include <set>

using namespace std;

void removeDuplicates(vector<int> &v){
    set<int> s;
    for(unsigned i = 0; i < v.size(); ++i)
        if(s.find(v[i]) != s.end()) v.erase(v.begin()+(i--));
        else                        s.insert(v[i]);
}

int main(){
    vector<int> v = {2,8,5,6,2,124,8,345,2345,123,1,3,6,8,3,2,5,8};
    removeDuplicates(v);
    for(auto i:v) cout << i << " ";
    cout << endl;
    return 0;
}
