//
// Created by Enzo Renard on 29/12/2024.
//
/**
 * @file GameOverException.hpp
 * @brief Defines a custom exception for signaling game over conditions.
 */
#ifndef GAMEOVEREXCEPTION_HPP
#define GAMEOVEREXCEPTION_HPP
#include <iostream>
#include <stdexcept>
#include <string>

/**
 * @class GameOverException
 * @brief Custom exception class for signaling game over conditions.
 * Such as when the player character dies.
 */
class GameOverException : public std::exception {
    std::string message;

public:
    /**
     * @brief Constructs a GameOverException with the specified message.
     * @param message The message to include in the exception.
     */
    explicit GameOverException(const std::string&message);

    /**
     * @brief Retrieves the message associated with the exception.
     * @return The message as a C-style string.
     */
    const char* what() const noexcept override;
};
#endif //GAMEOVEREXCEPTION_HPP
