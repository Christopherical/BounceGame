#include "background.hpp"

Background::Background()
    : backgroundTexture_("content/background.jpg"),
      backgroundSprite_(backgroundTexture_) {}

void Background::Draw(sf::RenderWindow& window) const {
    window.draw(backgroundSprite_);
}
