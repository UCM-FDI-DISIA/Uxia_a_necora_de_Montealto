#include "HealthComponent.h"
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include "EnemyComponent.h"

const std::string HealthComponent::id = "HealthComponent";

HealthComponent::HealthComponent() :
	maxHealth(1),
	health(1) {
	serializer(maxHealth, "health");
	health = maxHealth;
}

void HealthComponent::onEnabled()
{
	health = maxHealth;
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
		if (entity->hasComponent<EnemyComponent>())
		{
			entity->getComponent<EnemyComponent>()->onDeath();
		}
		else {
			entity->setAlive(false);
		}
	}
}
