#pragma once
#include "Framework/Component.h"

namespace c14
{
	class Actor;

	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;

		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Play();
		void Stop();

	public:
		std::string m_soundname;
		bool m_playonawake = false;
		float m_volume = 1;
		float m_pitch = 1;
		bool m_loop = false;
	};
}