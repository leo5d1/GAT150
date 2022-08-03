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

	// create texture
	std::shared_ptr<c14::Texture> texture = std::make_shared<c14::Texture>();
	texture->Create(c14::g_renderer, "sf2.bmp");

	// create window
	c14::g_renderer.CreateWindow("Neumont", 800, 600);
	c14::g_renderer.setClearColor(c14::Color{ 30, 30, 30, 0 });


	{
		bool quit = false;
		while (!quit)
		{
			//update (engine)
			c14::g_time.Tick();
			c14::g_inputSystem.Update();
			c14::g_audio.Update();

			if (c14::g_inputSystem.GetKeyDown(c14::key_escape)) { quit = true; }

			// renderer
			c14::g_renderer.BeginFrame();

			c14::g_renderer.Draw(texture, { 40, 30 }, 0);

			c14::g_renderer.EndFrame();
		}
	}

	c14::g_audio.Shutdown();
	c14::g_renderer.Shutdown();
}