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

bool CheckpointComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<Transform>() && entity->hasComponent<Collider>()) {
		collider = entity->getComponent<Collider>();
		collider->setTrigger(true);
		collider->registerCallback(forge::onCollisionEnter, [this](Collider* self, Collider* other) {
			Entity* player = other->getEntity();
			if (player == scene->getEntityByHandler("Player")) {
				std::cout << "checkpoint\n";
				this->getEntity()->setAlive(false);
			}
			});
		return true;
	}
	else {
		reportError("El componente Enemy requiere un componente Transform y Collider");
	}
	return false;
}