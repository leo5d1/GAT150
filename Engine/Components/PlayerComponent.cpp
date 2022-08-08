#include "PlayerComponent.h"
#include <iostream>

namespace c14
{
	void PlayerComponent::Update()
	{
		//keyboard controls
		// rotate
		if (c14::g_inputSystem.GetKeyDown(c14::key_left))
		{
			actor.m_transform.rotation -= math::Pi * c14::g_time.deltaTime;
		}
		if (c14::g_inputSystem.GetKeyDown(c14::key_right))
		{
			actor.m_transform.rotation += math::Pi * c14::g_time.deltaTime;
		}
		// set thrust speed
		m_speed = 0;
		if (c14::g_inputSystem.GetKeyDown(c14::key_up))
		{
			m_speed = m_maxSpeed;
		}
		// turbo speed
		if (c14::g_inputSystem.GetKeyDown(c14::key_up) && c14::g_inputSystem.GetKeyDown(c14::key_space))
		{
			m_speed = m_maxSpeed * 2;
		}

		// calculate velocity
		c14::Vector2 direction{ 1, 0 };
		direction = c14::Vector2::Rotate(direction, actor.m_transform.rotation);
		c14::Vector2 velocity = direction * m_speed * c14::g_time.deltaTime;
		//move
		actor.m_transform.position += velocity;

		// edge of screen
		if (actor.m_transform.position.x > c14::g_renderer.GetWidth()) actor.m_transform.position.x = 0;
		if (actor.m_transform.position.x < 0) actor.m_transform.position.x = c14::g_renderer.GetWidth();
		if (actor.m_transform.position.y > c14::g_renderer.GetHeight()) actor.m_transform.position.y = 0;
		if (actor.m_transform.position.y < 0) actor.m_transform.position.y = c14::g_renderer.GetHeight();
	}
}

