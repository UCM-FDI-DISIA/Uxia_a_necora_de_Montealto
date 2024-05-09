#include "EndLevelComponent.h"
#include "PlayerHealthComponent.h"
#include "LevelManager.h"
#include <Collider.h>
#include <Serializer.h>
#include <Entity.h>
#include <Transform.h>
#include <Scene.h> 

const std::string EndLevelComponent::id = "EndLevelComponent";

EndLevelComponent::EndLevelComponent() :
	collider(nullptr),
	level(nullptr),
	nextLevel(1){
	serializer(nextLevel, "nextLevel");
}

EndLevelComponent::~EndLevelComponent() {

}

bool EndLevelComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<Transform>() && entity->hasComponent<Collider>()) {
		Entity* manager = scene->getEntityByHandler("manager");
		if (manager != nullptr) {
			level = manager->getComponent<LevelManager>();
			if (level == nullptr) {
				return false;
			}
		}
		else {
			reportError("No se han encontrado los Managers");
		}
		collider = entity->getComponent<Collider>();
		collider->setTrigger(true);
		collider->registerCallback(forge::onCollisionEnter, [this](Collider* self, Collider* other) {
			Entity* player = other->getEntity();
			if (player->hasComponent<PlayerHealthComponent>()) {
				std::cout << "endLevel\n";
				this->getEntity()->setAlive(false);
				level->changeLevel(nextLevel);
			}
			});
		return true;
	}
	else {
		reportError("El componente Enemy requiere un componente Transform y Collider");
	}
	return false;
}