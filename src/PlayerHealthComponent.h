#pragma once
#ifndef PLAYER_HEALTH_COMPONENT_H_
#define PLAYER_HEALTH_COMPONENT_H_
#include "HealthComponent.h"
#include <string>

class Transform;
class SceneManager;
namespace forge {
	class Random;
}

class PlayerHealthComponent : public HealthComponent{
private:
	std::string kelpBlueprint;
	Transform* transform;
	int maxKelpsSpawned;
	SceneManager& sceneManager;
	forge::Random& random;
public:

	static const std::string id;

	PlayerHealthComponent();
	bool initComponent(ComponentData* data) override;
	void damage(int damage) override;
	void dropKelps();
	void addKelp(int kelp);
};

#endif //PLAYER_HEALTH_COMPONENT_H_