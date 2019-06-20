#pragma once

#include <string>
#include <sstream>

using namespace std;

void simplify(const string &name, string &sName){
    stringstream ss(name);
    string s; ss >> s; sName = s;
    string prev; s = "";
    while(ss){
        prev = s;
        ss >> s;
    }
    if(prev != "") sName += " " + prev;
}
