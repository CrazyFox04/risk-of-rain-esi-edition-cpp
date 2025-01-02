//
// Created by Enzo Renard on 29/12/2024.
//
#ifndef _WIN64
#define PCH_H
#endif
#include "pch.h"
#include "GameOverException.hpp"

#include <utility>

GameOverException::GameOverException(std::string message) : message(std::move(message)) {
}

const char* GameOverException::what() const noexcept {
    return message.c_str();
}