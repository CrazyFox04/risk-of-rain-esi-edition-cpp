//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Character.hpp"

#include <Jump.hpp>
#include <Run.hpp>

Character::Character(int max_health, double hurtTime, Capabilities capabilities) : id(nextId++),
    health(max_health, max_health), capabilities(capabilities) {
    onGround = true;
}

Character::Character(int max_health) : Character(max_health, DEF_HURT_TIME, {
                                                     {},
                                                     {
                                                         std::make_shared<Run>(DEF_RUN_FORCE),
                                                         std::make_shared<Jump>(DEF_JUMP_FORCE, 1)
                                                     },
                                                     false
                                                 }) {
}

Health Character::getHealth() const {
    return health;
}

Attack Character::getAttack(std::string name) const {
    return capabilities.getAttack(name);
}

Movement Character::getMovement(std::string name) const {
    return capabilities.getMovement(name);
}

JetPack Character::getJetPack() const {
    return capabilities.getJetPack();
}

int Character::getId() const {
    return id;
}

const std::vector<std::shared_ptr<Buff>>& Character::getItems() const {
    return items;
}

void Character::land() {
    onGround = true;
}

bool Character::isLanded() const {
    return onGround;
}

void Character::increaseHealth(int amount) {
    health.current += amount;
}

void Character::increaseMaxHealth(int amount) {
    health.max += amount;
}