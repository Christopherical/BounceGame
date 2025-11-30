#include "Application.hpp"
#include <iostream>

Application::Application()
    : window_(sf::VideoMode({600, 800}), "BounceGame", sf::Style::Default)
{
    window_.setFramerateLimit(60);

    rectangle_.setSize({200.f, 100.f});
    rectangle_.setPosition({100.f, 150.f});
    rectangle_.setFillColor({155, 255, 135});
    rectangle_.setOutlineThickness(5.f);
    rectangle_.setOutlineColor(sf::Color::Red);

    circle_.setRadius(50.f);
    circle_.setPosition({300.f, 400.f});
    circle_.setFillColor(sf::Color::Green);
    // circle_.setPointCount(3); // More points = smoother circle
    texture_.loadFromFile("player.png");
}

bool Application::isRunning() const
{
    return window_.isOpen();
}

void Application::processEvents()
{
    while (const std::optional<sf::Event> event = window_.pollEvent())
    {
        window_.handleEvents([this](const auto &event)
                             { this->HandleEvent(event); });
    }
}

void Application::update()
{
    // Update logic here
}

void Application::render()
{
    window_.clear(); // Erases everything that was drawn previously.
    // Draw your objects here

    window_.draw(rectangle_);
    window_.draw(circle_);

    window_.display(); // Updates the visible content of the window.
}

// Event Handlers
void Application::HandleEvent(const sf::Event::Closed &)
{
    window_.close();
    std::cout << "Window Closed" << std::endl;
}

void Application::HandleEvent(const sf::Event::Resized &resized)
{
    std::cout << "New width: " << resized.size.x << ", New height: " << resized.size.y << std::endl;
}
void Application::HandleEvent(const sf::Event::FocusLost &)
{
    std::cout << "Focus Lost" << std::endl;
}
void Application::HandleEvent(const sf::Event::FocusGained &)
{
    std::cout << "Focus Gained" << std::endl;
}

void Application::HandleEvent(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        std::cout << "W Pressed" << std::endl;
    }
}
void Application::HandleEvent(const sf::Event::KeyReleased &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        std::cout << "W Released" << std::endl;
    }
}
void Application::HandleEvent(const sf::Event::MouseButtonPressed &mouse)
{
    if (mouse.button == sf::Mouse::Button::Left)
    {
        std::cout << "Left mouse button clicked at position ("
                  << mouse.position.x << ", "
                  << mouse.position.y << ")" << std::endl;
    }
}
void Application::HandleEvent(const sf::Event::MouseButtonReleased &mouse)
{
    std::cout << "Mouse Button Released" << std::endl;
}
void Application::HandleEvent(const sf::Event::MouseWheelScrolled &scroll)
{
    std::cout << "Scrolled by:" << scroll.delta << std::endl;
}
