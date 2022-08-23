#include "PlayerComponent.h"
#include <iostream>

namespace c14
{
	void PlayerComponent::Update()
	{
		// move left/right
		Vector2 direction = Vector2::zero;
		if (c14::g_inputSystem.GetKeyState(c14::key_left) == InputSystem::State::Held)
		{
			direction = Vector2::left;
		}
		if (c14::g_inputSystem.GetKeyState(c14::key_right) == InputSystem::State::Held)
		{
			direction = Vector2::right;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
		}

		// edge of screen
		// if (m_owner->m_transform.position.x > c14::g_renderer.GetWidth()) m_owner->m_transform.position.x = 0;
		// if (m_owner->m_transform.position.x < 0) m_owner->m_transform.position.x = c14::g_renderer.GetWidth();
		// if (m_owner->m_transform.position.y > c14::g_renderer.GetHeight()) m_owner->m_transform.position.y = 0;
		// if (m_owner->m_transform.position.y < 0) m_owner->m_transform.position.y = c14::g_renderer.GetHeight();

		// jump
		if (g_inputSystem.GetKeyState(key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * 30);
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		//
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);

		return true;
	}
}

