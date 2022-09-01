#include "MyGame.h"
#include "Engine.h"
#include "GameComponents/EnemyComponent.h"

void MyGame::Initialize()
{
	REGISTER_CLASS(EnemyComponent);


	m_scene = std::make_unique<c14::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "scenes/prefabs.txt", "scenes/level.txt", "scenes/tilemap.txt" };

	for (auto sceneName : sceneNames)
	{
		bool success = c14::json::Load(sceneName, document);
		if (!success)
		{
			LOG("error could not load scene %s", sceneName.c_str());
			continue;
		}

		m_scene->Read(document);
	}
	m_scene->Initialize();
	
	

	c14::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&MyGame::OnNotify, this, std::placeholders::_1));
	c14::g_eventManager.Subscribe("EVENT_PLAYER_DEAD", std::bind(&MyGame::OnNotify, this, std::placeholders::_1));
}

void MyGame::Shutdown()
{
	m_scene->RemoveAll();
}

void MyGame::Update()
{
	switch (m_gameState)
	{
	case gameState::titleScreen:
		m_scene->GetActorFromName("Title")->SetActive(true);
		m_lives = 3;

		if (c14::g_inputSystem.GetKeyState(c14::key_enter) == c14::InputSystem::State::Pressed)
		{
			m_scene->GetActorFromName("Title")->SetActive(false);

			m_gameState = gameState::startLevel;
		}

		break;

	case gameState::startLevel:
		m_scene->GetActorFromName("Score")->SetActive(true);
		m_scene->GetActorFromName("Health")->SetActive(true);

		for (int i = 0; i < 10; i++)
		{
			auto actor = c14::Factory::Instance().Create<c14::Actor>("Coin");
			actor->m_transform.position = { c14::Randomf(0, 800), 100.0f };
 			actor->Initialize();

			m_scene->AddActor(std::move(actor));
		}
		for (int i = 0; i < 3; i++)
		{
			auto actor = c14::Factory::Instance().Create<c14::Actor>("Demon");
			actor->m_transform.position = { c14::Randomf(0, 800), 100.0f };
			actor->Initialize();

			m_scene->AddActor(std::move(actor));
		}
		{
			auto actor = c14::Factory::Instance().Create<c14::Actor>("Player");
			actor->m_transform.position = { 400.0f, 250.0f };
			actor->Initialize();

			m_scene->AddActor(std::move(actor));
		}
		m_gameState = gameState::game;
		break;

	case gameState::game:
	{
		auto score = m_scene->GetActorFromName("Score");
		auto component = score->GetComponent<c14::TextComponent>();
		if (component)
		{
			component->SetText(std::to_string(m_score));
		}
	}
	{
		auto health = m_scene->GetActorFromName("Health");
		auto component = health->GetComponent<c14::TextComponent>();
		auto player = m_scene->GetActorFromName("Player");
		if (player)
		{
			auto pcomponent = player->GetComponent<c14::PlayerComponent>();
			if (component)
			{
				component->SetText(std::to_string((int)pcomponent->health));
			}
		}
	}
		break;

	case gameState::playerDead:

		m_scene->GetActorFromName("Death")->SetActive(true);
		
		m_stateTimer -= c14::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_scene->GetActorFromName("Death")->SetActive(false);
			m_gameState = (m_lives > 0) ? gameState::startLevel : gameState::gameOver;
		}
		break;

	case gameState::gameOver:
		break;

	default:
		break;
	}

	m_scene->Update();
}

void MyGame::Draw(c14::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void MyGame::OnAddPoints(const c14::Event& event)
{
	AddPoints(std::get<int>(event.data));
}

void MyGame::OnPlayerDead(const c14::Event& event)
{
	m_gameState = gameState::playerDead;
	m_lives--;
	m_stateTimer = 3;
}

void MyGame::OnNotify(const c14::Event& event)
{
	if (event.name == "EVENT_ADD_POINTS")
	{
		OnAddPoints(event);
	}

	if (event.name == "EVENT_PLAYER_DEAD")
	{
		OnPlayerDead(event);
	}
}
