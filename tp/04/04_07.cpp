#include <iostream>
#include <vector>

using namespace std;

vector<int> readIntVector(int nElem){
    vector<int> v(nElem);
    for(int i = 0; i < nElem; ++i)
        cin >> v[i];
    return v;
}

int searchValueInVector(const vector<int> &v, int value){
    for(unsigned i = 0; i < v.size(); ++i)
        if(v[i] == value)
            return i;
    return -1;
}

vector<int> searchMultValuesInIntVector(const vector<int> &v, int value){
    vector<int> r;
    for(unsigned i = 0; i < v.size(); ++i)
        if(v[i] == value)
            r.push_back(i);
    return r;
}

int main(){
    int nElem = 10;
    vector<int> v = readIntVector(nElem);
    int i = searchValueInVector(v, 5); cout << i << endl;
    vector<int> j = searchMultValuesInIntVector(v, 5);
    for(unsigned k = 0; k < j.size(); ++k) cout << j[k] << " ";
    cout << endl;
    return 0;
}
