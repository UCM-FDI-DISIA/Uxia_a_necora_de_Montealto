#include "LevelManager.h"
#include "PlayerHealthComponent.h"
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include <Scene.h>
#include <Collider.h>

const std::string LevelManager::id = "LevelManager";

LevelManager::LevelManager() :
spawnpoint(forge::Vector3::ZERO){
    serializer(spawnpoint, "spawn");
}

bool LevelManager::initComponent(ComponentData* data) {
    return true;
}

void LevelManager::setSpawnpoint(forge::Vector3 newSpawn) {
    spawnpoint = newSpawn;
}

forge::Vector3 LevelManager::getSpawnpoint() {
    return spawnpoint;
}