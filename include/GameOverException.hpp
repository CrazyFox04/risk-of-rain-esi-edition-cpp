//
// Created by Enzo Renard on 29/12/2024.
//

#ifndef GAMEOVEREXCEPTION_HPP
#define GAMEOVEREXCEPTION_HPP
#include <iostream>
#include <stdexcept>
#include <string>

class GameOverException : public std::exception {
    std::string message;

public:
    explicit GameOverException(const std::string&message);

    const char* what() const noexcept override;
};
#endif //GAMEOVEREXCEPTION_HPP
