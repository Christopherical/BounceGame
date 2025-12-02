
#include "paddle.hpp"
#include "gameConfig.hpp"

#include <algorithm>

Paddle::Paddle()
    : shape_(gConfig.paddleSize),
      speed_(gConfig.paddleSpeed) {

    shape_.setFillColor(sf::Color::Green);
    shape_.setOrigin(shape_.getGeometricCenter());
    shape_.setPosition({gConfig.windowSize.x * 0.50f, gConfig.windowSize.y * 0.85f});
}

void Paddle::Draw(sf::RenderWindow& window) const {
    window.draw(shape_);
}

void Paddle::Move(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        shape_.move({speed_ * deltaTime, 0.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        shape_.move({-speed_ * deltaTime, 0.f});
    }

    // Keep paddle within window bounds.
    float halfWidth = shape_.getSize().x / 2.f;
    float x = std::clamp(shape_.getPosition().x, halfWidth, gConfig.windowSize.x - halfWidth);
    shape_.setPosition({x, shape_.getPosition().y});
}

sf::FloatRect Paddle::GetGlobalBounds() const {
    return shape_.getGlobalBounds();
}
