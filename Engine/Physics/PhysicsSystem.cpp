#include "PhysicsSystem.h"

namespace c14
{
	void PhysicsSystem::Initialize()
	{
		b2Vec2 gravity{ 0, 10 };
		world = std::make_unique<b2World>(gravity);
	}

	void PhysicsSystem::Shutdown()
	{
	}

	void PhysicsSystem::Update()
	{
	}
}