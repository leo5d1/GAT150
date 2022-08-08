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
			thrust = 100;
		}
		// turbo speed
		if (c14::g_inputSystem.GetKeyState(c14::key_up) == InputSystem::State::Held && c14::g_inputSystem.GetKeyState(c14::key_space) == InputSystem::State::Held)
		{
			thrust = thrust * 2;
		}

		// calculate velocity
		c14::Vector2 direction{ 1, 0 };
		direction = c14::Vector2::Rotate(direction, m_owner->m_transform.rotation);
		c14::Vector2 velocity = direction * thrust * c14::g_time.deltaTime;
		//move
		m_owner->m_transform.position += velocity;

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
}

