#pragma once
#ifndef PLAYER_HEALTH_COMPONENT_H_
#define PLAYER_HEALTH_COMPONENT_H_
#include "HealthComponent.h"
#include <string>

class Transform;

class PlayerHealthComponent : public HealthComponent{
private:
	std::string kelpBlueprint;
	Transform* transform;
	int maxKelpsSpawned;
public:

	static const std::string id;

	PlayerHealthComponent();
	bool initComponent(ComponentData* data) override;
	void damage(int damage) override;
	void dropKelps();
	void addKelp(int kelp);
	void onDeath();
};

#endif //PLAYER_HEALTH_COMPONENT_H_