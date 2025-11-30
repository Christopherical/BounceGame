#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({600, 800}), "BounceGame", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        // Uses pollEvent to check whether the m_events queue has any events to process.
        while(const std::optional event = window.pollEvent())
        {
            // uses is and getIf which are wrappers for std::holds_alternative and std::get_if respectively.
            if(event->is<sf::Event::Closed>()){
                window.close();
            }

            // Gain and lose focus events.
            if(event->is<sf::Event::FocusLost>())
            {
                std::cout << "Window lost focus" << std::endl;
            }
            if(event->is<sf::Event::FocusGained>())
            {
                std::cout << "Window gained focus" << std::endl;
            }
            
            // Uses getIf to return a pointer to the Resized event data if the event is of that type.
            if(const sf::Event::Resized* resized = event->getIf<sf::Event::Resized>())
            {
                std::cout << "New width: " << resized->size.x << ", New height: " << resized->size.y << std::endl;
            }

            // Key pressed event with modifier check.
            if(const auto key = event->getIf<sf::Event::KeyPressed>())
            {
                if (key->code == sf::Keyboard::Key::W)
                {
                    if (key->control){
                        std::cout << "W key pressed with ctrl" << std::endl;
                    }
                    else{
                        std::cout << "W key pressed" << std::endl;
                    }
                }
            }
            
            // Mouse button pressed event.
            if(const auto mouseClick = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if(mouseClick->button == sf::Mouse::Button::Left)
                {
                    std::cout << "Left mouse button clicked at position (" 
                              << mouseClick->position.x << ", " 
                              << mouseClick->position.y << ")" << std::endl;
                }
            }
        }

        // Rendering
        window.clear(); // Erases everything that was drawn previously.
        window.draw(shape);
        window.display(); // Updates the visible content of the window.
    }
}

// Window functions:
// window.setMinimumSize(sf::Vector2u(400, 300));
// window.setMaximumSize(sf::Vector2u(800, 1000));
// sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Window", sf::State::Windowed); // Windowed mode.
// window.create(sf::VideoMode::getDesktopMode(), "Window", sf::State::Windowed); // Creates new window (if player changes window settings, etc.)
// window.setVerticalSyncEnabled(true); // Alternative to setFramerateLimit - to avoid screen tearing.
// window.setMouseCursorVisible(false); // Hides the mouse cursor when it's over the window. For a full screen first person game, etc.
// window.setMouseCursorGrabbed(true); // Confines the mouse cursor to the window.
// window.hasFocus() // Pause or stop music, etc., when user clicks off the game.

// https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1Event.html
// List of events available in SFML:
// std::variant<Closed,
//              Resized,
//              FocusLost,
//              FocusGained,
//              TextEntered,
//              KeyPressed,
//              KeyReleased,
//              MouseWheelScrolled,
//              MouseButtonPressed,
//              MouseButtonReleased,
//              MouseMoved,
//              MouseMovedRaw,
//              MouseEntered,
//              MouseLeft,
//              JoystickButtonPressed,
//              JoystickButtonReleased,
//              JoystickMoved,
//              JoystickConnected,
//              JoystickDisconnected,
//              TouchBegan,
//              TouchMoved,
//              TouchEnded,
//              SensorChanged>
//     m_data;