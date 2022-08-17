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

	// create window
	c14::g_renderer.CreateWindow("Neumont", 800, 600);
	c14::g_renderer.setClearColor(c14::Color{ 0, 0, 0, 0 });

	// create scene
	c14::Scene scene;

	rapidjson::Document document;
	bool success = c14::json::Load("level.txt", document);

	scene.Read(document);

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
			scene.Update();

			// renderer
			c14::g_renderer.BeginFrame();

			scene.Draw(c14::g_renderer);

			c14::g_renderer.EndFrame();
		}
	}

	c14::g_audio.Shutdown();
	c14::g_renderer.Shutdown();
}