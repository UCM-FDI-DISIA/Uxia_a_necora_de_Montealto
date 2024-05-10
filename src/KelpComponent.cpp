#include "KelpComponent.h"
#include "PlayerHealthComponent.h"
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include <Scene.h>
#include <Collider.h>

const std::string KelpComponent::id = "KelpComponent";

KelpComponent::KelpComponent() :
    score(1) {
    serializer(score, "score");
}

KelpComponent::~KelpComponent()
{
}

bool KelpComponent::initComponent(ComponentData* data) {
    if (entity->hasComponent<Collider>()) {
        Collider* collider = entity->getComponent<Collider>();
        collider->registerCallback(forge::onCollisionEnter, [this](Collider* self, Collider* other) {
            Entity* player = other->getEntity();
            if (player->hasComponent<PlayerHealthComponent>()) {
                player->getComponent<PlayerHealthComponent>()->addKelp(this->score);
                this->getEntity()->setAlive(false);
            }
            });
        return true;
    }
    return false;
}
