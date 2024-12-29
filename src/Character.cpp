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

Character::Character(const std::string&type, int max_health, double hurtTime,
                     Capabilities capabilities) : hurtAnimation(hurtTime), type(type),
                                                  id(nextId++),
                                                  health(max_health, max_health), capabilities(capabilities) {
    onGround = true;
}

Character::Character(const std::string&type, int max_health) : Character(type, max_health, DEF_HURT_TIME, {
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
    return capabilities.getAttack(name);
}

std::shared_ptr<Movement> Character::getMovement(std::string name) const {
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
    auto jump = std::dynamic_pointer_cast<Jump>(capabilities.getMovement("JUMP"));
    jump->reset();
}

bool Character::isLanded() const {
    return onGround;
}

void Character::increaseHealth(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Amount must be positive");
    }
    health.current += amount;
}

void Character::increaseMaxHealth(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Amount must be positive");
    }
    health.max += amount;
}

bool Character::hasJetPack() const {
    return capabilities.getJetPack().getForce() > 0;
}

int Character::attack(std::string attackName) {
    if (!canUse(attackName)) {
        throw std::invalid_argument("This attack cannot be used");
    }
    return capabilities.use(attackName);
}

void Character::move(std::string movementName) {
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

void Character::useJetpack() {
    if (!canUseJetpack()) {
        throw std::invalid_argument("Jetpack cannot be used");
    }
    capabilities.getJetPack().activate();
}

bool Character::canUse(std::string attackName) const {
    if (isBusy()) {
        return false;
    }
    return capabilities.canUse(attackName);
}

bool Character::canMove(std::string movementName) const {
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
    catch (std::invalid_argument&e) {
        return false;
    }
}

void Character::useItem(const std::shared_ptr<Items>&item) {
    // todo
}

bool Character::isBusy() const {
    if (capabilities.hasThisMovement("DASH")) {
        return capabilities.getMovement("DASH")->isUsing() || hurtAnimation.isPlaying(); 
    }
    return hurtAnimation.isPlaying();
}

void Character::hurt(int damage) {
    if (damage < 0) {
        throw std::invalid_argument("Damage must be positive");
    }
    if (health.current - damage <= 0) {
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
    health.current -= damage;
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

void Character::stopMoving(std::string movementName) {
    if (movementName == "JETPACK") {
        capabilities.stop(movementName);
        return;
    }
    capabilities.stop(movementName);
}

void Character::addItem(Item item) {
    if (items.contains(item.getName())) {
        items.at(item.getName()) += 1;
    }
    else {
        items.emplace(item.getName(), 1);
    }
}

void Character::increaseMovementForce(const std::string& movementName, const double amount) {
    capabilities.increaseMovementForce(movementName, amount);
}

void Character::increaseAttackDamage(double amount, std::vector<std::string> attackName) {
    for (auto attack_name : attackName) {
        capabilities.increaseAttackDamage(amount, attack_name);
    }
}

std::vector<std::string> Character::getAllAttackName() {
    return capabilities.getCharacterAttacksName();
}

int Character::getNumberOfItem(int item_id) const {
    return items.at(DefinedItems::getItemName(static_cast<Items>(item_id)));
}
