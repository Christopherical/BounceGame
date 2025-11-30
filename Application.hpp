#pragma once

#include <SFML/Graphics.hpp>

class Application
{
private:
    sf::RenderWindow window_;
    sf::RectangleShape rectangle_;
    sf::CircleShape circle_;

    sf::Texture texture_;

public:
    Application();

    bool isRunning() const;
    void processEvents();
    void update();
    void render();

private:
    void HandleEvent(const sf::Event::Closed &);
    void HandleEvent(const sf::Event::Resized &resized);
    void HandleEvent(const sf::Event::FocusLost &);
    void HandleEvent(const sf::Event::FocusGained &);
    void HandleEvent(const sf::Event::KeyPressed &key);
    void HandleEvent(const sf::Event::KeyReleased &key);
    void HandleEvent(const sf::Event::MouseButtonPressed &mouse);
    void HandleEvent(const sf::Event::MouseButtonReleased &mouse);
    void HandleEvent(const sf::Event::MouseWheelScrolled &scroll);
    void HandleEvent(const auto &) {}
};
