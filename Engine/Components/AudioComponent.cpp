#include "AudioComponent.h"
#include "Engine.h"

namespace c14
{
	void AudioComponent::Update()
	{

	}

	void AudioComponent::Play()
	{
		g_audio.PlayAudio(m_soundname, m_loop);
	}
	
	void AudioComponent::Stop()
	{
		
	}
}
