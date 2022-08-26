#pragma once
#include "Math/Transform.h"
#include "Serialization/Serializable.h"

#define CLASS_DECLARTATION(class) \
	std::unique_ptr<GameObject> Clone() override { return std::make_unique<class>(*this); }

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class);

namespace c14
{
	class GameObject
	{
	public:
		GameObject() = default;

		virtual std::unique_ptr<GameObject> Clone() = 0;
		virtual void Initialize() = 0;
		virtual void Update() = 0;
	};
}
