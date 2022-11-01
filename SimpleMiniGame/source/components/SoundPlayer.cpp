#include "../../include/utils/SoundPlayer.h"

// SFMLSoundProvider
SoundPlayer::SoundPlayer()
{
    _sound.setVolume(100.0f);
}

void SoundPlayer::PlaySound(std::string filename)
{
    _soundBuffer.loadFromFile(filename);
    _sound.setBuffer(_soundBuffer);
    _sound.play();
}

void SoundPlayer::StopAllSounds()
{
    _sound.setBuffer(_soundBuffer);
    _sound.stop();
}
