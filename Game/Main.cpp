#include "Engine.h"
#include <iostream>

using namespace std;

int main()
{
	c14::InitializeMemory();

	c14::SetFilePath("../Assets");

	// initialize systems
	c14::g_renderer.Initialize();
	c14::g_inputSystem.Initialize();
	c14::g_audio.Initialize();
	c14::g_resourcemanager.Initialize();

	// create window
	c14::g_renderer.CreateWindow("Neumont", 800, 600);
	c14::g_renderer.setClearColor(c14::Color{ 0, 0, 0, 0 });

	// load assets
	//std::shared_ptr<c14::Texture> texture = std::make_shared<c14::Texture>();
	//texture->Create(c14::g_renderer, "Textures/spaceshipblue.png");
	std::shared_ptr<c14::Texture> texture = c14::g_resourcemanager.Get<c14::Texture>("Textures/spaceshipblue.png", c14::g_renderer);

	//std::shared_ptr<c14::Model> model = std::make_shared<c14::Model>();
	//model->Create("Models/Player.txt");
	std::shared_ptr<c14::Model> model = c14::g_resourcemanager.Get<c14::Model>("Models/Player.txt");
	//std::shared_ptr<c14::Model> model2 = c14::g_resourcemanager.Get<c14::Model>("Models/Player.txt");

	// create audio
	c14::g_audio.AddAudio("laser", "Audio/laser.wav");

	// create scene
	c14::Scene scene;

	// Player Character
	c14::Transform transform{ { 400, 300 }, 90, { 3, 3 } };
	std::unique_ptr<c14::Actor> player = std::make_unique<c14::Actor>(transform);

	// player comp
	std::unique_ptr<c14::PlayerComponent> Pcomponent = std::make_unique<c14::PlayerComponent>();
	player->AddComponent(std::move(Pcomponent));

	// sprite comp
	//std::unique_ptr<c14::SpriteComponent> Scomponent = std::make_unique<c14::SpriteComponent>();
	//Scomponent->m_texture = texture;
	//player->AddComponent(std::move(Scomponent));

	// model comp
	std::unique_ptr<c14::ModelComponent> Mcomponent = std::make_unique<c14::ModelComponent>();
	Mcomponent->m_model = model;
	player->AddComponent(std::move(Mcomponent));

	// audio comp
	std::unique_ptr<c14::AudioComponent> Acomponent = std::make_unique<c14::AudioComponent>();
	Acomponent->m_soundname = "laser";
	player->AddComponent(std::move(Acomponent));

	// physics comp
	std::unique_ptr<c14::PhysicsComponent> PHcomponent = std::make_unique<c14::PhysicsComponent>();
	PHcomponent->m_damping = 0.98f;
	player->AddComponent(std::move(PHcomponent));

	c14::Transform transformC{ { 4, 3 }, 0, { 1, 1 } };
	std::unique_ptr<c14::Actor> child = std::make_unique<c14::Actor>(transformC);

	std::unique_ptr<c14::ModelComponent> McomponentC = std::make_unique<c14::ModelComponent>();
	McomponentC->m_model = c14::g_resourcemanager.Get<c14::Model>("Models/Player.txt");
	child->AddComponent(std::move(McomponentC));

	player->AddChild(std::move(child));

	scene.Add(std::move(player));

	float angle = 0;

	{
		bool quit = false;
		while (!quit)
		{
			//update (engine)
			c14::g_time.Tick();
			c14::g_inputSystem.Update();
			c14::g_audio.Update();

			if (c14::g_inputSystem.GetKeyDown(c14::key_escape)) { quit = true; }

			// update Scene
			//angle += 360.0f * c14::g_time.deltaTime;
			scene.Update();

			// renderer
			c14::g_renderer.BeginFrame();

			scene.Draw(c14::g_renderer);
			//c14::g_renderer.Draw(texture, { 400, 300 }, angle, { 2, 2 }, {0.5f, 0.5f});

			c14::g_renderer.EndFrame();
		}
	}

	c14::g_audio.Shutdown();
	c14::g_renderer.Shutdown();
}