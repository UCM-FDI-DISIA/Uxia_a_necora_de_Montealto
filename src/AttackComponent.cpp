#include "AttackComponent.h"
#include "PlayerHealthComponent.h"
#include "PlayerInputComponent.h"
#include <Entity.h>
#include <Scene.h>
#include <Serializer.h>
#include <SceneManager.h>
#include <Collider.h>

const std::string AttackComponent::id = "AttackComponent";

AttackComponent::AttackComponent() :
	hitbox(nullptr),
	input(nullptr),
	damage(1){
	serializer(damage, "damage");
}

AttackComponent::~AttackComponent() {
	input->setAttacking(false);
}

bool AttackComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<Collider>()) {
		Entity* player = entity->getParent();
		if (player == nullptr || !player->hasComponent<PlayerInputComponent>()) {
			throwError(false, "El component Attack requiere un padre Player");
		}
		input = player->getComponent<PlayerInputComponent>();
		hitbox = entity->getComponent<Collider>();
		hitbox->registerCallback(forge::onCollisionEnter, [this](Collider* self, Collider* other) {
			if (other->getEntity()->hasComponent<PlayerHealthComponent>()) {	
				other->getEntity()->getComponent<HealthComponent>()->damage(damage);
				entity->setAlive(false);
				input->setAttacking(false);
			}
		});
		return true;
	}
	throwError(false, "El component Attack requiere un componente Collider");
}

