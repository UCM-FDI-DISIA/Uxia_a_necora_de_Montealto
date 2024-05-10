#pragma once
#include <Component.h>
class Transform;

class DanceComponent : public Component {
protected:
	Transform* myTransform;
	float limSup, limInf;
	float originalHeight;
	bool goingUp;

public:
	static const std::string id;

	DanceComponent();
	bool initComponent(ComponentData* data) override;
	void update() override;
};