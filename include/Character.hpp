//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Buff.h"
#include "Weapon.h"
#include <vector>
#include <memory>

class Character {
protected:
    int health;
    int speed;
    int damage;
    std::vector<std::shared_ptr<Buff>> buffs;

public:
    Character(int health, int speed, int damage);

    virtual ~Character() = default;

    // Getters
    int getHealth() const { return health; }
    int getSpeed() const { return speed; }
    int getDamage() const { return damage; }
    const std::vector<std::shared_ptr<Buff>> &getItems() const { return buffs; }


    virtual void hit(int damage);
    virtual void kill();
    virtual bool canHit(int damage) const;
    virtual void attack() = 0;  // Méthode pure virtuelle
    virtual void shoot() = 0;   // Méthode pure virtuelle
    void addItem(std::shared_ptr<Buff> buff);
};
#endif //CHARACTER_HPP
