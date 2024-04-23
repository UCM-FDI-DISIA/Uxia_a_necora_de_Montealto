#pragma once
#include <Component.h>
#include <Vector3.h>

class Transform;
class MovementComponent : public Component {
private:
	Transform* transform;
	forge::Vector3* currentDirection;
public:
	static const std::string id;

	MovementComponent();
	bool initComponent(ComponentData* data) override;
	void moveHorizontal(float direction);
	void jump();
};
