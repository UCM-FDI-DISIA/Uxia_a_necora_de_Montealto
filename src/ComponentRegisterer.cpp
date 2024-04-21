#include "Factory.h"
#include "ForgeImport.h"
#include "MovementComponent.h"
#include "PlayerInputComponent.h"

FORGE_IMPORT void registerComponents(Factory& f) {
	f.registerComponent<MovementComponent>();
	f.registerComponent<PlayerInputComponent>();
}