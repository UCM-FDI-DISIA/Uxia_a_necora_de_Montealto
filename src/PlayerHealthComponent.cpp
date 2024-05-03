#include "PlayerHealthComponent.h"
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include <SceneManager.h>
#include <Transform.h>
#include <Random.h>

const std::string PlayerHealthComponent::id = "PlayerHealthComponent";

PlayerHealthComponent::PlayerHealthComponent(): 
	maxKelpsSpawned(10), 
	transform(nullptr),
	sceneManager(*SceneManager::GetInstance()),
	random(*forge::Random::GetInstance()) {
	health = 0;
	maxHealth = 99;
	serializer(kelpBlueprint, "kelpBlueprint");
	serializer(maxKelpsSpawned, "kelpsSpawnLimit");
	serializer(maxHealth, "maxKelp");
}

bool PlayerHealthComponent::initComponent(ComponentData* data)
{
	if(entity->hasComponent<Transform>())
	{
		transform = entity->getComponent<Transform>();
		return true;
	}
	else
	{
		reportError("El component PlayerHealth requiere un componente Transform");
	}
	return false;

}

void PlayerHealthComponent::damage(int damage){
	if (health > 0) {
		dropKelps();
		health = 0;
	}
	else {
		//muere
	}
}

void PlayerHealthComponent::dropKelps() {
	for (int i = 0; i < std::min(health, maxKelpsSpawned); i++) {
		forge::Vector3 newDelta = random.getRandomVector();
		newDelta.setZ(0);
		if (sceneManager.instantiateBlueprint("Kelp", transform->getGlobalPosition() + (newDelta *random.generateRange(1.0f, 5.0f))) == nullptr) {
			reportError("No se ha podido instanciar el Kelp");
			return;
		}
	}
}

void PlayerHealthComponent::addKelp(int kelp) {
	health += kelp;
	if (health > maxHealth) {
		health = maxHealth;
	}
}