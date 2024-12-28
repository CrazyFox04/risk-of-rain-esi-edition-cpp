//
// Created by Enzo Renard on 05/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "GameController.hpp"

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

std::string GameController::getType(int id) const {
    return game_.getType(id);
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

bool GameController::canCharacterAttack(int id, std::string attack_name) const {
    return game_.canCharacterAttack(id, attack_name);
}

int GameController::getDamage(int id, std::string attack_name) const {
    return game_.getDamage(id, attack_name);
}

double GameController::getChargeTime(int id, std::string attack_name) const {
    return game_.getChargeTime(id, attack_name);
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

double GameController::getCharacterAttackTime(int id, std::string attack_name) const {
    return game_.getCharacterAttackTime(id, attack_name);
}

bool GameController::isPlayerDashing() const {
    return game_.isPlayerDashing();
}

bool GameController::isPlayerUsingJetpack() const {
    return game_.isPlayerUsingJetpack();
}

bool GameController::canCharacterMove(int id, std::string movement_name) const {
    return game_.canCharacterMove(id, movement_name);
}

double GameController::getCharacterCoolDownAttackTime(int id, std::string attack_name) const {
    return game_.getCharacterCoolDownAttack(id, attack_name);
}

bool GameController::isAValidId(int id) const {
    return game_.isAValidId(id);
}

void GameController::attack(int id, std::string attack_name, int targetId) {
    game_.attack(id, attack_name, targetId);
}

void GameController::move(int id, std::string movement_name) {
    game_.move(id, movement_name);
}

int GameController::getPlayerId() const {
    return game_.getPlayerId();
}

bool GameController::isCharacterBusy(int id) const {
    return game_.isCharacterBusy(id);
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

const char* getType(const GameController* game_controller, int id) {
    return game_controller->getType(id).c_str();
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

bool canCharacterAttack_ATTACK1(const GameController* game_controller, int id) {
    return game_controller->canCharacterAttack(id, "ATTACK1");
}

bool canCharacterAttack_ATTACK2(const GameController* game_controller, int id) {
    return game_controller->canCharacterAttack(id, "ATTACK2");
}

bool canCharacterAttack_ATTACK3(const GameController* game_controller, int id) {
    return game_controller->canCharacterAttack(id, "ATTACK3");
}

bool canCharacterAttack_ATTACK4(const GameController* game_controller, int id) {
    return game_controller->canCharacterAttack(id, "ATTACK4");
}

bool canCharacterAttack_ATTACK5(const GameController* game_controller, int id) {
    return game_controller->canCharacterAttack(id, "ATTACK5");
}

bool canCharacterAttack_ATTACK_SPECTRUM(const GameController* game_controller, int id) {
    return game_controller->canCharacterAttack(id, "ATTACK_SPECTRUM");
}

bool canCharacterAttack_ATTACK_MONSTER(const GameController* game_controller, int id) {
    return game_controller->canCharacterAttack(id, "ATTACK_MONSTER");
}

bool canCharacterAttack_ATTACK_DROID(const GameController* game_controller, int id) {
    return game_controller->canCharacterAttack(id, "ATTACK_DROID");
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

// TODO Check if this is correct
double getCharacterAttackTime(const GameController* game_controller, int id, int attackIndex) {
    std::string attackName = DefinedAttacks::getAttackName(attackIndex);
    return game_controller->getCharacterAttackTime(id, attackName);
}

bool isPlayerDashing(const GameController* game_controller) {
    return game_controller->isPlayerDashing();
}

bool isPlayerUsingJetpack(const GameController* game_controller) {
    return game_controller->isPlayerUsingJetpack();
}

bool canCharacterMove_RUN(const GameController* game_controller, int id) {
    return game_controller->canCharacterMove(id, "RUN");
}

bool canCharacterMove_JUMP(const GameController* game_controller, int id) {
    return game_controller->canCharacterMove(id, "JUMP");
}

bool canCharacterMove_DASH(const GameController* game_controller, int id) {
    return game_controller->canCharacterMove(id, "DASH");
}
// TODO Check if this is correct
double getCharacterCoolDownAttackTime(const GameController* game_controller, int id, int attackIndex) {
    std::string attackName = DefinedAttacks::getAttackName(attackIndex);
    return game_controller->getCharacterCoolDownAttackTime(id, attackName);
}

bool isAValidId(const GameController* game_controller, int id) {
    return game_controller->isAValidId(id);
}

int getPlayerId(const GameController* game_controller) {
    return game_controller->getPlayerId();
}

void attack_ATTACK1(GameController* game_controller, int id, int targetId) {
    game_controller->attack(id, "ATTACK1", targetId);
}

void attack_ATTACK2(GameController* game_controller, int id, int targetId) {
    game_controller->attack(id, "ATTACK2", targetId);
}

void attack_ATTACK3(GameController* game_controller, int id, int targetId) {
    game_controller->attack(id, "ATTACK3", targetId);
}

void attack_ATTACK4(GameController* game_controller, int id, int targetId) {
    game_controller->attack(id, "ATTACK4", targetId);
}

void attack_ATTACK5(GameController* game_controller, int id, int targetId) {
    game_controller->attack(id, "ATTACK5", targetId);
}

void attack_ATTACK_SPECTRUM(GameController* game_controller, int id, int targetId) {
    game_controller->attack(id, "ATTACK_SPECTRUM", targetId);
}

void attack_ATTACK_MONSTER(GameController* game_controller, int id, int targetId) {
    game_controller->attack(id, "ATTACK_MONSTER", targetId);
}

void attack_ATTACK_DROID(GameController* game_controller, int id, int targetId) {
    game_controller->attack(id, "ATTACK_DROID", targetId);
}

void move_RUN(GameController* game_controller, int id) {
    game_controller->move(id, "RUN");
}

void move_JUMP(GameController* game_controller, int id) {
    game_controller->move(id, "JUMP");
}

void move_DASH(GameController* game_controller, int id) {
    game_controller->move(id, "DASH");
}

// TODO Check if this is correct
double getAttackDamage(const GameController* gameController, int id, int attackIndex) {
    std::string attackName = DefinedAttacks::getAttackName(attackIndex);
    return gameController->getDamage(id, attackName);
}
// TODO Check if this is correct
double getAttackChargeTime(const GameController* gameController, int id, int attackIndex) {
    std::string attackName = DefinedAttacks::getAttackName(attackIndex);
    return gameController->getChargeTime(id, attackName);
}

// TODO Check if this is correct
bool canCharacterAttack(const GameController* game_controller, int id, int attackIndex) {
    std::string attackName = DefinedAttacks::getAttackName(attackIndex);
    return game_controller->canCharacterAttack(id, attackName);
}

double getCharacterHurtTime(const GameController* game_controller, int id) {
    return game_controller->getCharacterHurtTime(id);
}

bool isCharacterBusy(GameController* game_controller, int id) {
    return game_controller->isCharacterBusy(id);
}
