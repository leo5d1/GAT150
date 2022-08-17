#pragma once
#include "Framework/Component.h"
#include "Engine.h"

namespace c14
{
	class Actor;

	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;

		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float speed{ 0 };
	};
}