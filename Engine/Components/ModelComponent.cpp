#include "ModelComponent.h"
#include "Renderer/Model.h"
#include "Framework/Actor.h"

namespace c14
{
	void ModelComponent::Update()
	{

	}
	void ModelComponent::Draw(Renderer& renderer)
	{
		//renderer.Draw(m_texture, m_owner->m_transform);
		m_model->Draw(renderer, m_owner->m_transform);
	}
}
