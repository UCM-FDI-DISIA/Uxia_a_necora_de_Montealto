#include "PlayerInputComponent.h"
#include <Input.h>
#include <Entity.h>
#include <Vector2.h>
#include "MovementComponent.h"
#include <ForgeError.h>
#include <Serializer.h>

const std::string PlayerInputComponent::id = "PlayerInputComponent";

PlayerInputComponent::PlayerInputComponent(): 
	input(*Input::GetInstance()),
	movement(nullptr),
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

	if (input.keyPressed(K_A)) {
		movement->move(-speed, 0);
	}
	else if (input.keyPressed(K_D)) {
		movement->move(speed, 0);
	}

	//Salto
	if (input.keyDown(K_W)) {
		movement->jump();
	}
}