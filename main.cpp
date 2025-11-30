#include "Application.hpp"

int main()
{
    Application app;

    while (app.isRunning())
    {
        app.processEvents();
        app.update();
        app.render();
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