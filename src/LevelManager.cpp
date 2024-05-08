#include "LevelManager.h"
#include "PlayerHealthComponent.h"
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include <Scene.h>
#include <Collider.h>

const std::string LevelManager::id = "LevelManager";

LevelManager::LevelManager() {

}

bool LevelManager::initComponent(ComponentData* data) {
    return true;
}