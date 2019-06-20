#include "toUpperStr.h"
#include <locale>

using namespace std;

void toUpperStr(string &s){
    for(char &c:s)
        c = toupper(c);
}
