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

void GameController::addPlayerMaxHealth(int health) {
     game_.addPlayerMaxHealth(health);
}

void GameController::addPlayerHealth(int health) {
    game_.addPlayerHealth(health);
}

void GameController::takePlayerDamage(int damage) {
    game_.takePlayerDamage(damage);
}

int GameController::get_area_guid_current_level(int x, int y) const {
    return game_.get_area_guid_current_level(x, y);
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

void addPlayerMaxHealth(GameController* game_controller, int health) {
    game_controller->addPlayerMaxHealth(health);
}

void addPlayerHealth(GameController* game_controller, int health) {
    game_controller->addPlayerHealth(health);
}

void takePlayerDamage(GameController* game_controller, int health) {
    game_controller->takePlayerDamage(health);
}

int get_area_guid_current_level(const GameController* game_controller, int x, int y) {
    return game_controller->get_area_guid_current_level(x, y);
}