#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) {this->type = type;}

Weapon::~Weapon()
{
    std::cout << "Weapon : call destructor\n";
}

const std::string &Weapon::getType() const {return type;}

void Weapon::setType(std::string type) {this->type = type;}
