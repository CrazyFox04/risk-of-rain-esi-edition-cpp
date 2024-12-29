//
// Created by Enzo Renard on 29/12/2024.
//
#include "GameOverException.hpp"

GameOverException::GameOverException(const std::string&message) : message(message) {
}

const char* GameOverException::what() const noexcept {
    return message.c_str();
}