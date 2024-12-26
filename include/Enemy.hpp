//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Character.hpp"

class Enemy : public Character {
    bool isBoss;
    double followRange;
    double attackRange;
    

public:
    Enemy(int maxHealth, double followRange, double attackRange, double hurtTime,
          Capabilities capabilities, bool isBoss);

    ~Enemy() override = default;

    void addItem(std::shared_ptr<Buff> buff) override;
};
#endif //ENEMY_HPP
