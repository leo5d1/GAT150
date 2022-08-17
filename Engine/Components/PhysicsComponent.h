#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace c14
{
	class Actor;

	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;

		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void ApplyForce(const Vector2& force) { m_acceleration += force; }

	public:
		Vector2 m_velocity;
		Vector2 m_acceleration;

		float m_damping = 1;
	};
}