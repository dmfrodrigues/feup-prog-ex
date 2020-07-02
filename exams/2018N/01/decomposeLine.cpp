#include "decomposeLine.h"
#include "transformLine.h"
#include <sstream>

using namespace std;

void decomposeLine(const string &line, vector<string> &words){
    words.clear();
    stringstream ss(transformLine(line));
    string tmp;
    ss >> tmp;
    while(ss){
        words.push_back(tmp);
        ss >> tmp;
    }
}
