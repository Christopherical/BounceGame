#include "Application.hpp"
#include <iostream>

/////////////////////////////Constructor//////////////////////////////
Application::Application()
    : window_(sf::VideoMode({600, 800}), "BounceGame", sf::Style::Default),
      texture_("player.png"),
      sprite_(texture_),
      font_("ArianaVioleta.ttf"),
      text_(font_),
      soundBuffer_("sampleSound.wav"),
      sound_(soundBuffer_),
      music_("sampleMusic.wav"),
      backgroundTexture_("background.jpg"),
      backgroundSprite_(backgroundTexture_) {

    // music_.play();
    // music_.setLooping(true);
    text_.setString("Bounce Game!");
    text_.setCharacterSize(50);
    text_.setFillColor(sf::Color::White);
    text_.setPosition({150.f, 20.f});
    text_.setOutlineColor(sf::Color::Red);
    text_.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
    text_.setOutlineThickness(2.f);
    text_.setScale({1.5f, 1.5f});

    texture_.setSmooth(true);

    player_.setTexture(&texture_);
    player_.setSize({64.f, 64.f});
    player_.setOrigin(player_.getGlobalBounds().size / 2.f);
    player_.setFillColor(sf::Color::Blue);
    player_.setPosition({300.f, 700.f});

    // enemy_.setTexture(&texture_);
    enemy_.setSize({64.f, 64.f});
    enemy_.setFillColor(sf::Color::Red);
    enemy_.setPosition({200.f, 400.f});

    sprite_.setPosition({500.f, 500.f});
    sprite_.setOrigin(sprite_.getGlobalBounds().size / 2.f);
    sprite_.setScale({3.0f, 4.0f});
    sprite_.setRotation(sf::degrees(45.f));
    // sprite_.setColor(sf::Color::Green);

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

    cameraView_.setSize({600.f, 800.f});
    cameraView_.setCenter({300.f, 400.f});
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
    float deltaTime = clock_.restart().asSeconds();

    cameraView_.setCenter(sprite_.getPosition());
    sf::Vector2f lastPositon = sprite_.getPosition();
    UpdatePlayerMovement(deltaTime);

    // AABB(access aligned bounding box) Collision Detection
    if (sprite_.getGlobalBounds().findIntersection(enemy_.getGlobalBounds())) {
        sprite_.setPosition(lastPositon);
    }
    if (sprite_.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window_)))) {
        std::cout << "Mouse is over the sprite!" << std::endl;
        sprite_.setColor(sf::Color::Yellow);
    } else {
        sprite_.setColor(sf::Color::White);
    }
}
void Application::render() {
    window_.clear(); // Erases everything that was drawn previously.
    // window_.draw(rectangle_);
    // window_.draw(circle_);
    // window_.draw(player_);
    window_.setView(cameraView_);
    window_.draw(backgroundSprite_);
    window_.draw(enemy_);
    window_.draw(sprite_);
    window_.setView(window_.getDefaultView());
    window_.draw(text_);


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
        sound_.play();
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
    if (scroll.wheel == sf::Mouse::Wheel::Vertical) {
        float zoomFactor;
        if (scroll.delta > 0) {
            zoomFactor = 0.9f; // Zoom in
            // cameraView_.zoom(0.9f); // Zoom out
            std::cout << "zooomm" << std::endl;
        } else {
            zoomFactor = 1.1f; // Zoom out
            // cameraView_.zoom(1.1f); // Zoom in
            std::cout << "Zooming In" << std::endl;
        }
        float newZoomLevel = zoomLevel_ * zoomFactor;
        if (newZoomLevel >= MIN_ZOOM && newZoomLevel <= MAX_ZOOM) {
            cameraView_.zoom(zoomFactor);
            zoomLevel_ = newZoomLevel;
            window_.setView(cameraView_);
        } else {
            std::cout << "Zoom limit reached!" << std::endl;
        }
    }
}
/////////////////////////////Event Handlers//////////////////////////
void Application::UpdatePlayerMovement(float deltaTime) {
    float speed = 200.f; // pixels per second
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
        sprite_.move({-speed * deltaTime, 0.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
        sprite_.move({speed * deltaTime, 0.f});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
        sprite_.move({0.f, -speed * deltaTime});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
        sprite_.move({0.f, speed * deltaTime});
    }
}
