#include "PlayerComponent.h"
#include <iostream>

namespace c14
{
	void PlayerComponent::Update()
	{
		if (g_inputSystem.GetKeyState(key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component)
			{
				component->Play();
			}
		}

		//keyboard controls
		// rotate
		if (c14::g_inputSystem.GetKeyState(c14::key_left) == InputSystem::State::Held)
		{
			m_owner->m_transform.rotation -= 180 * c14::g_time.deltaTime;
		}
		if (c14::g_inputSystem.GetKeyState(c14::key_right) == InputSystem::State::Held)
		{
			m_owner->m_transform.rotation += 180 * c14::g_time.deltaTime;
		}
		// set thrust speed
		float thrust = 0;
		if (c14::g_inputSystem.GetKeyState(c14::key_up) == InputSystem::State::Held)
		{
			thrust = speed;
			
		}

		// edge of screen
		if (m_owner->m_transform.position.x > c14::g_renderer.GetWidth()) m_owner->m_transform.position.x = 0;
		if (m_owner->m_transform.position.x < 0) m_owner->m_transform.position.x = c14::g_renderer.GetWidth();
		if (m_owner->m_transform.position.y > c14::g_renderer.GetHeight()) m_owner->m_transform.position.y = 0;
		if (m_owner->m_transform.position.y < 0) m_owner->m_transform.position.y = c14::g_renderer.GetHeight();


		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			// thrust force
			Vector2 force = Vector2::Rotate({ 1, 0 }, math::DegToRad(m_owner->m_transform.rotation)) * thrust;
			component->ApplyForce(force);

			// gravitational force
			//force = (Vector2{ 400, 300 } - m_owner->m_transform.position).Normalized() * 100;
			//component->ApplyForce(force);
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

