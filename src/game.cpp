#include "game.hpp"
#include "gameConfig.hpp"
#include <algorithm>

Game::Game()
    : window_(sf::VideoMode(sf::Vector2u(gConfig.windowSize)), "Bounce") {
    window_.setFramerateLimit(60);
}

bool Game::IsRunning() const {
    return window_.isOpen();
}

void Game::ProcessEvents() {
    while (std::optional event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }
    }
}

void Game::Update() {
    float deltaTime = clock_.restart().asSeconds();

    if (ballSpawnClock_.getElapsedTime().asSeconds() > gConfig.ballSpawnCooldown) {
        balls_.emplace_back();
        ballSpawnClock_.restart();
    }

    paddle_.Move(deltaTime);
    for (Ball& ball_ : balls_) {
        ball_.Move(deltaTime);
    }

    HandleCollisions();

    if (stats_.GetLives() <= 0) {
        Restart();
    }
}

void Game::Render() {
    window_.clear(sf::Color::White);

    background_.Draw(window_);
    paddle_.Draw(window_);
    for (const Ball& ball_ : balls_) {
        ball_.Draw(window_);
    }
    stats_.Draw(window_);

    window_.display();
}

void Game::HandleCollisions() {
    sf::FloatRect paddleBounds = paddle_.GetGlobalBounds();

    for (Ball& ball_ : balls_) {
        sf::FloatRect ballBounds = ball_.GetGlobalBounds();
        bool isColliding = ballBounds.findIntersection(paddleBounds).has_value();

        if (isColliding && ball_.GetDirection().y > 0) {
            ball_.Bounce();
            stats_.SetScore(stats_.GetScore() + 1);
            gameSounds_.PlayBounceSound();
        }
        if (ball_.IsOffScreen()) {
            gameSounds_.PlayMissedSound();
        }
    }

    std::size_t ballsMissed =
        std::erase_if(balls_, [](const Ball& ball) { return ball.IsOffScreen(); });
    if (ballsMissed > 0) {
        stats_.SetLives(stats_.GetLives() - ballsMissed);
    }
}

void Game::Restart() {
    balls_.clear();
    ballSpawnClock_.restart();
    stats_.Reset();
}
