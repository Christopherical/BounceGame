#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "background.hpp"
#include "ball.hpp"
#include "gameSounds.hpp"
#include "paddle.hpp"
#include "stats.hpp"

class Game {
private:
    sf::RenderWindow window_;
    sf::Clock clock_;

    Paddle paddle_;
    std::vector<Ball> balls_;
    sf::Clock ballSpawnClock_;

    Stats stats_;
    GameSounds gameSounds_;
    Background background_;

public:
    Game();

    bool IsRunning() const;

    void ProcessEvents();
    void Update();
    void Render();

private:
    void HandleCollisions();
    void Restart();
};