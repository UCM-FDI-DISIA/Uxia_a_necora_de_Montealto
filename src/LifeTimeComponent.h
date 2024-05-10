#pragma once
#ifndef LIFETIME_COMPONENT_H_
#define LIFETIME_COMPONENT_H_
#include <Component.h>

class LifeTimeComponent : public Component {
private:
	double lifetime;

public:

	static const std::string id;

	LifeTimeComponent();

	void update() override;
};
#endif //LIFETIME_COMPONENT_H_