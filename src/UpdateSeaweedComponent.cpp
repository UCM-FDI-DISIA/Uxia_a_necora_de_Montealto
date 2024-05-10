#include "UpdateSeaweedComponent.h"
#include <Entity.h>
#include <Scene.h>
#include <Text.h>
#include <ForgeError.h>
#include "LevelManager.h"

const std::string UpdateSeaweedComponent::id = "UpdateSeaweedComponent";

UpdateSeaweedComponent::UpdateSeaweedComponent() : 
	levelManager(nullptr),
	myText(nullptr){
}

bool UpdateSeaweedComponent::initComponent(ComponentData* data) {
	if (!entity->hasComponent(Text::id)) {
		throwError(false, "Se necesita tener un componente de texto para cambiar el numero de algas");
	}
	if (scene->getEntityByHandler("manager") == nullptr) {
		throwError(false, "No hay LevelManager en la escena");
	}
	myText = entity->getComponent<Text>();
	levelManager = scene->getEntityByHandler("manager")->getComponent<LevelManager>();

	myText->setText(myText->getText() + std::to_string(levelManager->getKelp()));
	return true;
}