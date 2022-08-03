#pragma once
#include "..\Math\Vector2.h"
#include <string>

struct SDL_Texture;
struct SDL_Surface;

namespace c14
{
	class Renderer;
	
	class Texture
	{
	public:
		Texture() = default;
		~Texture();

		bool Create(Renderer& renderer, const std::string& filename);

		Vector2 GetSize() const;

		friend class Renderer;

	private:
		SDL_Texture* m_texture = nullptr;
	};
}