#include "stats.hpp"
#include "gameConfig.hpp"

#include <fstream>

Stats::Stats()
    : font_("content/ArianaVioleta.ttf"),
      scoreText_(font_),
      livesText_(font_),
      highScoreText_(font_) {
    scoreText_.setPosition({10.f, 10.f});
    scoreText_.setFillColor(sf::Color::Green);
    SetScore(0);

    livesText_.setPosition({10.f, 60.f});
    livesText_.setFillColor(sf::Color::Red);
    SetLives(gConfig.startingLives);

    highScoreText_.setPosition({10.f, 110.f});
    highScoreText_.setFillColor(sf::Color::Yellow);
    SetHighScore(0);

    if (std::ifstream file {"HighScores.txt"}) {

        file >> highScore_;

    } else {
        highScore_ = 0;
    }

    SetHighScore(highScore_);
}

void Stats::Draw(sf::RenderWindow& window) const {
    window.draw(scoreText_);
    window.draw(livesText_);
    window.draw(highScoreText_);
}

void Stats::SetScore(int score) {
    score_ = score;
    scoreText_.setString("Score: " + std::to_string(score_));
}

void Stats::SetLives(int lives) {
    lives_ = lives;
    livesText_.setString("Lives: " + std::to_string(lives_));
}

void Stats::SetHighScore(int highScore) {
    highScore_ = highScore;
    highScoreText_.setString("High Score: " + std::to_string(highScore_));
}

int Stats::GetScore() const {
    return score_;
}

int Stats::GetLives() const {
    return lives_;
}

int Stats::GetHighScore() const {
    return highScore_;
}

void Stats::Reset() {
    if (score_ > highScore_) {
        if (std::ofstream file {"HighScores.txt"}) {
            file << score_;
        }
        SetHighScore(score_);
    }
    SetScore(0);
    SetLives(gConfig.startingLives);
}
