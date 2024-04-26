#include "HealthComponent.h"
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>

const std::string HealthComponent::id = "HealthComponent";

HealthComponent::HealthComponent()
{
	serializer(maxHealth, "health");
}

bool HealthComponent::initComponent(ComponentData* data)
{
    return true;
}

void HealthComponent::damage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		entity->setAlive(false);
	}
}
