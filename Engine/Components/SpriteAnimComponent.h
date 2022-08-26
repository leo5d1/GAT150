#pragma once
#include "RenderComponent.h"
#include "Math/Rect.h"

namespace c14
{
	class Texture;

	class SpriteAnimComponent : public RenderComponent
	{
	public:
		CLASS_DECLARTATION(SpriteAnimComponent)

		virtual void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		virtual void Draw(Renderer& renderer) override;

	public:
		// json read ins
		float fps = 0;
		int num_columns = 0;
		int num_rows = 0;

		int start_frame = 0;
		int end_frame = 0;

		// internals
		int frame = 0;
		float frameTimer = 0;

		Rect source;
		std::shared_ptr<Texture> m_texture;

	};
}