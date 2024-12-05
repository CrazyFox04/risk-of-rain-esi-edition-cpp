//
// Created by Enzo Renard on 05/12/2024.
//
#include "GameController.hpp"

int GameController::getPlayerMaxHealth() const {
    return 0; 
    //return game_.getPlayerMaxHealth(); todo
}

int GameController::getPlayerCurrentHealth() const {
    return 0;
    //return game_.getPlayerCurrentHealth(); todo
}

void GameController::addPlayerMaxHealth(int health) {
     //game_.addPlayerMaxHealth(health); todo
}

void GameController::addPlayerHealth(int health) {
    //game_.addPlayerHealth(health); todo
}

void GameController::takePlayerDamage(int damage) {
    //game_.takePlayerDamage(health); todo
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





