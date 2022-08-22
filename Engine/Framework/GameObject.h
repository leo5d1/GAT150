#pragma once
#include "Math/Transform.h"
#include "Serialization/Serializable.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class);

namespace c14
{
	class GameObject
	{
	public:
		GameObject() = default;

		virtual void Initialize() = 0;
		virtual void Update() = 0;
	};
}
