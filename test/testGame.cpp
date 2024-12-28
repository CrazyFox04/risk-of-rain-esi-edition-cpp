//
// Created by Enzo Renard on 25/12/2024.
//
#include <gtest/gtest.h>
#include "Game.hpp"
#include <tuple>
#include "Level.hpp"

TEST(GameTest, DefaultConstructorInitializesActiveLevelToNegativeOne) {
    Game game;
    EXPECT_EQ(game.getActiveLevel().getId(), 0);
}

TEST(GameTest, GetAreaGuidCurrentLevelReturnsCorrectGuid) {
    Game game;
    int x = 0, y = 0;
    EXPECT_NO_THROW(game.get_area_guid_current_level(x, y));
    EXPECT_NO_THROW(game.get_area_guid_current_level(98989908, 9889898));
}

TEST(GameTest, GetPlayerMaxHealthReturnsCorrectValue) {
    Game game;
    EXPECT_EQ(Player::DEF_MAX_HEALTH, game.getPlayerMaxHealth());
}

TEST(GameTest, GetPlayerCurrentHealthReturnsCorrectValue) {
    Game game;
    EXPECT_EQ(Player::DEF_MAX_HEALTH, game.getPlayerCurrentHealth());
    game.takePlayerDamage(10);
    EXPECT_EQ(Player::DEF_MAX_HEALTH - 10, game.getPlayerCurrentHealth());
}

TEST(GameTest, TakePlayerDamageDecreasesCurrentHealth) {
    Game game;
    int initialHealth = game.getPlayerCurrentHealth();
    game.takePlayerDamage(10);
    EXPECT_EQ(game.getPlayerCurrentHealth(), initialHealth - 10);
}

TEST(GameTest, IfCanSpawnCurrentLevelSpawnAtReturnsTrueWhenSpawned) {
    Game game = Game();
    std::tuple<std::tuple<int, int>, int> existingSpawn = game.getExistingSpawn();
    int areaX = std::get<0>(std::get<0>(existingSpawn));
    int areaY = std::get<1>(std::get<0>(existingSpawn));
    int spawnId = std::get<1>(existingSpawn);
    EXPECT_NE(-1, game.ifCanSpawnCurrentLevelSpawnAt(areaX, areaY, spawnId));
    EXPECT_EQ(-1, game.ifCanSpawnCurrentLevelSpawnAt(areaX, areaY, spawnId));
}

TEST(GameTest, IfCanSpawnCurrentLevelSpawnAtReturnsFalseWhenNotSpawned) {
    Game game = Game();
    std::tuple<std::tuple<int, int>, int> existingSpawn = game.getExistingSpawn();
    int areaX = std::get<0>(std::get<0>(existingSpawn));
    int areaY = std::get<1>(std::get<0>(existingSpawn));
    int spawnId = std::get<1>(existingSpawn);
    EXPECT_NE(-1, game.ifCanSpawnCurrentLevelSpawnAt(areaX, areaY, spawnId));
    EXPECT_EQ(-1, game.ifCanSpawnCurrentLevelSpawnAt(areaX, areaY, spawnId));
}

TEST(GameTest, IfSpawnReturnId_isInThisLevel) {
    Game game = Game();
    std::tuple<std::tuple<int, int>, int> existingSpawn = game.getExistingSpawn();
    int areaX = std::get<0>(std::get<0>(existingSpawn));
    int areaY = std::get<1>(std::get<0>(existingSpawn));
    int spawnId = std::get<1>(existingSpawn);
    int id = game.ifCanSpawnCurrentLevelSpawnAt(areaX, areaY, spawnId);
    EXPECT_NO_THROW(game.getType(98765678987));
    EXPECT_EQ("", game.getType(98765678987));
    EXPECT_NO_THROW(game.getType(id));
}

TEST(GameTest, noThrowWhenGetCharacterSpeed) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_NO_THROW(game.getCharacterSpeed(9988989));
    EXPECT_NO_THROW(game.getCharacterSpeed(id));
}

TEST(GameTest, noThrowWhenGetCharacterJumpForce) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_NO_THROW(game.getCharacterJumpForce(id));
    EXPECT_NO_THROW(game.getCharacterJumpForce(9898989));
}

TEST(GameTest, noThrowWhenGetEnemyFollowRange) {
    Game game = Game();
    std::tuple<std::tuple<int, int>, int> existingSpawn = game.getExistingSpawn();
    int areaX = std::get<0>(std::get<0>(existingSpawn));
    int areaY = std::get<1>(std::get<0>(existingSpawn));
    int spawnId = std::get<1>(existingSpawn);
    int id = game.ifCanSpawnCurrentLevelSpawnAt(areaX, areaY, spawnId);
    EXPECT_NO_THROW(game.getEnemyFollowRange(id));
    EXPECT_NO_THROW(game.getEnemyFollowRange(9898989));
}

TEST(GameTest, noThrowWhenGetEnemyAttackRange) {
    Game game = Game();
    std::tuple<std::tuple<int, int>, int> existingSpawn = game.getExistingSpawn();
    int areaX = std::get<0>(std::get<0>(existingSpawn));
    int areaY = std::get<1>(std::get<0>(existingSpawn));
    int spawnId = std::get<1>(existingSpawn);
    int id = game.ifCanSpawnCurrentLevelSpawnAt(areaX, areaY, spawnId);
    EXPECT_NO_THROW(game.getEnemyAttackRange(id));
    EXPECT_NO_THROW(game.getEnemyAttackRange(9898989));
}

TEST(GameTest, noThrowWhenCanCharacterAttack) {
    Game game = Game();
    int id = game.getPlayerId();
    std::string attackName = "ATTACK1";
    EXPECT_NO_THROW(game.canCharacterAttack(id, attackName));
    EXPECT_NO_THROW(game.canCharacterAttack(9898989, attackName));
    EXPECT_NO_THROW(game.canCharacterAttack(id, "ATTACK09876578"));
}

TEST(GameTest, noThrowWhenGetDamage) {
    Game game = Game();
    int id = game.getPlayerId();
    std::string attackName = "ATTACK1";
    EXPECT_NO_THROW(game.getDamage(id, attackName));
}

TEST(GameTest, noThrowWhenGetChargeTime) {
    Game game = Game();
    int id = game.getPlayerId();
    std::string attackName = "ATTACK1";
    EXPECT_NO_THROW(game.getChargeTime(id, attackName));
}

TEST(GameTest, noThrowWhenGetCharacterHurtTime) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_NO_THROW(game.getCharacterHurtTime(id));
}

TEST(GameTest, noThrowWhenIsCharacterBusy) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_NO_THROW(game.isCharacterBusy(id));
}

TEST(GameTest, noThrowWhenGetCharacterHealth) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_NO_THROW(game.getCharacterHealth(id));
}

TEST(GameTest, noThrowWhenGetCharacterMaxHealth) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_NO_THROW(game.getCharacterMaxHealth(id));
}

TEST(GameTest, noThrowWhenGetPlayerDashForce) {
    Game game = Game();
    EXPECT_NO_THROW(game.getPlayerDashForce());
}

TEST(GameTest, noThrowWhenGetJetPackForce) {
    Game game = Game();
    EXPECT_NO_THROW(game.getJetPackForce());
}

TEST(GameTest, noThrowWhenGetJetPackMaxTime) {
    Game game = Game();
    EXPECT_NO_THROW(game.getJetPackMaxTime());
}

TEST(GameTest, noThrowWhenGetPlayerLandingTime) {
    Game game = Game();
    EXPECT_NO_THROW(game.getPlayerLandingTime());
}

TEST(GameTest, noThrowWhenGetPlayerDashTime) {
    Game game = Game();
    EXPECT_NO_THROW(game.getPlayerDashTime());
}

TEST(GameTest, noThrowWhenGetCharacterAttackTime) {
    Game game = Game();
    int id = game.getPlayerId();
    std::string attackName = "ATTACK1";
    EXPECT_NO_THROW(game.getCharacterAttackTime(id, attackName));
}

TEST(GameTest, noThrowWhenIsPlayerDashing) {
    Game game = Game();
    EXPECT_NO_THROW(game.isPlayerDashing());
}

TEST(GameTest, noThrowWhenIsPlayerUsingJetpack) {
    Game game = Game();
    EXPECT_NO_THROW(game.isPlayerUsingJetpack());
}

TEST(GameTest, noThrowWhenGetActiveLevel) {
    Game game = Game();
    EXPECT_NO_THROW(game.getActiveLevel());
}

TEST(GameTest, noThrowWhenGetAreaGuidCurrentLevel) {
    Game game = Game();
    int x = 0, y = 0;
    EXPECT_NO_THROW(game.get_area_guid_current_level(x, y));
}

TEST(GameTest, noThrowWhenGetPlayerMaxHealth) {
    Game game = Game();
    EXPECT_NO_THROW(game.getPlayerMaxHealth());
}

TEST(GameTest, noThrowWhenGetPlayerCurrentHealth) {
    Game game = Game();
    EXPECT_NO_THROW(game.getPlayerCurrentHealth());
}

TEST(GameTest, noThrowWhenTakePlayerDamage) {
    Game game = Game();
    int damage = 10;
    EXPECT_NO_THROW(game.takePlayerDamage(damage));
}

TEST(GameTest, noThrowWhenIfCanSpawnCurrentLevelSpawnAt) {
    Game game = Game();
    std::tuple<std::tuple<int, int>, int> existingSpawn = game.getExistingSpawn();
    int areaX = std::get<0>(std::get<0>(existingSpawn));
    int areaY = std::get<1>(std::get<0>(existingSpawn));
    int spawnId = std::get<1>(existingSpawn);
    EXPECT_NO_THROW(game.ifCanSpawnCurrentLevelSpawnAt(areaX, areaY, spawnId));
}

TEST(GameTest, noThrowWhenGetType) {
    Game game = Game();
    int id = 0;
    EXPECT_NO_THROW(game.getType(id));
}

TEST(GameTest, playerJump) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_TRUE(game.canCharacterMove(id, "JUMP"));
    EXPECT_NO_THROW(game.move(id, "JUMP"));
}

TEST(GameTest, playerNotKnownMove) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_FALSE(game.canCharacterMove(id, "JUMPJUMP"));
    EXPECT_NO_THROW(game.move(id, "JUMPJUMPRUN"));
}

TEST(GameTest, playerDashCooldown) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_TRUE(game.canCharacterMove(id, "DASH"));
    EXPECT_NO_THROW(game.move(id, "DASH"));
    EXPECT_FALSE(game.canCharacterMove(id, "DASH"));
}

TEST(GameTest, playerMoveMultipleTimes) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_TRUE(game.canCharacterMove(id, "RUN"));
    EXPECT_NO_THROW(game.move(id, "RUN"));
    EXPECT_TRUE(game.canCharacterMove(id, "RUN"));
    EXPECT_NO_THROW(game.move(id, "RUN"));
    EXPECT_TRUE(game.canCharacterMove(id, "RUN"));
    EXPECT_NO_THROW(game.move(id, "RUN"));
}

TEST(GameTest, dashIsBusy) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_FALSE(game.isCharacterBusy(id));
    EXPECT_NO_THROW(game.move(id, "RUN"));
    EXPECT_NO_THROW(game.move(id, "DASH"));
    EXPECT_TRUE(game.isCharacterBusy(id));
}

TEST(GameTest, dashIsBusyAnimationTime) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_FALSE(game.isCharacterBusy(id));
    EXPECT_NO_THROW(game.move(id, "RUN"));
    EXPECT_NO_THROW(game.move(id, "DASH"));
    EXPECT_TRUE(game.isCharacterBusy(id));
    usleep(Dash::DEF_ANIMATION_TIME * 1000000);
    EXPECT_FALSE(game.isCharacterBusy(id));
}

TEST(GameTest, playerIsHurtBusy) {
    Game game = Game();
    int id = game.getPlayerId();
    std::tuple<std::tuple<int, int>, int> existingSpawn = game.getExistingSpawn();
    int areaX = std::get<0>(std::get<0>(existingSpawn));
    int areaY = std::get<1>(std::get<0>(existingSpawn));
    int spawnId = std::get<1>(existingSpawn);
    int enemyId = 0;
    do {
        enemyId = game.ifCanSpawnCurrentLevelSpawnAt(areaX, areaY, spawnId);
    } while (game.getType(enemyId) != "SPECTRUM");
    EXPECT_FALSE(game.isCharacterBusy(id));
    EXPECT_NO_THROW(game.attack(enemyId, "ATTACK_SPECTRUM", id));
    EXPECT_EQ(game.getPlayerCurrentHealth(), Player::DEF_MAX_HEALTH - 75);
    EXPECT_TRUE(game.isCharacterBusy(id));
    usleep(Player::DEF_HURT_TIME * 1000000);
    EXPECT_FALSE(game.isCharacterBusy(id));
}

TEST(GameTest, canCharacterAttackAttack4Player) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_TRUE(game.canCharacterAttack(id, "ATTACK3"));
    EXPECT_FALSE(game.canCharacterAttack(id, "ATTACK4"));
}

TEST(GameTest, canUseJump) {
    Game game = Game();
    int id = game.getPlayerId();
    EXPECT_TRUE(game.canCharacterMove(id, "JUMP"));
    EXPECT_NO_THROW(game.move(id, "JUMP"));
    EXPECT_FALSE(game.canCharacterMove(id, "JUMP"));
}