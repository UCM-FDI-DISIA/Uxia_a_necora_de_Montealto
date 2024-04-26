#include "KelpComponent.h"
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include <Scene.h>
#include <Collider.h>

const std::string KelpComponent::id = "KelpComponent";

KelpComponent::KelpComponent() :
	collider(nullptr),
    score(1){
    serializer(score, "score");
}

bool KelpComponent::initComponent(ComponentData* data) {
    Entity* manager = scene->getEntityByHandler("GameManager");
	if (entity->hasComponent<Collider>()) {
        collider = entity->getComponent<Collider>();
        collider->registerCallback([] (Collider* self, Collider* other){
            //TODO cuando se arreglen los callbacks
        });
        return true;
    }
    return false;
}


