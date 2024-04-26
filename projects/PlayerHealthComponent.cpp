#include "PlayerHealthComponent.h"
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>

const std::string PlayerHealthComponent::id = "PlayerHealthComponent";

PlayerHealthComponent::PlayerHealthComponent(): 
	maxKelpsSpawned(10), 
	transform(nullptr) {
	serializer(kelpBlueprint, "kelpBlueprint");
	serializer(maxKelpsSpawned, "kelpsSpawnLimit");
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
	if (kelpBlueprint != "") {

		for (int i = 0; i < std::min(health, maxKelpsSpawned); i++) {
			//spawnear las algas
		}
	}
}