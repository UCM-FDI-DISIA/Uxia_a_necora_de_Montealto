#include "KelpComponent.h"
#include "PlayerHealthComponent.h"
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include <Scene.h>
#include <Collider.h>

const std::string KelpComponent::id = "KelpComponent";

KelpComponent::KelpComponent() :
	collider(nullptr),
    uxia(nullptr),
    score(1){
    serializer(score, "score");
}

bool KelpComponent::initComponent(ComponentData* data) {
    //Entity* manager = scene->getEntityByHandler("GameManager");
	if (entity->hasComponent<Collider>()) {
        collider = entity->getComponent<Collider>();
        uxia = scene->getEntityByHandler("Player");
        return true;
    }
    return false;
}

void KelpComponent::fixedUpdate()
{
    if (collider->hasCollidedWith(uxia)) {
        uxia->getComponent<PlayerHealthComponent>()->addKelp(score);
        entity->setAlive(false);
    }
}


