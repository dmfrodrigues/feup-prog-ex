#include <iostream>
#include <cstddef>
#include <string>
#include <vector>
#include <map>

#include "Date.h"

using namespace std;

template<class T>
class Image{
public:
    Image(size_t nLins=0, size_t nCols=0, T pixVal=0);
    void setPixel(size_t lin, size_t col, T pixVal);
    bool read(string fileName);
    Image getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const;
    T getPixel(size_t lin, size_t col) const;
private:
    vector< vector<T> > img;
};

template<class T>
Image<T> Image<T>::getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const{
    Image<T> ret(nLins, nCols);
    for(size_t i = 0; i < nLins; ++i){
        for(size_t j = 0; j < nCols; ++j){
            ret.setPixel(i,j,this->getPixel(lin+i, col+j));
        }
    }
    return ret;
}

int main(){
    multimap<Date, Image<int> > a;
    Date d; cin >> d;
    string s;
    getline(cin, s);
    while(cin && s != ""){
        Image<int> im;
        im.read(s);
        a.insert(pair<Date,Image<int> >(d, im));
        getline(cin, s);
    }
    return 0;
}
