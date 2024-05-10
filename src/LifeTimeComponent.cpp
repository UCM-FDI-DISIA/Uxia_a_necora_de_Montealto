#include "LifeTimeComponent.h"
#include <Serializer.h>
#include <TimeForge.h>
#include <Entity.h>

const std::string LifeTimeComponent::id = "LifeTimeComponent";

LifeTimeComponent::LifeTimeComponent() : 
	lifetime(0.5f) {
	serializer(lifetime, "lifetime");
}

void LifeTimeComponent::update() {
	lifetime -= forge::Time::deltaTime;
	if (lifetime <= 0.0f) {
		entity->setAlive(false);
	}
}
