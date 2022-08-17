#pragma once
#include "Math/Transform.h"
#include "Serialization/Serializable.h"

namespace c14
{
	class GameObject
	{
	public:
		GameObject() = default;

		virtual void Update() = 0;
	};
}
