#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Application {
private:
    sf::RenderWindow window_;
    sf::RectangleShape rectangle_;
    sf::CircleShape circle_;

    sf::Texture texture_;
    sf::RectangleShape player_;
    sf::RectangleShape enemy_;
    sf::Sprite sprite_;

    sf::Clock clock_;

    sf::Font font_;
    sf::Text text_;

    sf::SoundBuffer soundBuffer_;
    sf::Sound sound_;

    sf::Music music_;

    sf::Texture backgroundTexture_;
    sf::Sprite backgroundSprite_;

    sf::View cameraView_;
    float zoomLevel_ = 1.0f; // Track current zoom level

    // Set your limits
    const float MIN_ZOOM = 0.5f; // Max zoom in (smaller = more zoomed in)
    const float MAX_ZOOM = 3.0f; // Max zoom out (larger = more zoomed out)

public:
    Application();

    bool isRunning() const;
    void processEvents();
    void update();
    void render();

private:
    void HandleEvent(const sf::Event::Closed&);
    void HandleEvent(const sf::Event::Resized& resized);
    void HandleEvent(const sf::Event::FocusLost&);
    void HandleEvent(const sf::Event::FocusGained&);
    void HandleEvent(const sf::Event::KeyPressed& key);
    void HandleEvent(const sf::Event::KeyReleased& key);
    void HandleEvent(const sf::Event::MouseButtonPressed& mouse);
    void HandleEvent(const sf::Event::MouseButtonReleased& mouse);
    void HandleEvent(const sf::Event::MouseWheelScrolled& scroll);
    void HandleEvent(const auto&) {}

    void UpdatePlayerMovement(float deltaTime);
};
