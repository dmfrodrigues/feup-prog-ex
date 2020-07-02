#include "Ship.h"

Ship::Ship(unsigned int identifier, char symbol,
    Position position, char direction, size_t size){
    this->identifier = identifier;
    this->symbol = symbol;
    this->position = position;
    this->direction = direction;
    this->sz = size;
}

unsigned int Ship::id() const{ return identifier; }
Position Ship::pos() const{ return position; }
char Ship::dir() const{ return direction; }
size_t Ship::size() const{ return sz; }
