//
// Created by Enzo Renard on 05/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "GameController.hpp"
#include "Movements.hpp"

int GameController::getPlayerMaxHealth() const {
    return game_.getPlayerMaxHealth();
}

int GameController::getPlayerCurrentHealth() const {
    return game_.getPlayerCurrentHealth();
}

void GameController::takePlayerDamage(int damage) {
    game_.takePlayerDamage(damage);
}

int GameController::getAreaGuidCurrentLevel(int x, int y) const {
    return game_.get_area_guid_current_level(x, y);
}

int GameController::ifCanSpawnCurrentLevelSpawnAt(int x, int y, int id) {
    return game_.ifCanSpawnCurrentLevelSpawnAt(x, y, id);
}

int GameController::getCharacterType(int id) const {
    return game_.getCharacterType(id);
}

double GameController::getCharacterSpeed(int id) const {
    return game_.getCharacterSpeed(id);
}

double GameController::getCharacterJumpForce(int id) const {
    return game_.getCharacterJumpForce(id);
}

double GameController::getEnemyFollowRange(int id) const {
    return game_.getEnemyFollowRange(id);
}

double GameController::getEnemyAttackRange(int id) const {
    return game_.getEnemyAttackRange(id);
}

bool GameController::canCharacterAttack(int id, int attackIndex) const {
    return game_.canCharacterAttack(id, getAttackName(attackIndex));
}

int GameController::getDamage(int id, int attackIndex) const {
    return game_.getDamage(id, getAttackName(attackIndex));
}

double GameController::getChargeTime(int id, int attackIndex) const {
    return game_.getChargeTime(id, getAttackName(attackIndex));
}

double GameController::getCharacterHurtTime(int id) const {
    return game_.getCharacterHurtTime(id);
}

int GameController::getCharacterHealth(int id) const {
    return game_.getCharacterHealth(id);
}

int GameController::getCharacterMaxHealth(int id) const {
    return game_.getCharacterMaxHealth(id);
}

double GameController::getPlayerDashForce() const {
    return game_.getPlayerDashForce();
}

double GameController::getJetPackForce() const {
    return game_.getJetPackForce();
}

double GameController::getJetPackMaxTime() const {
    return game_.getJetPackMaxTime();
}

double GameController::getPlayerLandingTime() const {
    return game_.getPlayerLandingTime();
}

double GameController::getPlayerDashTime() const {
    return game_.getPlayerDashTime();
}

double GameController::getCharacterAttackTime(int id, int attackIndex) const {
    return game_.getCharacterAttackTime(id, getAttackName(attackIndex));
}

bool GameController::isPlayerDashing() const {
    return game_.isPlayerDashing();
}

bool GameController::isPlayerUsingJetpack() const {
    return game_.isPlayerUsingJetpack();
}

bool GameController::canCharacterMove(int id, int movementIndex) const {
    return game_.canCharacterMove(id, getMovementName(movementIndex));
}

double GameController::getCharacterCoolDownAttackTime(int id, int attackIndex) const {
    return game_.getCharacterCoolDownAttack(id, getAttackName(attackIndex));
}

bool GameController::isAValidId(int id) const {
    return game_.isAValidId(id);
}

void GameController::attack(int id, int attackIndex, int targetId) {
    game_.attack(id, getAttackName(attackIndex), targetId);
}

void GameController::move(int id, int attackIndex) {
    game_.move(id, getMovementName(attackIndex));
}

int GameController::getPlayerId() const {
    return game_.getPlayerId();
}

bool GameController::isCharacterBusy(int id) const {
    return game_.isCharacterBusy(id);
}

bool GameController::isCharacterOnGround(int id) const {
    return game_.isCharacterOnGround(id);
}

void GameController::landCharacter(int id) {
    game_.landCharacter(id);
}

void GameController::takeOffCharacter(int id) {
    game_.takeOffCharacter(id);
}

GameController* newGame() {
    return new GameController();
}

void destroyGame(const GameController* game_controller) {
    delete game_controller;
}

int getPlayerMaxHealth(const GameController* game_controller) {
    return game_controller->getPlayerMaxHealth();
}

int getPlayerCurrentHealth(GameController* game_controller) {
    return game_controller->getPlayerCurrentHealth();
}

void takePlayerDamage(GameController* game_controller, int health) {
    game_controller->takePlayerDamage(health);
}

int getAreaGuidCurrentLevel(const GameController* game_controller, int x, int y) {
    return game_controller->getAreaGuidCurrentLevel(x, y);
}

int ifCanSpawnCurrentLevelSpawnAt(GameController* game_controller, int x, int y, int id) {
    return game_controller->ifCanSpawnCurrentLevelSpawnAt(x, y, id);
}

int getCharacterType(const GameController* game_controller, int id) {
    return game_controller->getCharacterType(id);
}

double getCharacterSpeed(const GameController* game_controller, int id) {
    return game_controller->getCharacterSpeed(id);
}

double getCharacterJumpForce(const GameController* game_controller, int id) {
    return game_controller->getCharacterJumpForce(id);
}

double getEnemyFollowRange(const GameController* game_controller, int id) {
    return game_controller->getEnemyFollowRange(id);
}

double getEnemyAttackRange(const GameController* game_controller, int id) {
    return game_controller->getEnemyAttackRange(id);
}

int getCharacterHealth(const GameController* game_controller, int id) {
    return game_controller->getCharacterHealth(id);
}

int getCharacterMaxHealth(const GameController* game_controller, int id) {
    return game_controller->getCharacterMaxHealth(id);
}

double getPlayerDashForce(const GameController* game_controller) {
    return game_controller->getPlayerDashForce();
}

double getJetPackForce(const GameController* game_controller) {
    return game_controller->getJetPackForce();
}

double getJetPackMaxTime(const GameController* game_controller) {
    return game_controller->getJetPackMaxTime();
}

double getPlayerLandingTime(const GameController* game_controller) {
    return game_controller->getPlayerLandingTime();
}

double getPlayerDashTime(const GameController* game_controller) {
    return game_controller->getPlayerDashTime();
}

double getCharacterAttackTime(const GameController* game_controller, int id, int attackIndex) {
    return game_controller->getCharacterAttackTime(id, attackIndex);
}

bool isPlayerDashing(const GameController* game_controller) {
    return game_controller->isPlayerDashing();
}

bool isPlayerUsingJetpack(const GameController* game_controller) {
    return game_controller->isPlayerUsingJetpack();
}

bool canCharacterMove(const GameController* game_controller, int id, int attackIndex) {
    return game_controller->canCharacterMove(id, attackIndex);
}

double getCharacterCoolDownAttackTime(const GameController* game_controller, int id, int attackIndex) {
    return game_controller->getCharacterCoolDownAttackTime(id, attackIndex);
}

bool isAValidId(const GameController* game_controller, int id) {
    return game_controller->isAValidId(id);
}

int getPlayerId(const GameController* game_controller) {
    return game_controller->getPlayerId();
}

void attack(GameController* game_controller, int id, int attackIndex, int targetId) {
    game_controller->attack(id, attackIndex, targetId);
}

void move(GameController* game_controller, int id, int attackIndex) {
    game_controller->move(id, attackIndex);
}

double getAttackDamage(const GameController* gameController, int id, int attackIndex) {
    return gameController->getDamage(id, attackIndex);
}

double getAttackChargeTime(const GameController* gameController, int id, int attackIndex) {
    return gameController->getChargeTime(id, attackIndex);
}

bool canCharacterAttack(const GameController* game_controller, int id, int attackIndex) {
    return game_controller->canCharacterAttack(id, attackIndex);
}

double getCharacterHurtTime(const GameController* game_controller, int id) {
    return game_controller->getCharacterHurtTime(id);
}

bool isCharacterBusy(GameController* game_controller, int id) {
    return game_controller->isCharacterBusy(id);
}

std::string GameController::getAttackName(int attackIndex) {
    try {
        return DefinedAttacks::getAttackName(attackIndex);
    }
    catch (std::out_of_range&e) {
        return {};
    }
}

std::string GameController::getMovementName(int movementIndex) {
    try {
        return DefinedMovements::getMovementName(movementIndex);
    }
    catch (std::out_of_range&e) {
        return {};
    }
}

bool isCharacterOnGround(const GameController* game_controller, int id) {
    return game_controller->isCharacterOnGround(id);
}

void landCharacter(GameController* game_controller, int id) {
    game_controller->landCharacter(id);
}

void takeOffCharacter(GameController* game_controller, int id) {
    game_controller->takeOffCharacter(id);
}
