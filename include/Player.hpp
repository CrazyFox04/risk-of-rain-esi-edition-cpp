//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <memory>
#include "Character.hpp"

class Player : public Character {
    std::shared_ptr<Weapon> activeWeapon;
    std::vector<std::shared_ptr<Weapon>> weapons;

public:
    static constexpr int DEF_HEALTH = 100;
    static constexpr int DEF_SPEED = 1;
    static constexpr int DEF_DAMAGE = 10;

    Player();
    Player(int health, int speed, int damage);
    ~Player() override = default;

    bool canShoot() const;
    void useItem(const std::shared_ptr<Buff> &item);
    void switchWeapons();
    void addWeapon(const std::shared_ptr<Weapon> &weapon);
    void addItem(const std::shared_ptr<Buff> &item);
    std::shared_ptr<Weapon> getActiveWeapon() const;
    std::shared_ptr<Buff> getItem(size_t index) const;

    void attack() override;
    void shoot() override;

    void increaseHealth(int amount);
    void increaseMaxHealth(int amount);
    void increaseSpeed(int amount);
    void increaseDamage(int amount);
};
#endif //PLAYER_HPP
