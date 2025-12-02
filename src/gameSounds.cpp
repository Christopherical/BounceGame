#include "gameSounds.hpp"
#include "gameConfig.hpp"

GameSounds::GameSounds()
    : music_("content/sampleMusic.wav"),
      bounceSoundBuffer_("content/jump.mp3"),
      bounceSound_(bounceSoundBuffer_),
      missedSoundBuffer_("content/missed.mp3"),
      missedSound_(missedSoundBuffer_) {

    music_.setVolume(gConfig.musicVolume);
    music_.setLooping(true);
    music_.play();

    bounceSound_.setVolume(gConfig.bounceSoundVolume);
    missedSound_.setVolume(gConfig.bounceSoundVolume);
}

void GameSounds::PlayBounceSound() {
    bounceSound_.play();
}

void GameSounds::PlayMissedSound() {
    missedSound_.play();
}
