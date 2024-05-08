#include "Factory.h"
#include "ForgeImport.h"
#include "MovementComponent.h"
#include "PlayerInputComponent.h"
#include "KelpComponent.h"
#include "EnemyComponent.h"
#include "CheckpointComponent.h"
#include "PlayerHealthComponent.h"
#include "UIManager.h"
#include "LevelManager.h"

FORGE_IMPORT void registerComponents(Factory& f) {
	f.registerComponent<KelpComponent>();
	f.registerComponent<MovementComponent>();
	f.registerComponent<PlayerInputComponent>();
	f.registerComponent<EnemyComponent>();
	f.registerComponent<CheckpointComponent>();
	f.registerComponent<UIManager>();
	f.registerComponent<LevelManager>();
	f.registerComponent<PlayerHealthComponent>();
}