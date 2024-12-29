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
#include "Climb.hpp"

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

void Player::addItem(std::shared_ptr<Buff> item) {
    items.push_back(item);
}

const std::set<Attack> Player::DEF_ATTACKS_PLAYER = {
    DefinedAttacks::get(ATTACK1).attack, DefinedAttacks::get(ATTACK2).attack, DefinedAttacks::get(ATTACK3).attack
};
