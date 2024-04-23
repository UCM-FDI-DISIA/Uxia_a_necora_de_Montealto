#include "EnemyComponent.h"
#include "MovementComponent.h"
#include <RigidBody.h>
#include <ComponentData.h>
#include <Entity.h>

EnemyComponent::EnemyComponent() :
damage(0),
radius(0),
sign(1),
movementComponent(nullptr),
rb(nullptr),
p1(forge::Vector3::ZERO),
p2(forge::Vector3::ZERO){

}

EnemyComponent::~EnemyComponent() {

}

void EnemyComponent::update() {
	/*
	if (p1.getX() >= movementComponent->getTransform()->getPosition().getX()
	|| p2.getX() <= movementComponent->getTransform()->getPosition().getX()) {
		sign = -sign;
	}
	float distance = movementComponent->getTransform()->getPosition().getX() - 
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
	}
	*/
}

bool EnemyComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<RigidBody>() && entity->hasComponent<MovementComponent>()) {
		rb = entity->getComponent<RigidBody>();
		movementComponent = entity->getComponent<MovementComponent>();
		if (data->has("radius")) {
			setRadius(data->get<float>("radius"));
		}
		if (data->has("damage")) {
			setDamage(data->get<float>("damage"));
		}
		return true;
	}
	return false;
}

bool EnemyComponent::checkAttack() {
	/*
	if (rb->hasCollidedWith(rb) {
		return true;
	}
	return false;
	*/
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