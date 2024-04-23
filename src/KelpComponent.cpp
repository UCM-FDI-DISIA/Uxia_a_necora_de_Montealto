#include "KelpComponent.h"
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include <Scene.h>
#include <Collider.h>

const std::string KelpComponent::id = "KelpComponent";

KelpComponent::KelpComponent() :
	collider(nullptr),
    gameManager(nullptr),
    score(1){
       // serializer(score,"score");
}

bool KelpComponent::initComponent(ComponentData* data) {
 //   Entity* manager = scene->getEntityByHandler("GameManager");
	//if (/*manager->hasComponent<GameManager>() && */ entity->hasComponent<Collider>()) {
 //       //gameManager = manager->getComponent<GameManager>();
 //       collider = entity->getComponent<Collider>();
 //       collider->registerCallback([] (Collider* self, Collider* other){
 //           //TODO cuando se arreglen los callbacks
 //       });
        return true;
 //   }
	//return false;
}


