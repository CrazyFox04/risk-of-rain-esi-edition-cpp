//
// Created by Enzo Renard on 26/12/2024.
//

#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <chrono>

class Animation {
    double duration;
    std::chrono::time_point<std::chrono::steady_clock> lastUsage;

public:
    Animation(double duration);
    void start();
    bool isPlaying() const;
    double getDuration() const;
};
#endif //ANIMATION_HPP
