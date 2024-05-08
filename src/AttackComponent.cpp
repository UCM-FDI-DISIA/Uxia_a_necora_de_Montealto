#include "AttackComponent.h"
#include "PlayerHealthComponent.h"
#include "PlayerInputComponent.h"
#include <Entity.h>
#include <Serializer.h>
#include <SceneManager.h>
#include <Collider.h>
#include <TimeForge.h>

const std::string AttackComponent::id = "AttackComponent";

AttackComponent::AttackComponent() :
	hitbox(nullptr),
	lifetime(500),
	damage(1){
	serializer(damage, "damage");
	serializer(lifetime, "lifetime");
}

AttackComponent::~AttackComponent() {

}
bool AttackComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<Collider>()) {
		hitbox = entity->getComponent<Collider>();
		hitbox->registerCallback(forge::onCollisionEnter, [this](Collider* self, Collider* other) {
			if (other->getEntity()->hasComponent<PlayerHealthComponent>()) {
				other->getEntity()->getComponent<PlayerHealthComponent>()->damage(damage);
			}
			else if (other->getEntity()->hasComponent<HealthComponent>()) {
				other->getEntity()->getComponent<HealthComponent>()->damage(damage);
			}
		});
			return true;
	}
	else reportError("El component Attack requiere un componente Collider");
	return false;
}

void AttackComponent::fixedUpdate() {
	lifetime -= forge::Time::deltaTime;	
	if (lifetime <= 0.0) {
		if (entity->getParent()->getComponent<PlayerInputComponent>()) {
			entity->getParent()->getComponent<PlayerInputComponent>()->setAttacking(false);
		}
		entity->setAlive(false);
	}
}

