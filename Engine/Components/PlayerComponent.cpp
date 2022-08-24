#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace c14
{
	void PlayerComponent::Initialize()
	{
		auto component = m_owner->GetComponent<CollisionComponent>();
		if (component)
		{
			component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

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

		// jump
		if (g_inputSystem.GetKeyState(key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * 500);
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

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		std::cout << "Player enter\n";
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "Player exit\n";
	}
}

