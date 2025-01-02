//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Character.hpp"

#include "GameOverException.hpp"
#include <random>

#include "Items.hpp"
#include "Item.hpp"
#include "Climb.hpp"
#include "Dash.hpp"

#include "Jump.hpp"
#include "Run.hpp"
#include <utility>

int Character::nextId = 0;

Character::Character(std::string type, const int max_health, const double hurtTime,
                     Capabilities capabilities) : type(std::move(type)), id(nextId++),
                                                  health(max_health, max_health),
                                                  capabilities(std::move(capabilities)), onGround(true), hurtAnimation(hurtTime) {
}

Character::Character(const std::string&type, const int max_health) : Character(type, max_health, DEF_HURT_TIME, {
                                                                             {},
                                                                             {
                                                                                 std::make_shared<Run>(DEF_RUN_FORCE),
                                                                                 std::make_shared<Jump>(
                                                                                     DEF_JUMP_FORCE, 1)
                                                                             },
                                                                             false
                                                                         }) {
}

Health Character::getHealth() const {
    return health;
}

Attack Character::getAttack(std::string name) const {
    return capabilities.getCopyAttack(name);
}

std::shared_ptr<Movement> Character::getMovement(const std::string&name) const {
    return capabilities.getMovement(name);
}

JetPack Character::getJetPack() const {
    return capabilities.getJetPack();
}

int Character::getId() const {
    return id;
}

void Character::land() {
    onGround = true;
    const auto jump = std::dynamic_pointer_cast<Jump>(capabilities.getMovement("JUMP"));
    jump->reset();
}

bool Character::isLanded() const {
    return onGround;
}

void Character::increaseHealth(const int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Amount must be positive");
    }
    if (health.current + amount >= health.max) {
        health.current = health.max;
        return;
    }
    health.current += amount;
}

void Character::increaseMaxHealth(const int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Amount must be positive");
    }
    health.max += amount;
    health.current = health.max;
}

bool Character::hasJetPack() const {
    return capabilities.getJetPack().getForce() > 0;
}

int Character::attack(const std::string& attackName) {
    if (!canUse(attackName)) {
        throw std::invalid_argument("This attack cannot be used");
    }
    return capabilities.use(attackName);
}

void Character::move(const std::string& movementName) {
    if (!canMove(movementName)) {
        throw std::invalid_argument("This movement cannot be used");
    }
    capabilities.use(movementName);
}

bool Character::canUseJetpack() const {
    if (!hasJetPack()) {
        return false;
    }
    return capabilities.getJetPack().canActivate();
}

void Character::useJetpack() const {
    if (!canUseJetpack()) {
        throw std::invalid_argument("Jetpack cannot be used");
    }
    capabilities.getJetPack().activate();
}

bool Character::canUse(const std::string&attackName) const {
    if (isBusy()) {
        return false;
    }
    return capabilities.canUse(attackName);
}

bool Character::canMove(const std::string& movementName) const {
    if (isBusy()) {
        return false;
    }
    try {
        if (movementName == "JETPACK") {
            return canUseJetpack();
        }
        if (movementName == "RUN") {
            const std::shared_ptr<Run> run = std::dynamic_pointer_cast<Run>(capabilities.getMovement(movementName));
            return run->canUse();
        }
        if (movementName == "JUMP") {
            const std::shared_ptr<Jump> jump = std::dynamic_pointer_cast<Jump>(capabilities.getMovement(movementName));
            return jump->canUse();
        }
        if (movementName == "DASH") {
            const std::shared_ptr<Dash> dash = std::dynamic_pointer_cast<Dash>(capabilities.getMovement(movementName));
            return dash->canUse();
        }
        if (movementName == "CLIMB") {
            const std::shared_ptr<Climb> climb = std::dynamic_pointer_cast<Climb>(
                capabilities.getMovement(movementName));
            return climb->canUse();
        }
    }
    catch (std::invalid_argument&) {
        return false;
    }
    return false;
}

bool Character::isBusy() const {
    if (capabilities.hasThisMovement("DASH")) {
        return capabilities.getMovement("DASH")->isUsing() || hurtAnimation.isPlaying(); 
    }
    return hurtAnimation.isPlaying();
}

void Character::hurt(const int damage) {
    if (damage < 0) {
        throw std::invalid_argument("Damage must be positive");
    }
    if (health.current - damage <= 0) {
        health.current = 0;
        die();
    } else {
        health.current -= damage; 
    }
    if (!hurtAnimation.isPlaying()) {
        hurtAnimation.start();
    }
}

std::string Character::getType() const {
    return type;
}

Animation Character::getHurtAnimation() const {
    return hurtAnimation;
}

void Character::takeOff() {
    onGround = false;
}

int Character::isMoving() const {
    return capabilities.isMoving();
}

void Character::stopMoving(const std::string& movementName) {
    if (movementName == "JETPACK") {
        capabilities.stop(movementName);
        return;
    }
    capabilities.stop(movementName);
}

void Character::addItem(const Item& item) {
    if (items.contains(item.getName())) {
        items.at(item.getName()) += 1;
    }
    else {
        items.emplace(item.getName(), 1);
    }
}

void Character::increaseMovementForce(const std::string& movementName, const double amount) {
    if (movementName == "JUMP") {
        const std::shared_ptr<Jump> jump = std::dynamic_pointer_cast<Jump>(capabilities.getMovement(movementName));
        jump->increaseForce(amount);
        return;
    }
    capabilities.increaseMovementForce(movementName, amount);
}

void Character::increaseAttackDamage(const double amount, const std::vector<std::string>& attackName) {
    for (auto attack_name : attackName) {
        capabilities.increaseAttackDamage(amount, attack_name);
    }
}

std::vector<std::string> Character::getAllAttackName() const {
    return capabilities.getCharacterAttacksName();
}

int Character::getNumberOfItem(int item_id) const {
    const auto item = DefinedItems::getItemName(static_cast<Items>(item_id));
    if (item.empty()) {
        return 0;
    }
    if (!items.contains(item)) {
        return 0;
    }
    return items.at(item);
}

Attack Character::getAttackAt(const int attackIndex) const {
    return capabilities.getAttackAt(attackIndex);
}
