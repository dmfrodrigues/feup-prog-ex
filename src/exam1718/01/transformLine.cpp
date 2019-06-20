#include "transformLine.h"
#include "toUpperStr.h"

using namespace std;

string transformLine(string s){
    toUpperStr(s);
    for(auto &c:s)
        if(c < 'A' || 'Z' < c)
            c = ' ';
    return s;
}
