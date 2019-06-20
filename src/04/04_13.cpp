#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string inpath; cout << "inpath: "; cin >> inpath;
    ifstream is(inpath);
    vector<string> v;
    string s;
    getline(is, s);
    while(is){
        v.push_back(s);
        getline(is,s);
    }
    sort(v.begin(), v.end());
    string outpath = "sorted_" + inpath;
    ofstream os(outpath);
    for(const auto& i:v)
        os << i << endl;
    return 0;
}
