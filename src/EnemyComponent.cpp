#include "EnemyComponent.h"
#include "MovementComponent.h"
#include <RigidBody.h>
#include <Entity.h>
#include <Serializer.h>
#include <Transform.h>

const std::string EnemyComponent::id = "EnemyComponent";


EnemyComponent::EnemyComponent() :
	damage(0),
	radius(0),
	sign(1),
	movementComponent(nullptr),
	rb(nullptr),
	p1(forge::Vector3::ZERO),
	p2(forge::Vector3::ZERO) {
	serializer(p1, "p1");
	serializer(p2, "p2");
	serializer(damage, "damage");
	serializer(radius, "radius");
}

EnemyComponent::~EnemyComponent() {

}

void EnemyComponent::update() {
	//if (p1.getX() >= entity->getComponent<Transform>()->getGlobalPosition().getX()
	//	|| p2.getX() <= entity->getComponent<Transform>()->getGlobalPosition().getX()) {
	//	sign = -sign;
	//}
	//movementComponent->moveHorizontal(1.0f * sign);
	//std::cout << entity->getComponent<Transform>()->getPosition().getX() << "\n";
	/*float distance = movementComponent->getTransform()->getPosition().getX() -
	uxia->movementComponent->transform->getPosition().getX();
	if((abs)distance <= radius && radius != 0){
		if(distance >= 0){
			movementComponent->moveHorizontal(speed);
		}
		else{
			movementComponent->moveHorizontal(-speed);
		}
	}
	else{
		movementComponent->moveHorizontal(speed * sign);
	}
	if(checkAttack()){
		attack();
	}*/
}

bool EnemyComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<RigidBody>() && entity->hasComponent<MovementComponent>()) {
		rb = entity->getComponent<RigidBody>();
		movementComponent = entity->getComponent<MovementComponent>();
		return true;
	}
	return false;
}

bool EnemyComponent::checkAttack() {
	/*
	if (rb->hasCollidedWith(rb) {
		return true;
	}
	*/
	return false;
}

void EnemyComponent::attack() {
	// uxia->healthComponent()->getDamage(damage);
}

void EnemyComponent::setRadius(float r) {
	radius = r;
}

void EnemyComponent::setDamage(float d) {
	damage = d;
}