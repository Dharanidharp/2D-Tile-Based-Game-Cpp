#pragma once
#include "../../include/components/AudioManager.h"

class ServiceLocator
{
public:
    static AudioManager* GetAudio() { return _audioManager; }

    static void RegisterServiceLocator(AudioManager* manager) 
    {
        _audioManager = manager;
    }

private:
    static AudioManager* _audioManager;
};