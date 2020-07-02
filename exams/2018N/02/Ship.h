#pragma once

#include <cstddef>

struct Position{
    int lin, col;
};

class Ship{
public:
    Ship(unsigned int identifier, char symbol,
        Position position, char direction,
        size_t size);
    unsigned int id() const;
    Position pos() const;
    char dir() const;
    size_t size() const;
private:
    unsigned int identifier;
    char symbol;
    Position position;
    char direction;
    size_t sz;
};
