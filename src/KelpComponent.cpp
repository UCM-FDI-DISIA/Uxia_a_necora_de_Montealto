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
    score(1){
    serializer(score, "score");
}

bool KelpComponent::initComponent(ComponentData* data) {
    Entity* manager = scene->getEntityByHandler("GameManager");
	if (entity->hasComponent<Collider>()) {
        collider = entity->getComponent<Collider>();
        //collider->registerCallback(Collider::onCollisionEnter, [this] (Collider* self, Collider* other){
        //    Entity* player = other->getEntity();
        //    if (player->hasComponent<PlayerHealthComponent>()) {
        //        player->getComponent<PlayerHealthComponent>()->addKelp(this->score);
        //        this->getEntity()->setAlive(false);
        //    }
        //});
        return true;
    }
    return false;
}


