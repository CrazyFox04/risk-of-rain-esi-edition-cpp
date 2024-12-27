//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Enemies.hpp"
#include "Game.hpp"

Game::Game() : activeLevel(-1) {
    next_level();
}

void Game::add_level(const Level&level) {
    levels.push_back(level);
}

void Game::next_level() {
    auto level = Level(++activeLevel);
    levels.push_back(level.generate());
}

Level Game::getActiveLevel() {
    for (auto level: levels) {
        if (level.getId() == this->activeLevel) {
            return level;
        }
    }
    auto level = Level(-1).generate();
    add_level(level);
    return level;
}

int Game::get_area_guid_current_level(int x, int y) const {
    return levels.at(activeLevel).get_area_guid(x, y);
}

int Game::getPlayerMaxHealth() const {
    return player.getHealth().max;
}

int Game::getPlayerCurrentHealth() const {
    return player.getHealth().current;
}

void Game::takePlayerDamage(int damage) {
    player.hurt(damage);
}

int Game::if_can_spawn_current_level_spawn_at(int areaX, int areaY, int spawdId) {
    if (levels.at(activeLevel).can_spawn_at(areaX, areaY, spawdId)) {
        return levels.at(activeLevel).spawn_at(areaX, areaY, spawdId);
    }
    return -1; // can't spawn
}

std::string Game::getType(int id) const {
    if (player.getId() == id) {
        return player.getType();
    }
    return levels.at(activeLevel).getEnemy(id).getType();
}

int Game::getCharacterSpeed(int id) const {
    if (player.getId() == id) {
        return player.getMovement("RUN").getForce();
    }
    return levels.at(activeLevel).getEnemy(id).getMovement("RUN").getForce();
}

double Game::getCharacterJumpForce(int id) const {
    if (player.getId() == id) {
        return player.getMovement("JUMP").getForce();
    }
    return levels.at(activeLevel).getEnemy(id).getMovement("JUMP").getForce();
}

double Game::getEnemyFollowRange(int id) const {
    return levels.at(activeLevel).getEnemy(id).getFollowRange();
}

double Game::getEnemyAttackRange(int id) const {
    return levels.at(activeLevel).getEnemy(id).getAttackRange();
}

bool Game::canCharacterAttack(int id, std::string attackName) const {
    if (player.getId() == id) {
        return player.canUse(attackName);
    }
    return levels.at(activeLevel).getEnemy(id).canUse(attackName);
}

double Game::getDamage(int id, std::string attackName) const {
    if (player.getId() == id) {
        return player.getAttack(attackName).getDamage();
    }
    return levels.at(activeLevel).getEnemy(id).getAttack(attackName).getDamage();
}

double Game::getChargeTime(int id, std::string attackName) const {
    if (player.getId() == id) {
        return player.getAttack(attackName).getChargeTime();
    }
    return levels.at(activeLevel).getEnemy(id).getAttack(attackName).getChargeTime();
}

double Game::getCharacterHurtTime(int id) const {
    if (player.getId() == id) {
        return player.getHurtAnimation().getDuration();
    }
    return levels.at(activeLevel).getEnemy(id).getHurtAnimation().getDuration();
}

bool Game::isCharacterBusy(int id) {
    if (player.getId() == id) {
        return player.isBusy();
    }
    return levels.at(activeLevel).getEnemy(id).isBusy();
}

int Game::getCharacterHealth(int id) const {
    if (player.getId() == id) {
        return player.getHealth().current;
    }
    return levels.at(activeLevel).getEnemy(id).getHealth().current;
}

int Game::getCharacterMaxHealth(int id) const {
    if (player.getId() == id) {
        return player.getHealth().max;
    }
    return levels.at(activeLevel).getEnemy(id).getHealth().max;
}

double Game::getPlayerDashForce() const {
    return player.getMovement("DASH").getForce();
}

double Game::getJetPackForce() const {
    return player.getJetPack().getForce();
}

double Game::getJetPackMaxTime() const {
    return player.getJetPack().getMaxTime();
}

double Game::getPlayerLandingTime() const {
    return player.getJetPack().getLandAnimationTime();
}

double Game::getPlayerDashTime() const {
    return player.getMovement("DASH").getAnimationTime();
}

double Game::getCharacterAttackTime(int id, std::string attackName) const {
    if (player.getId() == id) {
        return player.getAttack(attackName).getAnimationTime();
    }
    return levels.at(activeLevel).getEnemy(id).getAttack(attackName).getAnimationTime();
}

bool Game::isPlayerDashing() const {
    return player.getMovement("DASH").isUsing();
}

bool Game::isPlayerUsingJetpack() const {
    return player.getJetPack().isUsing();
}

bool Game::canCaracterMove(int id, std::string movementName) const {
    if (player.getId() == id) {
        return player.canMove(movementName);
    }
    return levels.at(activeLevel).getEnemy(id).canMove(movementName);
}

double Game::getCharacterCoolDownAttack(int id, std::string attackName) const {
    if (player.getId() == id) {
        return player.getAttack(attackName).getCooldown();
    }
    return levels.at(activeLevel).getEnemy(id).getAttack(attackName).getCooldown();
}

