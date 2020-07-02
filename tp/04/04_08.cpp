#include <iostream>
#include <vector>

using namespace std;

void bubblesort(vector<string> &v){
    for(unsigned i = 0; i < v.size()-1; ++i)
        for(unsigned j = i+1; j < v.size(); ++j)
            if(v[i]>v[j])
                swap(v[i], v[j]);
}

int main(){
    vector<string> v = {"ANTONIO", "ANDRE", "CASA", "MARIA", "CAO", "GATO", "CEU", "PRAIA", "DESPORTO", "CASA"};
    bubblesort(v);
    for(auto s:v) cout << s << " ";
    cout << endl;
    return 0;
}
