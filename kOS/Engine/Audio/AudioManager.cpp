#include "AudioManager.h"

namespace audio {
    FMOD::System* AudioManager::s_fmod = nullptr;
    bool AudioManager::s_paused = false;

    AudioManager::AudioManager(){}

    AudioManager::~AudioManager(){}

    void AudioManager::Init() {
        if (!s_fmod) {
            FMOD_RESULT r = FMOD::System_Create(&s_fmod);

            //Intialize fmod
            if (r == FMOD_OK && s_fmod) {
                s_fmod->init(64, FMOD_INIT_NORMAL, nullptr);
                R_Audio::SetGlobalSystem(s_fmod);
            }
        }
    }

    void AudioManager::SetPaused(bool paused) {
        if (!s_fmod) return;

        FMOD::ChannelGroup* master = nullptr;
        if (s_fmod->getMasterChannelGroup(&master) == FMOD_OK && master) {
            master->setPaused(paused);
        }
    }

    void AudioManager::StopAll() {
        if (!s_fmod) return;

        FMOD::ChannelGroup* master = nullptr;
        if (s_fmod->getMasterChannelGroup(&master) == FMOD_OK && master) {
            master->stop();
        }
    }

} 
