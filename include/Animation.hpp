//
// Created by Enzo Renard on 26/12/2024.
//
/**
 * @file Animation.hpp
 * @brief Defines the Animation class for managing timed animations.
 *
 * The Animation class provides a simple interface to start, check, and retrieve
 * the duration of an animation. This can be used for visual or logical animations
 * requiring a timed duration.
 */
#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <chrono>

/**
 * @class Animation
 * @brief Manages a timed animation state.
 */
class Animation {
    double duration; ///< The duration of the animation in seconds.
    std::chrono::time_point<std::chrono::steady_clock> lastUsage; ///< The time point when the animation was last started.

public:
    /**
     * @brief Constructd an Animation object with a specific duration.
     * @param duration The duration of the animation in seconds.
     */
    Animation(double duration);

    /**
     * @brief Starts the animation by setting the last usage time to the current time.
     */
    void start();

    /**
     * @brief Checks if the animation is currently playing.
     * @return True if the animation is still within its duration, otherwise false.
     */
    bool isPlaying() const;

    /**
     * @brief Retrieves the duration of the animation.
     * @return The duration of the animation in seconds.
     */
    double getDuration() const;
};
#endif //ANIMATION_HPP
