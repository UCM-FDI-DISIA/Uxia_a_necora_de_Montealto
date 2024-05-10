#include "ButtonSoundComponent.h"
#include <AudioSource.h>
#include <Entity.h>
#include <ForgeError.h>
#include <Invoker.h>

const std::string ButtonSoundComponent::id = "ButtonSoundComponent";

ButtonSoundComponent::ButtonSoundComponent() : 
	audioComponent(nullptr) {
}

bool ButtonSoundComponent::initComponent(ComponentData* data) {
	if (!entity->hasComponent(AudioSource::id)) {
		throwError(false, "Se necesita un componente AudioSource para reproducir un sonido de boton");
	}
	audioComponent = entity->getComponent<AudioSource>();
	entity->getInvoker().registerFunction("playClicked", [&]() {
		playClicked();
		});
	return true;
}

void ButtonSoundComponent::playClicked() {
	audioComponent->play();
}