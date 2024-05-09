#pragma once
#ifndef PLAYER_INPUT_CONTROLLER_H
#define PLAYER_INPUT_CONTROLLER_H

#include <Component.h>

class Input;
class MovementComponent;

class PlayerInputComponent : public Component {
private:
	Input& input;
	MovementComponent* movement;
	float speed;
	bool attacking;
	float attackOffset;
	short lastDirection;

public:
	static const std::string id;

	PlayerInputComponent();
	bool initComponent(ComponentData* data) override;
	void update() override;

	void setAttacking(bool attack);
};
#endif // !PLAYER_INPUT_CONTROLLER_H
