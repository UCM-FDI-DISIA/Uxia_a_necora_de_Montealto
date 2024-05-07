#include "CheckpointComponent.h"
#include <Collider.h>
#include <Serializer.h>
#include <Entity.h>
#include <Transform.h>
#include <Scene.h> 

const std::string CheckpointComponent::id = "CheckpointComponent";

CheckpointComponent:: CheckpointComponent() :
collider(nullptr),
active (true),
uxia(nullptr),
respawnpoint(forge::Vector3::ZERO){
	serializer(respawnpoint, "respawnpoint");
}

CheckpointComponent::~CheckpointComponent() {

}

void CheckpointComponent::fixedUpdate() {
	if (active && checkCollision()) {
		activateCheckpoint();
	}
}

bool CheckpointComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<Transform>() && entity->hasComponent<Collider>()) {
		collider = entity->getComponent<Collider>();
		collider->setTrigger(true);
		uxia = scene->getEntityByHandler("Player");
		return true;
	}
	else {
		reportError("El componente Enemy requiere un componente Transform y Collider");
	}
	return false;
}

bool CheckpointComponent::checkCollision() {
	if (collider->hasCollidedWith(uxia)) {
		//std::cout << "checkpoint\n";
		return true;
	}
	return false;
}

void CheckpointComponent::activateCheckpoint() {
	/*uxia->getComponent<SpawnComponent>().changeSpawn(respawnpoint);
	active = false;*/
}