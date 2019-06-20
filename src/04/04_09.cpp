#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int> &v, int value){
    int bottom = 0;
    int top    = v.size();
    int middle;
    bool found = false;
    while(!(bottom > top) && !found){
        middle = (bottom+top)/2;
        if(v[middle] == value) found = true;
        else if(v[middle] < value) bottom = middle+1;
        else                       top    = middle-1;
    }
    if(found) return middle;
    else      return -1;
}

int main(){
    vector<int> v = {2,8,5,6,2,124,8,345,2345,123,1,3,6,8,3,2,5,8};
    sort(v.begin(), v.end());
    cout << binarySearch(v, 123) << endl;
    cout << binarySearch(v, 122) << endl;
    return 0;
}
