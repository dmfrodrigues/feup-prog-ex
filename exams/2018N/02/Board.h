#pragma once

#include <vector>
#include <cstddef>
#include "Ship.h"

class Board{
public:
    Board(size_t numLines = 10, size_t numColumns = 10);
    bool putShip(const Ship &s);
private:
    bool canPutShip(Position pos, char dir, size_t size);
    size_t numLines, numColumns;
    std::vector< std::vector<int> > board;
    std::vector<Ship> ships;
};
