#pragma once
#include "RenderComponent.h"
#include "Math/Rect.h"

namespace c14
{
	class Texture;

	class SpriteComponent : public RenderComponent
	{
	public:
		CLASS_DECLARTATION(SpriteComponent)

		virtual void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		virtual void Draw(Renderer& renderer) override;

	public:
		Rect source;
		std::shared_ptr<Texture> m_texture;

	};
}