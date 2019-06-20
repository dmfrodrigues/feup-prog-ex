#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

int main(){
    Board b(10,20);
    unsigned id; cin >> id;
    char symb; cin >> symb;
    Position pos; cin >> pos.lin >> pos.col;
    char dir; cin >> dir;
    size_t sz; cin >> sz;
    Ship s(id, symb, pos, dir, sz);
    if(!b.putShip(s)) throw string("Can't put ship!");
}
