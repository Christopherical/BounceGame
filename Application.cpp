#include "Application.hpp"
#include <iostream>

/////////////////////////////Constructor//////////////////////////////
Application::Application()
    : window_(sf::VideoMode({600, 800}), "BounceGame", sf::Style::Default),
      texture_("player.png"),
      sprite_(texture_) {

    texture_.setSmooth(true);
    player_.setTexture(&texture_);
    player_.setSize({64.f, 64.f});
    player_.setFillColor(sf::Color::Blue);
    player_.setPosition({300.f, 700.f});

    enemy_.setTexture(&texture_);
    enemy_.setSize({64.f, 64.f});
    enemy_.setFillColor(sf::Color::Red);
    enemy_.setPosition({200.f, 400.f});

    sprite_.setPosition({100.f, 100.f});
    sprite_.setScale({3.0f, 4.0f});
    sprite_.setColor(sf::Color::Green);

    window_.setFramerateLimit(60);
    // Prevents multiple key pressed events when holding key down.
    window_.setKeyRepeatEnabled(false);

    sf::Mouse::setPosition({300, 400}, window_);

    rectangle_.setSize({200.f, 100.f});
    rectangle_.setPosition({100.f, 150.f});
    rectangle_.setFillColor({155, 255, 135});
    rectangle_.setOutlineThickness(5.f);
    rectangle_.setOutlineColor(sf::Color::Red);

    circle_.setRadius(50.f);
    circle_.setPosition({300.f, 400.f});
    circle_.setFillColor(sf::Color::Green);
}
/////////////////////////////Constructor//////////////////////////////
/////////////////////////////Methods/////////////////////////////////
bool Application::isRunning() const {
    return window_.isOpen();
}

// Event processing for single events.
void Application::processEvents() {
    window_.handleEvents([this](const auto& event) { this->HandleEvent(event); });
}

// Polling for key held down events in update loop.
void Application::update() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window_);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
        std::cout << "Left Key Held Down" << std::endl;
        // sprite_.move(-5.f, 0.f);
    }
}

void Application::render() {
    window_.clear(); // Erases everything that was drawn previously.
    // Draw your objects here

    // window_.draw(rectangle_);
    // window_.draw(circle_);
    // window_.draw(player_);
    // window_.draw(enemy_);
    window_.draw(sprite_);

    window_.display(); // Updates the visible content of the window.
}
/////////////////////////////Methods/////////////////////////////////
/////////////////////////////Event Handlers//////////////////////////
// Event Handlers
void Application::HandleEvent(const sf::Event::Closed&) {
    window_.close();
    std::cout << "Window Closed" << std::endl;
}

void Application::HandleEvent(const sf::Event::Resized& resized) {
    std::cout << "New width: " << resized.size.x << ", New height: " << resized.size.y << std::endl;
}
void Application::HandleEvent(const sf::Event::FocusLost&) {
    std::cout << "Focus Lost" << std::endl;
}
void Application::HandleEvent(const sf::Event::FocusGained&) {
    std::cout << "Focus Gained" << std::endl;
}

void Application::HandleEvent(const sf::Event::KeyPressed& key) {
    if (key.code == sf::Keyboard::Key::W) {
        std::cout << "W Pressed" << std::endl;
    }
}
void Application::HandleEvent(const sf::Event::KeyReleased& key) {
    if (key.code == sf::Keyboard::Key::W) {
        std::cout << "W Released" << std::endl;
    }
}
void Application::HandleEvent(const sf::Event::MouseButtonPressed& mouse) {
    if (mouse.button == sf::Mouse::Button::Left) {
        std::cout << "Left mouse button clicked at position (" << mouse.position.x << ", "
                  << mouse.position.y << ")" << std::endl;
    }
}
void Application::HandleEvent(const sf::Event::MouseButtonReleased& mouse) {
    std::cout << "Mouse Button Released" << std::endl;
}
void Application::HandleEvent(const sf::Event::MouseWheelScrolled& scroll) {
    std::cout << "Scrolled by:" << scroll.delta << std::endl;
}
/////////////////////////////Event Handlers//////////////////////////
