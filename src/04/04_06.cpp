#include <iostream>

using namespace std;

void readIntArray(int a[], int nElem){
    for(int i = 0; i < nElem; ++i)
        cin >> a[i];
}

int searchValueInIntArray(const int a[], int nElem, int value){
    for(int i = 0; i < nElem; ++i)
        if(a[i] == value)
            return i;
    return -1;
}

int searchMultValuesInIntArray(const int a[], int nElem, int value, int index[]){
    int r = 0;
    for(int i = 0; i < nElem; ++i)
        if(a[i] == value)
            index[r++] = i;
    return r;
}

int main(){
    int a[10];
    int nElem = 10;
    int index[10];
    readIntArray(a, nElem);
    int i = searchValueInIntArray(a, nElem, 5); cout << i << endl;
    int j = searchMultValuesInIntArray(a, nElem, 5, index); cout << j << endl;
    for(int k = 0; k < j; ++k) cout << index[k] << " ";
    cout << endl;
    return 0;
}
