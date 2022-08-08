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

	};
}