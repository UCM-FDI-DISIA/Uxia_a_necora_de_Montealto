#include "LevelManager.h"
#include "PlayerHealthComponent.h"
#include <SceneManager.h>
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include <Scene.h>
#include <Collider.h>

const std::string LevelManager::id = "LevelManager";

LevelManager::LevelManager() :
    mainMenu(),
    pauseMenu(),
    levels(),
    spawnpoint(),
    currentLevel(0) {
    serializer(mainMenu, "mainMenu");
    serializer(pauseMenu, "pauseMenu");
    serializer(levels, "levels");
    serializer(spawnpoint, "spawn");
}

bool LevelManager::initComponent(ComponentData* data) {
    return true;
}

void LevelManager::changeLevel(int level) {
    currentLevel = level;
    sceneManager.changeScene(levels[level]);
}

int LevelManager::getLevel() {
    return currentLevel;
}

void LevelManager::returnToLevel() {
    sceneManager.changeScene(levels[currentLevel]);
}

void LevelManager::setMainMenu() {
    sceneManager.changeScene(mainMenu);
}

void LevelManager::setPauseMenu() {
    sceneManager.changeScene(pauseMenu);
}

void LevelManager::setSpawnpoint(forge::Vector3 newSpawn) {
    spawnpoint = newSpawn;
}

forge::Vector3 LevelManager::getSpawnpoint() {
    return spawnpoint;
}

