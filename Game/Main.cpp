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
	c14::g_resources.Initialize();
	c14::g_physicsSystem.Initialize();

	c14::Engine::Instance().Register();

	// create window
	c14::g_renderer.CreateWindow("Neumont", 800, 600);
	c14::g_renderer.setClearColor(c14::Color{ 20, 20, 20, 0 });

	// create scene
	c14::Scene scene;

	rapidjson::Document document;
	bool success = c14::json::Load("levels/level.txt", document);

	scene.Read(document);
	scene.Initialize();

	for (int i = 0; i < 5; i++)
	{
		auto actor = c14::Factory::Instance().Create<c14::Actor>("Coin");
		actor->m_transform.position = { c14::Randomf(0, 800), 100.0f};
		actor->Initialize();

		scene.AddActor(std::move(actor));
	}
	
	bool quit = false;
	while (!quit)
	{
			
		//update (engine)
		c14::g_time.Tick();
		c14::g_inputSystem.Update();
		c14::g_audio.Update();
		c14::g_physicsSystem.Update();

		if (c14::g_inputSystem.GetKeyDown(c14::key_escape)) { quit = true; }

		// update Scene
 		scene.Update();

		// renderer
		
		c14::g_renderer.BeginFrame();
		
		scene.Draw(c14::g_renderer);
		
		c14::g_renderer.EndFrame();
	}
	
	scene.RemoveAll();

	c14::g_physicsSystem.Shutdown();
	c14::g_resources.Shutdown();
	c14::g_inputSystem.Shutdown();
	c14::g_audio.Shutdown();
	c14::g_renderer.Shutdown();
}