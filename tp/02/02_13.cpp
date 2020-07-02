#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N; cin >> N; cout << N <<"=";
    vector<int> v;
    int i = 2;
    while(N != 1){
        if(N%i == 0){
            v.push_back(i);
            N /= i;
        }else{
            ++i;
        }
    }
    cout << v[0];
    for(unsigned i = 1; i < v.size(); ++i)
        cout << "x" << v[i];
    cout << endl;
    return 0;
}
