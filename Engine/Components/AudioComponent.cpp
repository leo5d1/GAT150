#include "AudioComponent.h"
#include "Engine.h"

namespace c14
{
	void AudioComponent::Update()
	{

	}

	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		//
		return true;
	}

	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		//
		return true;
	}

	void AudioComponent::Play()
	{
		g_audio.PlayAudio(m_soundname, m_loop);
	}
	
	void AudioComponent::Stop()
	{
		
	}
}
