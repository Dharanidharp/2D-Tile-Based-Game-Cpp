#pragma once
#include "../../include/components/AudioManager.h"
#include <SFML/Audio.hpp>

// Provider
class SoundPlayer : public AudioManager
{
public:
	SoundPlayer();

	void PlaySound(std::string filename);
	void StopAllSounds();

private:
	sf::SoundBuffer _soundBuffer;
	sf::Sound _sound;
};