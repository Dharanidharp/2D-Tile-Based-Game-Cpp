#pragma once
#include "../../include/components/AudioManager.h"

class NullService : public AudioManager
{
public:
	virtual void PlaySound(std::string filename) { /* Do nothing. */ }
	virtual void StopAllSounds() { /* Do nothing. */ }
	virtual bool IsSoundPlaying() { /* Do nothing. */ }
};