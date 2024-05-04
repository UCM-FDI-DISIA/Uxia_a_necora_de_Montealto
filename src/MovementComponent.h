#pragma once
#include <Component.h>
#include <Vector3.h>

class Transform;
class RigidBody;
class MovementComponent : public Component {
private:
	Transform* transform;
	RigidBody* rigidBody;
	forge::Vector3 currentDirection;
	float jumpForce;

	forge::Vector3 jumpDirection;
public:
	static const std::string id;

	MovementComponent();
	bool initComponent(ComponentData* data) override;
	void move(float direction, int axis);
	void jump();
};
