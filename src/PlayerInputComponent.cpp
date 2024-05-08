#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include <Input.h>
#include <Entity.h>
#include <Vector2.h>
#include <ForgeError.h>
#include <Serializer.h>
#include <SceneManager.h>
#include <Transform.h>

const std::string PlayerInputComponent::id = "PlayerInputComponent";

PlayerInputComponent::PlayerInputComponent(): 
	input(*Input::GetInstance()),
	movement(nullptr),
	attacking(false),
	speed(1){
	serializer(speed, "speed");
}

bool PlayerInputComponent::initComponent(ComponentData* data)
{
	if (entity->hasComponent<MovementComponent>()) {
		movement = entity->getComponent<MovementComponent>();
		return true;
	}
	else {
		reportError("El componente PlayerInput necesita un componente Movement");
	}
	return false;
}

void PlayerInputComponent::update() {
	//Movimiento A / D

	if (input.keyUp(K_A) || input.keyUp(K_D)) { 
		movement->stop();
	}

	if (input.keyPressed(K_A)) {
		movement->move(-speed, 0);
	}
	else if (input.keyPressed(K_D)) {
		movement->move(speed, 0);
	}
	else if (input.keyPressed(K_SPACE) && !attacking) {
		sceneManager.instantiateBlueprint("Attack", entity->getComponent<Transform>()->getGlobalPosition() + forge::Vector3(0.5, 0, 0), entity);
		attacking = true;
	}

	//Salto
	if (input.keyDown(K_W)) {
		movement->jump();
	}
}

void PlayerInputComponent::setAttacking(bool attack) {
	attacking = attack;
}