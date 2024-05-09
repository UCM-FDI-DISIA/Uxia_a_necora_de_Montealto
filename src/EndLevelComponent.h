#pragma once
#include <Component.h>
#include <Vector3.h>

class Collider;
class LevelManager;

class EndLevelComponent : public Component
{
private:
	int nextLevel;
	Collider* collider;
	LevelManager* level;
public:
	static const std::string id;

	EndLevelComponent();

	~EndLevelComponent();

	bool initComponent(ComponentData* data) override;
};

