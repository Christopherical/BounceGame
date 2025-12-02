#pragma once

#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::CircleShape shape_;
    sf::Vector2f direction_;
    float speed_;

public:
    Ball();

    void Draw(sf::RenderWindow& window) const;
    void Move(float deltaTime);
    void Bounce();

    sf::FloatRect GetGlobalBounds() const;
    sf::Vector2f GetDirection() const;
    bool IsOffScreen() const;
};