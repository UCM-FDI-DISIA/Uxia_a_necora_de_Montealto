#include "PlayerHealthComponent.h"
#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include "LifeTimeComponent.h"
#include "UIManager.h"
#include "LevelManager.h"
#include <TimeForge.h>
#include <ComponentData.h>
#include <Entity.h>
#include <Animator.h>
#include <Scene.h>
#include <Serializer.h>
#include <SceneManager.h>
#include <RigidBody.h>
#include <Transform.h>
#include <Random.h>

const std::string PlayerHealthComponent::id = "PlayerHealthComponent";

PlayerHealthComponent::PlayerHealthComponent(): 
	maxKelpsSpawned(10),
	invulnerability(1.5f),
	invulnerabilityTime(0),
	transform(nullptr), 
	ui(nullptr), 
	level(nullptr) {
	health = 0;
	maxHealth = 99;
	serializer(kelpBlueprint, "kelpBlueprint");
	serializer(maxKelpsSpawned, "kelpsSpawnLimit");
	serializer(maxHealth, "maxKelp");
	serializer(invulnerability, "invulnerability");
}

bool PlayerHealthComponent::initComponent(ComponentData* data)
{
	if(entity->hasComponent<Transform>())
	{
		transform = entity->getComponent<Transform>();
		Entity* manager = scene->getEntityByHandler("manager");
		if (manager != nullptr) {
			ui = manager->getComponent<UIManager>();
			level = manager->getComponent<LevelManager>();
			if (ui != nullptr && level != nullptr) {
				health = level->getKelp();
				return true;
			}
		}
		reportError("No se han encontrado los Managers");
	}
	else
	{
		reportError("El component PlayerHealth requiere un componente Transform");
	}
	return false;

}

void PlayerHealthComponent::damage(int damage) {
	if (forge::Time::time >= invulnerabilityTime && damage < 100) {
		if (health > 0) {
			dropKelps();
			health = 0;
			ui->updateKelpText(health);
			level->setKelp(health);
		}
		else {
			death();
		}
		invulnerabilityTime = (float)forge::Time::time + invulnerability;
	}
	else {
		death();
		health = 0;
		ui->updateKelpText(health);
		level->setKelp(health);
	}
}

void PlayerHealthComponent::dropKelps() {
	forge::Random& random = *forge::Random::GetInstance();
	for (int i = 0; i < std::min(health, maxKelpsSpawned); i++) {
		forge::Vector3 newPos = random.getRandomVector();
		newPos.setZ(0);
		newPos = transform->getGlobalPosition() + (newPos * random.generateRange(7.0f, 10.0f));
		Entity* kelp = sceneManager.instantiateBlueprint(kelpBlueprint, newPos);
		if (kelp == nullptr) {
			reportError("No se ha podido instanciar el Kelp");
			return;
		}
		ComponentData data = ComponentData(LifeTimeComponent::id);
		data.add("lifetime", 2.5f);
		kelp->addComponent(&data);
	}
}

void PlayerHealthComponent::addKelp(int kelp) {
	health += kelp;
	if (health > maxHealth) {
		health = maxHealth;
	}
	ui->updateKelpText(health);
	level->setKelp(health);
}

void PlayerHealthComponent::death() {
	entity->getComponent<PlayerInputComponent>()->setDead(true);
	entity->getComponent<Animator>()->setActive("my_animation", false);
	entity->getComponent<MovementComponent>()->fullStop();
	
	ui->enableDeathText(true);
}

void PlayerHealthComponent::resetKelp() {
	level->setKelp(0);
}