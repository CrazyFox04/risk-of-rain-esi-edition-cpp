//
// Created by Enzo Renard on 19/11/2024.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <chrono>
#include <string>
#include <array>
#include "Dash.hpp"
#include "Jump.hpp"
#include "Run.hpp"

#include "Capabilities.hpp"
#include "Health.hpp"
#include "Character.hpp"

class Player : public Character {
public:
    static constexpr int DEF_MAX_HEALTH = 100;
    static constexpr double DEF_RUN_FORCE = 4.0;
    static constexpr double DEF_JUMP_FORCE = 5.0;
    static constexpr double DEF_HURT_TIME = 0.5;
    static constexpr std::set<std::shared_ptr<Movement>> DEF_MOVEMENTS{
        std::make_shared<Run>(DEF_RUN_FORCE), std::make_shared<Jump>(DEF_JUMP_FORCE, 1),
        std::make_shared<Dash>()
    };
    static constexpr std::set<Attack> DEF_ATTACKS = {
        DefinedAttacks::get(ATTACK1).attack, DefinedAttacks::get(ATTACK2).attack, DefinedAttacks::get(ATTACK3).attack
    };

    Player();

    ~Player() override = default;

    void addItem(const std::shared_ptr<Buff>&item);
};
#endif //PLAYER_HPP
