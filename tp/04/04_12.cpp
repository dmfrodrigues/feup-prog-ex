#include <iostream>
#include <sstream>

using namespace std;

double executeOperation(string op){
    stringstream ss(op);
    double a, b; char oper;
    ss >> a >> oper >> b;
    switch(oper){
        case '+': return a+b; break;
        case '-': return a-b; break;
        case '*': return a*b; break;
        case '/': return a/b; break;
    }
    return 0;
}

int main(){
    cout << executeOperation("2+5.3") << endl;
    return 0;
}
