//
// Created by Enzo Renard on 19/11/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "Enemies.hpp"
#include "Game.hpp"

#include "GameOverException.hpp"
Game::Game(const int primaryAttack, const int secondaryAttack, const int tertiaryAttack) : activeLevel(-1), player(primaryAttack, secondaryAttack, tertiaryAttack), over(false) {
    next_level();
}


double Game::getCharacterSpeed(const int id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.getMovement("RUN")->getForce();
    }
    return levels.at(activeLevel).getEnemy(id).getMovement("RUN")->getForce();
}

double Game::getCharacterJumpForce(const int id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.getMovement("JUMP")->getForce();
    }
    return levels.at(activeLevel).getEnemy(id).getMovement("JUMP")->getForce();
}

double Game::getEnemyFollowRange(const int id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    return levels.at(activeLevel).getEnemy(id).getFollowRange();
}

double Game::getEnemyAttackRange(const int id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    return levels.at(activeLevel).getEnemy(id).getAttackRange();
}

int Game::getDamage(const int id, const std::string&attackName) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (!isAValidAttackName(attackName)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.getAttack(attackName).getDamage();
    }
    return levels.at(activeLevel).getEnemy(id).getAttack(attackName).getDamage();
}

double Game::getChargeTime(const int id, const std::string&attackName) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (!isAValidAttackName(attackName)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.getAttack(attackName).getChargeTime();
    }
    return levels.at(activeLevel).getEnemy(id).getAttack(attackName).getChargeTime();
}

double Game::getCharacterHurtTime(const int id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.getHurtAnimation().getDuration();
    }
    return levels.at(activeLevel).getEnemy(id).getHurtAnimation().getDuration();
}

int Game::getCharacterHealth(const int id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.getHealth().current;
    }
    return levels.at(activeLevel).getEnemy(id).getHealth().current;
}

int Game::getCharacterMaxHealth(const int id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.getHealth().max;
    }
    return levels.at(activeLevel).getEnemy(id).getHealth().max;
}

double Game::getCharacterAttackTime(const int id, const std::string& attackName) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (!isAValidAttackName(attackName)) {
        return -1;
    }
    try {
        if (player.getId() == id) {
            return player.getAttack(attackName).getAnimationTime();
        }
        return levels.at(activeLevel).getEnemy(id).getAttack(attackName).getAnimationTime();
    }
    catch (std::invalid_argument&) {
        return -1;
    }
}

double Game::getCharacterCoolDownAttack(const int id, const std::string& attackName) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (!isAValidAttackName(attackName)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.getAttack(attackName).getCooldown();
    }
    return levels.at(activeLevel).getEnemy(id).getAttack(attackName).getCooldown();
}

Game::Game() : Game(0,1,2) {}

void Game::add_level(const Level&level) {
    levels.push_back(level);
}

void Game::next_level() {
    auto level = Level(++activeLevel);
    levels.push_back(level.generate());
    if (activeLevel != 0) {
        levels.at(activeLevel - 1).unload();
    }
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
    if (!levels.at(activeLevel).isValidCoordinates(x, y)) {
        return -1;
    }
    if (!levels.at(activeLevel).isLoaded()) {
        return -1;
    }
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

int Game::ifCanSpawnCurrentLevelSpawnAt(const int areaX, const int areaY, const int spawnId) {
    if (levels.at(activeLevel).can_spawn_at(areaX, areaY, spawnId)) {
        return levels.at(activeLevel).spawn_at(areaX, areaY, spawnId, getDifficulty());
    }
    return -1; // can't spawn
}

int Game::getCharacterType(const int id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (player.getId() == id) {
        return 0;
    }
    try {
        return DefinedEnemies::getId(levels.at(activeLevel).getEnemy(id).getType()) + 1;
    }
    catch (std::invalid_argument&) {
        return -1;
    }
}

bool Game::canCharacterAttack(const int id, const std::string&attackName) const {
    if (!isAValidId(id)) {
        return false;
    }
    if (!isAValidAttackName(attackName)) {
        return false;
    }
    if (player.getId() == id) {
        return player.canUse(attackName);
    }
    return levels.at(activeLevel).getEnemy(id).canUse(attackName);
}

bool Game::isCharacterBusy(const int id) const {
    if (!isAValidId(id)) {
        return false;
    }
    if (player.getId() == id) {
        return player.isBusy();
    }
    return levels.at(activeLevel).getEnemy(id).isBusy();
}

double Game::getPlayerDashForce() const {
    return player.getMovement("DASH")->getForce();
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
    return player.getMovement("DASH")->getAnimationTime();
}

bool Game::isPlayerDashing() const {
    return player.getMovement("DASH")->isUsing();
}

bool Game::isPlayerUsingJetpack() const {
    return player.getJetPack().isUsing();
}

bool Game::canCharacterMove(const int id, const std::string&movementName) const {
    if (!isAValidId(id)) {
        return false;
    }
    if (!isAValidMovementName(movementName)) {
        return false;
    }
    if (player.getId() == id) {
        return player.canMove(movementName);
    }
    return levels.at(activeLevel).getEnemy(id).canMove(movementName);
}

bool Game::isAValidId(const int id) const {
    if (player.getId() == id) {
        return true;
    }
    return levels.at(activeLevel).isAValidEnemyId(id);
}

int Game::getPlayerId() const {
    return player.getId();
}

std::tuple<std::tuple<int, int>, int> Game::getExistingSpawn() const {
    return levels.at(activeLevel).getAnExistingSpawn();
}

std::set<std::string> Game::getCharacterAttacksName() {
    return DefinedAttacks::getCharacterAttacksName();
}

bool Game::isAValidAttackName(const std::string&attackName) {
    return DefinedAttacks::isAValidAttackName(attackName);
}

bool Game::isAValidMovementName(const std::string&string) {
    return DefinedMovements::isAValidMovementName(string);
}

void Game::attack(const int id, const std::string& attackName, const int targetId) {
    if (!isAValidId(id)) {
        throw std::invalid_argument("Invalid id");
    }
    if (targetId == -1) {
        if (player.getId() == id) {
            player.attack(attackName);
            return;
        }
        levels.at(activeLevel).attackEnemy(id, attackName);
        return;
    }
    if (!isAValidId(targetId)) {
        throw std::invalid_argument("Invalid target id");
    }
    if (!isAValidAttackName(attackName)) {
        throw std::invalid_argument("Invalid attack name");
    }
    if (player.getId() == id) {
        if (player.canUse(attackName)) {
            const int damage = player.attack(attackName);
            levels.at(activeLevel).hurtEnemy(targetId, damage);
        }
    }
    else {
        if (levels.at(activeLevel).getEnemy(id).canUse(attackName)) {
            const int damage = levels.at(activeLevel).attackEnemy(id, attackName);
            try {
                player.hurt(damage);
            } catch (GameOverException&) {
                over = true;
            }
        }
    }
}

void Game::move(const int id, const std::string&movementName) {
    if (!isAValidId(id)) {
        throw std::invalid_argument("Invalid id");
    }
    if (!isAValidMovementName(movementName)) {
        throw std::invalid_argument("Invalid movement name");
    }
    if (player.getId() == id) {
        if (player.canMove(movementName)) {
            player.move(movementName);
        }
    }
    else {
        if (levels.at(activeLevel).getEnemy(id).canMove(movementName)) {
            levels.at(activeLevel).getEnemy(id).move(movementName);
        }
    }
}

bool Game::isCharacterOnGround(const int id) const {
    if (!isAValidId(id)) {
        return false;
    }
    if (player.getId() == id) {
        return player.isLanded();
    }
    return levels.at(activeLevel).getEnemy(id).isLanded();
}

void Game::landCharacter(const int id) {
    if (isAValidId(id)) {
        if (player.getId() == id) {
            player.land();
        }
        else {
            levels.at(activeLevel).getEnemy(id).land();
        }
    }
}

void Game::takeOffCharacter(const int id) {
    if (isAValidId(id)) {
        if (player.getId() == id) {
            player.takeOff();
        }
        else {
            levels.at(activeLevel).getEnemy(id).takeOff();
        }
    }
}

int Game::getMovingType(const int id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.isMoving();
    }
    return levels.at(activeLevel).getEnemy(id).isMoving();
}

int Game::isMoving(const int id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.isMoving();
    }
    return levels.at(activeLevel).getEnemy(id).isMoving();
}

void Game::stopMoving(const int id, const std::string& type) {
    if (!isAValidId(id)) {
        return;
    }
    if (player.getId() == id) {
        player.stopMoving(type);
    }
    else {
        levels.at(activeLevel).getEnemy(id).stopMoving(type);
    }
}

int Game::activateBossSpawn(const int area_x, const int area_y, const int area_id) {
    if (levels.at(activeLevel).canActivateBossSpawn(area_x, area_y)) {
        return levels.at(activeLevel).activateBossSpawn(area_x, area_y, area_id);
    }
    return -1;
}

bool Game::canActivateBossSpawn(const int areaX, const int areaY, const int spawnId) {
    return levels.at(activeLevel).canActivateBossSpawn(areaX, areaY);
}

double Game::getCharacterCoolDownMovementTime(const int id, const std::string&string) const {
    if (!isAValidId(id)) {
        throw std::invalid_argument("Invalid id");
    }
    if (!isAValidMovementName(string)) {
        throw std::invalid_argument("Invalid movement name");
    }
    if (player.getId() == id) {
        if (string == "JETPACK") {
            return player.getJetPack().getCoolDown();
        }
        return player.getMovement(string)->getCooldown();
    }
    if (string == "JETPACK") {
        return levels.at(activeLevel).getEnemy(id).getJetPack().getCoolDown();
    }
    return levels.at(activeLevel).getEnemy(id).getMovement(string)->getCooldown();
}

int Game::openChest(const int area_x, const int area_y, const int chest_id) {
    Item item = levels.at(activeLevel).openChest(area_x, area_y, chest_id);
    switch (DefinedItems::getId(item.getName())) {
        case HEALTH_POTION:
            // nop
            break;
        case HEALTH_BOOST:
            player.increaseMaxHealth(item.use());
            break;
        case SPEED_BOOST:
            player.increaseMovementForce("RUN", item.use());
            break;
        case DAMAGE_BOOST:
            player.increaseAttackDamage(item.use(), player.getAllAttackName());
            break;
        case EXTRA_JUMP:
            player.increaseMovementForce("JUMP", item.use());
            break;
        case TEDDY_BEAR:
            // nop
            break;
        default:
            throw std::invalid_argument("Invalid item");
    }
    player.addItem(item);
    return DefinedItems::getId(item.getName());
}

bool Game::isChestEmpty(const int area_x, const int area_y, const int chest_id) const {
    return levels.at(activeLevel).isChestEmpty(area_x, area_y, chest_id);
}

int Game::getNumberOfItem(const int id, const int item_id) const {
    if (!isAValidId(id)) {
        return -1;
    }
    if (player.getId() == id) {
        return player.getNumberOfItem(item_id);
    }
    return levels.at(activeLevel).getEnemy(id).getNumberOfItem(item_id);
}

void Game::updateGameDifficulty() {
    if (const auto now = std::chrono::steady_clock::now(); std::chrono::steady_clock::now() - timeSinceDifficultyUpdate > DIFFICULTY_INTERVAL) {
        increaseDifficulty(0.1);
        timeSinceDifficultyUpdate = now;
    }
}

void Game::increaseDifficulty(const double increment) {
    if (increment < 0) {
        throw std::invalid_argument("Increment must be positive");
    }
    difficulty += increment;
}

double Game::getDifficulty() const {
    return difficulty;
}

bool Game::isOver() const {
    return over;
}

int Game::getPrimaryPlayerAttack() const {
    return DefinedAttacks::getAttackValue(player.getAttackAt(0).getName());
}

int Game::getSecondaryPlayerAttack() const {
    return DefinedAttacks::getAttackValue(player.getAttackAt(1).getName());
}

int Game::getTertiaryPlayerAttack() const {
    return DefinedAttacks::getAttackValue(player.getAttackAt(2).getName());
}

bool Game::canEndCurrentLevel(const int bossId) const {
    if (!isAValidId(bossId)) {
        return false;
    }
    const auto boss = levels.at(activeLevel).getEnemy(bossId);
    if (!boss.getIsBoss()) {
        return false;
    }
    return boss.getHealth().current == 0;
}

void Game::nextLevel(const int bossId) {
    if (!canEndCurrentLevel(bossId)) {
        throw std::runtime_error("Can't end the level");
    }
    next_level();
}

void Game::useHealthPotionIfAvailable() {
    if (player.getNumberOfItem(0) > 0) {
        player.useHealthPotion();
    }
}

