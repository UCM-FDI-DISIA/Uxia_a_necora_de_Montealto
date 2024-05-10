#include "DanceComponent.h"
#include <Transform.h>
#include <Entity.h>
#include <Serializer.h>
#include <ForgeError.h>
#include <TimeForge.h>

const std::string DanceComponent::id = "DanceComponent";

DanceComponent::DanceComponent() :
	myTransform(nullptr),
	limSup(0.0f),
	limInf(0.0f),
	originalHeight(0.0f),
	goingUp(false){
	serializer(limSup, "upperBound");
	serializer(limInf, "lowerBound");
}

DanceComponent::~DanceComponent()
{
}

bool DanceComponent::initComponent(ComponentData* data) {
	if (!entity->hasComponent(Transform::id)) {
		throwError(false, "Se necesita un componente AudioSource para reproducir un sonido de boton");
	}
	myTransform = entity->getComponent<Transform>();
	originalHeight = myTransform->getPosition().getY();
	return true;
}

void DanceComponent::update() {
	float height = myTransform->getPosition().getY();
	if (goingUp) {
		myTransform->setPositionY(height + 50 * forge::Time::deltaTime);
		goingUp = (height <= originalHeight + limSup);
	}
	else {
		myTransform->setPositionY(height - 50 * forge::Time::deltaTime);
		goingUp = !(height >= originalHeight - limInf);
	}

	myTransform->rotateY(10 * forge::Time::deltaTime);
}