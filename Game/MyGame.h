#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"



class MyGame : public c14::Game, public c14::INotify
{
public:
	enum class gameState
	{
		titleScreen,
		startLevel,
		game,
		playerDead,
		gameOver
	};

public:
	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual void Update() override;
	virtual void Draw(c14::Renderer& renderer) override;

	virtual void OnNotify(const c14::Event& event) override;
	void OnAddPoints(const c14::Event& event);
	void OnPlayerDead(const c14::Event& event);

private:
	gameState m_gameState = gameState::titleScreen;
	float m_stateTimer = 0;
	int m_lives = 3;
};