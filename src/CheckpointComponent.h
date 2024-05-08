#pragma once
#include <Component.h>
#include <Vector3.h>

class Collider;

class CheckpointComponent : public Component
{
private:
	forge::Vector3 respawnpoint;
	bool active;
	Collider* collider;
	Entity* uxia;
public:
	static const std::string id;

	CheckpointComponent();

	~CheckpointComponent();

	bool initComponent(ComponentData* data) override;
};

