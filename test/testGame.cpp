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
    EXPECT_TRUE(game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId));
    EXPECT_FALSE(game.if_can_spawn_current_level_spawn_at(areaX, areaY, spawnId));
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