#pragma once
#ifndef PLAYER_HEALTH_COMPONENT_H_
#define PLAYER_HEALTH_COMPONENT_H_
#include "HealthComponent.h"
#include <string>

class Transform;
class UIManager;
class LevelManager;

class PlayerHealthComponent : public HealthComponent{
private:
	std::string kelpBlueprint;
	Transform* transform;
	UIManager* ui;
	LevelManager* level;
	int maxKelpsSpawned;
	float invulnerabilityTime;
	float invulnerability;
public:

	static const std::string id;

	PlayerHealthComponent();
	bool initComponent(ComponentData* data) override;
	void damage(int damage) override;
	void dropKelps();
	void addKelp(int kelp);
	void death();
};

#endif //PLAYER_HEALTH_COMPONENT_H_