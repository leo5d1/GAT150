#pragma once
#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/PlayerComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"

#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Texture.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

#include <memory>

namespace c14
{
	extern InputSystem g_inputSystem;
	extern Renderer g_renderer;
	extern Time g_time;
	extern AudioSystem g_audio;
}