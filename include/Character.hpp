//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <vector>
// #include <Item.hpp> todo

class Character {
    int health;
    int speed;
    int damage;
    //std::vector<Item> items; todo

public:
    Character(int health, int speed, int damage);

    Character(const Character&other);

    virtual void hit(int damage);

    virtual void kill();

    // virtual void canShoot(Weapon weapon); todo

    virtual void canHit(int damage);
};
#endif //CHARACTER_HPP
