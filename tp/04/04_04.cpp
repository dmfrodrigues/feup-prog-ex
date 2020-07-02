#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string upper_case(string s){
    for(auto& c:s) c = toupper(c);
    return s;
}

string trim(string s){
    string ret = s;
    size_t i;
    i = ret.find_first_not_of(' '); if(i != s.npos) ret = ret.substr(i);
    i = ret.find_last_not_of (' '); if(i != s.npos) ret = ret.substr(0, i+1);
    return ret;
}

vector<string> split(string s, char delim){
    vector<string> ret;
    while(true){
        size_t i = s.find(delim); if(i == s.npos) break;
        string t = trim(s.substr(0,i));
        if(t != "") ret.push_back(t);
        s = s.substr(i+1);
    }
    s = trim(s);
    if(s != "") ret.push_back(s);
    return ret;
}

string join(const vector<string>& v, string delim){
    string ret;
    if(!v.empty()){
        ret += v[0];
        for(unsigned i = 1; i < v.size(); ++i)
            ret += delim + v[i];
    }
    return ret;
}

set<string> s = {"DE", "DO", "DA", "DAS", "DOS", "E"};
string normalizeName(string name){
    name = upper_case(name);
    vector<string> v = split(name, ' ');
    for(unsigned i = 0; i < v.size(); ++i){
        if(s.find(v[i]) != s.end()) v.erase(v.begin()+i);
    }
    return join(v, " ");
}

int main(){
    string s = "AntOnio de AlMeiDa e Castro da rocha e sousa do carvaLho dos santos das flores";
    cout << normalizeName(s) << endl;
    return 0;
}
