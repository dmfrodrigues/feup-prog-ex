#include "Board.h"

using namespace std;

Board::Board(size_t numLines, size_t numColumns){
    board = vector< vector<int> >(numLines, vector<int>(numColumns, -1));
    this->numLines = numLines;
    this->numColumns = numColumns;
}

bool Board::canPutShip(Position pos, char dir, size_t size){
    switch(dir){
        case 'H':
            if(pos.lin < 0 || pos.col < 0) return false;
            for(; size--; ++pos.col){
                if(pos.col >= numColumns || board[pos.lin][pos.col] != -1) return false;
            }
            return true;
        case 'V':
            return true;
    }
}

bool Board::putShip(const Ship &s){
    if(!this->canPutShip(s.pos(), s.dir(), s.size())){
        return false;
    }else{
        size_t sz = s.size();
        Position pos = s.pos();
        switch(s.dir()){
            case 'H':
                for(; --sz; ++pos.col) board[pos.lin][pos.col] = s.id();
                break;
            case 'V':
                for(; --sz; ++pos.lin) board[pos.lin][pos.col] = s.id();
                break;
        }
        return true;
    }
}
