#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> union_(const vector<int> &v1, const vector<int> &v2){
    set<int> s;
    s.insert(v1.begin(), v1.end());
    s.insert(v2.begin(), v2.end());
    return vector<int>(s.begin(), s.end());
}
vector<int> intersection_(const vector<int> &v1, const vector<int> &v2){
    set<int> s;
    set<int> r;
    s.insert(v1.begin(), v1.end());
    for(const auto& i:v2) if(s.find(i) != s.end()) r.insert(i);
    return vector<int>(r.begin(), r.end());
}

int main(){
    vector<int> v1 = {2,8,5,6,2,124,8,345,2345,123,1,3,6,8,3,2,5,8};
    vector<int> v2 = {6,2,6,9,0,6,54,2,345};
    vector<int> a = union_(v1,v2);
    for(auto i:a) cout << i << " ";
    cout << endl;
    vector<int> b = intersection_(v1,v2);
    for(auto i:b) cout << i << " ";
    cout << endl;
    return 0;
}
