#include "AttackComponent.h"
#include <Entity.h>
#include <Serializer.h>
#include <SceneManager.h>
#include <Collider.h>

const std::string AttackComponent::id = "AttackComponent";

AttackComponent::AttackComponent() :
	hitbox(nullptr),
	damage(1) {
	serializer(damage, "damage");
}

AttackComponent::~AttackComponent() {

}
bool AttackComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<Collider>()) {
		hitbox = entity->getComponent<Collider>();
		hitbox->registerCallback(forge::onCollisionEnter, [this](Collider* self, Collider* other) {

		});
		return true;
	}
	else reportError("El component Attack requiere un componente Collider");
	return false;
}
//
//bool AttackComponent::checkAttack() {
//}

void AttackComponent::attack() {

}

