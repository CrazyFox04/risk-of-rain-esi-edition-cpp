//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <vector>
#include <memory>

class Item;

class Character {
protected:
    int health;
    int speed;
    int damage;
    std::vector<std::shared_ptr<Item>> items;

public:
    Character(int health, int speed, int damage);

    virtual ~Character() = default;

    // Getters
    int getHealth() const { return health; }
    int getSpeed() const { return speed; }
    int getDamage() const { return damage; }
    const std::vector<std::shared_ptr<Item>> &getItems() const { return items; }


    virtual void hit(int damage);
    virtual void kill();
    virtual bool canHit(int damage) const;
    virtual void attack() = 0;  // Méthode pure virtuelle
    virtual void shoot() = 0;   // Méthode pure virtuelle
    void addItem(std::shared_ptr<Item> item);

protected:
    void modifyStats(int healthMod, int speedMod, int damageMod);
};
#endif //CHARACTER_HPP
