#pragma once
#include "Components/CharacterComponent.h"

class EnemyComponent : public c14::CharacterComponent
{
public:
	CLASS_DECLARATION(EnemyComponent)

		virtual void Initialize() override;
	virtual void Update() override;

	virtual void OnCollisionEnter(c14::Actor* other) override;
	virtual void OnCollisionExit(c14::Actor* other) override;

	virtual void OnNotify(const c14::Event& event) override;

	virtual bool Write(const rapidjson::Value& value) const override;
	virtual bool Read(const rapidjson::Value& value) override;

protected:
};