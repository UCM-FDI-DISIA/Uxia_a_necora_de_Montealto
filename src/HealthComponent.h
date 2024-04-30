#pragma once
#ifndef HEALTH_COMPONENT_H_
#define HEALTH_COMPONENT_H_
#include <Component.h>

class HealthComponent : public Component {
protected:
	int health;
	int maxHealth;
public:

	static const std::string id;

	HealthComponent();
	void onEnabled() override;
	bool initComponent(ComponentData* data) override;
	virtual void damage(int damage);
};

#endif // !HEALTH_COMPONENT_H_