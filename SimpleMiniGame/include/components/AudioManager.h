#pragma once
#include <SFML/Audio.hpp>

class AudioManager
{
public:
	virtual ~AudioManager() {}
	virtual void PlaySound(std::string filename) = 0;
	virtual void StopAllSounds() = 0;
};