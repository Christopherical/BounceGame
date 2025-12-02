#pragma once
#include <SFML/Graphics.hpp>
class Background {
private:
    sf::Texture backgroundTexture_;
    sf::Sprite backgroundSprite_;

public:
    Background();

    void Draw(sf::RenderWindow& window) const;
};