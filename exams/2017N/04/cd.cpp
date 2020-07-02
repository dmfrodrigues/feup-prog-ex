#include <iostream>
#include <cstddef>
#include <string>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

class Image{
public:
    Image(size_t nLins=0, size_t nCols=0, int pixVal=0);
    void setPixel(size_t lin, size_t col, int pixVal);
    bool read(string fileName);
    Image getRegion(size_t lin, size_t col, size_t nLins, size_t nCols) const;
    int getPixel(size_t lin, size_t col) const;
private:
    int **img = NULL;
};

Image::Image(size_t nLins, size_t nCols, int pixVal){
    img = new int*[nLins];
    for(unsigned i = 0; i < nLins; ++i){
        img[i] = new int[nCols];
        fill(img[i], img[i]+nCols, pixVal);
    }
}

int main(){
    return 0;
}
