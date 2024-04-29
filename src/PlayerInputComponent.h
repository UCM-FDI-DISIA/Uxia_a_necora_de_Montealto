#pragma once
#include <Component.h>

class Input;
class MovementComponent;
class PlayerInputComponent : public Component {
private:
	Input& input;
	MovementComponent* movement;
	float speed;
public:
	static const std::string id;

	PlayerInputComponent();
	bool initComponent(ComponentData* data) override;
	void update() override;
};
