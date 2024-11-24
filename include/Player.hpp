//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include "Character.hpp"

class Weapon; // a supprimer une fois que la classe Weapon sera créée et incluse

class Player : public Character {
private:
    std::shared_ptr<Weapon> activeWeapon;
    std::vector<std::shared_ptr<Weapon>> weapons;

public:
    Player(int health, int speed, int damage);
    ~Player() override = default;

    bool canShoot() const;
    void useItem(const std::shared_ptr<Item> &item);
    void switchWeapons();
    void addWeapon(const std::shared_ptr<Weapon> &weapon);
    void addItem(const std::shared_ptr<Item> &item);
    std::shared_ptr<Weapon> getActiveWeapon() const;
    std::shared_ptr<Item> getItem(size_t index) const;

    void attack() override;
    void shoot() override;

protected:
    void increaseHealth(int amount);
    void increaseSpeed(int amount);
    void increaseDamage(int amount);
};
#endif //PLAYER_HPP
