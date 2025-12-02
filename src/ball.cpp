#include "ball.hpp"
#include "gameConfig.hpp"
#include "random.hpp"


Ball::Ball()
    : shape_(gConfig.ballRadius),
      speed_(gConfig.ballSpeed) {

    shape_.setFillColor(sf::Color::Red);
    shape_.setOrigin(shape_.getGeometricCenter());
    shape_.setPosition({gConfig.windowSize.x * 0.5f, gConfig.windowSize.y * 0.25f});

    direction_ = {1, sf::degrees(gRandom.GetFloat(0, 360))};
}

void Ball::Draw(sf::RenderWindow& window) const {
    window.draw(shape_);
}

void Ball::Move(float deltaTime) {

    sf::Vector2f lastPosition = shape_.getPosition();
    shape_.move(direction_ * speed_ * deltaTime);

    if (shape_.getPosition().x < shape_.getRadius() ||
        shape_.getPosition().x >= gConfig.windowSize.x - shape_.getRadius()) {
        shape_.setPosition(lastPosition);
        direction_.x *= -1;
    }

    if (shape_.getPosition().y < shape_.getRadius()) {
        shape_.setPosition(lastPosition);
        direction_.y *= -1;
    }
}

sf::FloatRect Ball::GetGlobalBounds() const {
    return shape_.getGlobalBounds();
}

sf::Vector2f Ball::GetDirection() const {
    return direction_;
}

bool Ball::IsOffScreen() const {
    return shape_.getPosition().y - shape_.getRadius() > gConfig.windowSize.y;
}

void Ball::Bounce() {
    direction_.y *= -1;
}
