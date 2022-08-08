#pragma once
#include "Framework/Component.h"
#include "Framework/Actor.h"
#include "Engine.h"

namespace c14
{
	class Actor;

	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;

		void Update() override;

		Actor actor;

	private:
		float m_speed{ 0 };
		float m_maxSpeed{ 100 };
	};
}