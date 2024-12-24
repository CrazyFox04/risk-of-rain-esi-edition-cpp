//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Character.hpp"

class Enemy : public Character {
private:
    bool canThrow;

public:
    Enemy(int health, int speed, int damage, bool canThrow);

    ~Enemy() override = default;

    bool getCanThrow() const { return canThrow; }
    void setCanThrow(bool value) { canThrow = value; }

    void attack() override;
    void shoot() override;
};
#endif //ENEMY_HPP
