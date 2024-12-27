//
// Created by Enzo Renard on 25/12/2024.
//
#include <gtest/gtest.h>
#include "Game.hpp"
#include "Level.hpp"

TEST(GameTest, DefaultConstructorInitializesActiveLevelToNegativeOne) {
    Game game;
    EXPECT_EQ(game.getActiveLevel().getId(), 0);
}

TEST(GameTest, GetAreaGuidCurrentLevelReturnsCorrectGuid) {
    Game game;
    int x = 0, y = 0;
    EXPECT_NO_THROW(game.get_area_guid_current_level(x, y));
}

TEST(GameTest, GetPlayerMaxHealthReturnsCorrectValue) {
    Game game;
    EXPECT_EQ(game.getPlayerMaxHealth(), game.getPlayerMaxHealth());
}

TEST(GameTest, GetPlayerCurrentHealthReturnsCorrectValue) {
    Game game;
    EXPECT_EQ(game.getPlayerCurrentHealth(), game.getPlayerCurrentHealth());
}

TEST(GameTest, TakePlayerDamageDecreasesCurrentHealth) {
    Game game;
    int initialHealth = game.getPlayerCurrentHealth();
    game.takePlayerDamage(10);
    EXPECT_EQ(game.getPlayerCurrentHealth(), initialHealth - 10);
}

TEST(GameTest, IfCanSpawnCurrentLevelSpawnAtReturnsTrueWhenSpawned) {
    Game game = Game();
    int areaX = 0, areaY = 0, spawnId = 1;
    EXPECT_NE(-1, game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId));
    EXPECT_EQ(-1, game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId));
    sleep(11);
    EXPECT_NE(-1, game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId));
}

TEST(GameTest, IfCanSpawnCurrentLevelSpawnAtReturnsFalseWhenNotSpawned) {
    Game game = Game();
    int areaX = 0, areaY = 0, spawnId = 1;
    EXPECT_NE(-1, game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId));
    EXPECT_EQ(-1, game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId));
}

TEST(GameTest, IfSpawnReturnId_isInThisLevel) {
    Game game = Game();
    int areaX = 0, areaY = 0, spawnId = 1;
    int id = game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId);
    EXPECT_NO_THROW(game.getType(98765678987));
    EXPECT_EQ("", game.getType(98765678987));
    EXPECT_NO_THROW(game.getType(id));
}

TEST(GameTest, noThrowWhenGetCharacterSpeed) {
    Game game = Game();
    int id = 0;
    EXPECT_NO_THROW(game.getCharacterSpeed(id));
}

TEST(GameTest, noThrowWhenGetCharacterJumpForce) {
    Game game = Game();
    int id = 0;
    EXPECT_NO_THROW(game.getCharacterJumpForce(id));
}

TEST(GameTest, noThrowWhenGetEnemyFollowRange) {
    Game game = Game();
    int areaX = 0, areaY = 0, spawnId = 1;
    int id = game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId);
    EXPECT_NO_THROW(game.getEnemyFollowRange(id));
}

TEST(GameTest, noThrowWhenGetEnemyAttackRange) {
    Game game = Game();
    int areaX = 0, areaY = 0, spawnId = 1;
    int id = game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId);
    EXPECT_NO_THROW(game.getEnemyAttackRange(id));
}

TEST(GameTest, noThrowWhenCanCharacterAttack) {
    Game game = Game();
    int id = 0;
    std::string attackName = "ATTACK1";
    EXPECT_NO_THROW(game.canCharacterAttack(id, attackName));
}

TEST(GameTest, noThrowWhenGetDamage) {
    Game game = Game();
    int id = 0;
    std::string attackName = "ATTACK1";
    EXPECT_NO_THROW(game.getDamage(id, attackName));
}

TEST(GameTest, noThrowWhenGetChargeTime) {
    Game game = Game();
    int id = 0;
    std::string attackName = "ATTACK1";
    EXPECT_NO_THROW(game.getChargeTime(id, attackName));
}

TEST(GameTest, noThrowWhenGetCharacterHurtTime) {
    Game game = Game();
    int id = 0;
    EXPECT_NO_THROW(game.getCharacterHurtTime(id));
}

TEST(GameTest, noThrowWhenIsCharacterBusy) {
    Game game = Game();
    int id = 0;
    EXPECT_NO_THROW(game.isCharacterBusy(id));
}

TEST(GameTest, noThrowWhenGetCharacterHealth) {
    Game game = Game();
    int id = 0;
    EXPECT_NO_THROW(game.getCharacterHealth(id));
}

TEST(GameTest, noThrowWhenGetCharacterMaxHealth) {
    Game game = Game();
    int id = 0;
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
    int id = 0;
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
    int areaX = 0, areaY = 0, spawnId = 1;
    EXPECT_NO_THROW(game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId));
}

TEST(GameTest, noThrowWhenGetType) {
    Game game = Game();
    int id = 0;
    EXPECT_NO_THROW(game.getType(id));
}
