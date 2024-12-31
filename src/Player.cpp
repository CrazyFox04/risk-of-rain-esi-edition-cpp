//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Player.hpp"
#include "Run.hpp"
#include <memory>
#include "GameOverException.hpp"
#include <random>
#include "Climb.hpp"
#include "Items.hpp"

Player::Player(): Character("PLAYER", DEF_MAX_HEALTH, DEF_HURT_TIME,
                            {
                                {DEF_ATTACKS_PLAYER}, {
                                    std::make_shared<Run>(DEF_RUN_FORCE),
                                    std::make_shared<Jump>(DEF_JUMP_FORCE, 1),
                                    std::make_shared<Dash>(),
                                    std::make_shared<Climb>(DEF_CLIMB_FORCE)
                                },
                                true
                            }) {
}

Player::Player(int primaryAttack, int secondaryAttack, int tertiaryAttack) : Character(
    "PLAYER", DEF_MAX_HEALTH, DEF_HURT_TIME,
    {
        {
            DefinedAttacks::get(static_cast<Attacks>(primaryAttack)).attack,
            DefinedAttacks::get(static_cast<Attacks>(secondaryAttack)).attack,
            DefinedAttacks::get(static_cast<Attacks>(tertiaryAttack)).attack
        },
        {
            std::make_shared<Run>(DEF_RUN_FORCE),
            std::make_shared<Jump>(DEF_JUMP_FORCE, 1),
            std::make_shared<Dash>(),
            std::make_shared<Climb>(DEF_CLIMB_FORCE)
        },
        true
    }) {
}


const std::vector<Attack> Player::DEF_ATTACKS_PLAYER = {
    DefinedAttacks::get(ATTACK1).attack, DefinedAttacks::get(ATTACK2).attack, DefinedAttacks::get(ATTACK3).attack
};

void Player::die() {
    if (items.contains("TEDDY_BEAR")) {
        items.at("TEDDY_BEAR") -= 1;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 100);
        if (dis(gen) < 5) {
            health.current = 0.1 * health.max;
        }
    }
    throw GameOverException("Game over : Player is dead");
}
