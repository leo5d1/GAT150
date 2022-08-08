#pragma once
#include"../Math/Transform.h"

namespace c14
{
	class GameObject
	{
	public:
		GameObject() = default;

		virtual void Update() = 0;
	};
}
