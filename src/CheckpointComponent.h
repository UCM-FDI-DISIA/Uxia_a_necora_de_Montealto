#pragma once
#include <Component.h>
#include <Vector3.h>

class Collider;
class LevelManager;

class CheckpointComponent : public Component
{
private:
	forge::Vector3 respawnpoint;
	Collider* collider;
	LevelManager* level;
public:
	static const std::string id;

	CheckpointComponent();

	~CheckpointComponent();

	bool initComponent(ComponentData* data) override;
};
