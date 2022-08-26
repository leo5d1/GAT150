#pragma once
#include "Framework/Game.h"

class MyGame : public c14::Game
{
public:
	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual void Update() override;
	virtual void Draw(c14::Renderer& renderer) override;


};