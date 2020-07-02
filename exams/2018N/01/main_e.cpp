#include <iostream>
#include <string>
#include <set>
#include <fstream>

#include "decomposeLine.h"

using namespace std;

int main(){
    string in_path = "text.txt"; /* "C:\\docs\\text.txt" */
    string out_path = "words_e.txt";
    set<string> ms;
    string buff;
    ifstream is(in_path);
    getline(is, buff);
    while(is){
        vector<string> words;
        decomposeLine(buff, words);
        ms.insert(words.begin(), words.end());
        getline(is, buff);
    }
    ofstream os(out_path);
    for(const string &s:ms)
        os << s << endl;
    return 0;
}
