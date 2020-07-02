#include <iostream>
#include <cstddef>
#include <string>
#include <vector>
#include <map>

#include "Date.h"

using namespace std;

class Image{
public:
    Image(size_t nLins=0, size_t nCols=0, int pixVal=0);
    void setPixel(size_t lin, size_t col, int pixVal);
    bool read(string fileName);
    Image getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const;
    int getPixel(size_t lin, size_t col) const;
private:
    vector< vector<int> > img;
};

Image Image::getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const{
    Image ret(nLins, nCols);
    for(size_t i = 0; i < nLins; ++i){
        for(size_t j = 0; j < nCols; ++j){
            ret.setPixel(i,j,this->getPixel(lin+i, col+j));
        }
    }
    return ret;
}

int main(){
    multimap<Date, Image> a;
    Date d; cin >> d;
    string s;
    getline(cin, s);
    while(cin && s != ""){
        Image im;
        im.read(s);
        a.insert(pair<Date,Image>(d, im));
        getline(cin, s);
    }
    return 0;
}
