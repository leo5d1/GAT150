#pragma once
#include "Vector2.h"

namespace c14
{
	struct Transform
	{
		Vector2 position;
		float rotation{ 0 };
		Vector2 scale{ 1, 1 };
	};
}
