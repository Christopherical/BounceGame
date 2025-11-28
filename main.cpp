#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // sf::RenderWindow window(sf::VideoMode({600, 800}), "BounceGame", sf::Style::Default);
    // window.setMinimumSize(sf::Vector2u(400, 300));
    // window.setMaximumSize(sf::Vector2u(800, 1000));
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Window", sf::State::Windowed); // Windowed mode.
    window.setFramerateLimit(60);
    // window.create(sf::VideoMode::getDesktopMode(), "Window", sf::State::Windowed); // Creates new window (if player changes window settings, etc.)

    // window.setVerticalSyncEnabled(true); // Alternative to setFramerateLimit - to avoid screen tearing.
    // window.setMouseCursorVisible(false); // Hides the mouse cursor when it's over the window. For a full screen first person game, etc.
    // window.setMouseCursorGrabbed(true); // Confines the mouse cursor to the window.

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        // Handles events triggered during the frame.
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // std::cout << window.hasFocus() << std::endl; // Pause or stop music, etc., when user clicks off the game.

        // Rendering
        window.clear(); // Erases everything that was drawn previously.
        window.draw(shape);
        window.display(); // Updates the visible content of the window.
    }
}