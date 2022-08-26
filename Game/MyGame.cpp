#include "MyGame.h"
#include "Engine.h"

void MyGame::Initialize()
{
	m_scene = std::make_unique<c14::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "scenes/prefabs.txt", "scenes/tilemap.txt", "scenes/level.txt" };

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
	
	for (int i = 0; i < 5; i++)
	{
		auto actor = c14::Factory::Instance().Create<c14::Actor>("Coin");
		actor->m_transform.position = { c14::Randomf(0, 800), 100.0f };
		actor->Initialize();

		m_scene->AddActor(std::move(actor));
	}
}

void MyGame::Shutdown()
{
	m_scene->RemoveAll();
}

void MyGame::Update()
{
	m_scene->Update();
}

void MyGame::Draw(c14::Renderer& renderer)
{
	m_scene->Draw(renderer);
}
