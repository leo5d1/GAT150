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

	// create window
	c14::g_renderer.CreateWindow("Neumont", 800, 600);
	c14::g_renderer.setClearColor(c14::Color{ 0, 0, 0, 0 });

	// create texture
	std::shared_ptr<c14::Texture> texture = std::make_shared<c14::Texture>();
	texture->Create(c14::g_renderer, "sf2.bmp");

	// create actors
	c14::Scene scene;


	c14::Transform transform{ { 100, 100 }, 90, { 3, 3 } };
	std::unique_ptr<c14::Actor> player = std::make_unique<c14::Actor>();
	std::unique_ptr<c14::PlayerComponent> component = std::make_unique<c14::PlayerComponent>();
	player->AddComponent(std::move(component));
	std::unique_ptr<c14::SpriteComponent> scomponent = std::make_unique<c14::SpriteComponent>();
	scomponent->m_texture = texture;
	player->AddComponent(std::move(scomponent));
	std::unique_ptr<c14::PlayerComponent> pcomponent = std::make_unique<c14::PlayerComponent>();
	player->AddComponent(std::move(pcomponent));

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
			angle += 360.0f * c14::g_time.deltaTime;
			scene.Update();

			// renderer
			c14::g_renderer.BeginFrame();

			scene.Draw(c14::g_renderer);
			c14::g_renderer.Draw(texture, { 400, 300 }, angle, { 2, 2 }, {0.5f, 0.5f});

			c14::g_renderer.EndFrame();
		}
	}

	c14::g_audio.Shutdown();
	c14::g_renderer.Shutdown();
}