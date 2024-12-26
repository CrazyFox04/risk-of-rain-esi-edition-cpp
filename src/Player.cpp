//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Player.hpp"

Player::Player(): Character(DEF_MAX_HEALTH, DEF_HURT_TIME, {{DEF_ATTACKS}, DEF_MOVEMENTS, true}) {}

void Player::addItem(const std::shared_ptr<Buff> &item) {
    items.push_back(item);
}