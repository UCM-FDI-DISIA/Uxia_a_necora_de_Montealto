#include "LevelManager.h"
#include "PlayerHealthComponent.h"
#include <SceneManager.h>
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include <Scene.h>
#include <Collider.h>
#include <RigidBody.h>
#include <MainForge.h>

const std::string LevelManager::id = "LevelManager";

void LevelManager::registerFunctions() {
    entity->getInvoker().registerFunction("startGame", [&]() {
        returnToLevel();
        });
    entity->getInvoker().registerFunction("exitGame", [&]() {
        MainForge::Exit();
        });
    entity->getInvoker().registerFunction("goToMenu", [&]() {
        setMainMenu();
        });
}

LevelManager::LevelManager() :
    mainMenu(),
    pauseMenu(),
    levels(),
    spawnpoint(),
    currentLevel(0),
    maxLevel(0) {
    serializer(mainMenu, "mainMenu");
    serializer(pauseMenu, "pauseMenu");
    serializer(levels, "levels");
    serializer(spawnpoint, "spawn");
}

bool LevelManager::initComponent(ComponentData* data) {
    if (levels.size() < 1 || pauseMenu == "" || mainMenu == "") {
        throwError(false, "Falta definir escenas en el level manager");
    }
    maxLevel = levels.size() - 1;
    registerFunctions();
    return true;
}

void LevelManager::changeLevel(int level) {
    if (level >= maxLevel) {
        reportError("El nivel introducido no es valido");
        return;
    }
    currentLevel = level;
    sceneManager.changeScene(levels[currentLevel]);
}

void LevelManager::nextLevel() {
    if (currentLevel >= maxLevel) {
        reportError("Ya se ha alcanzado el máximo nivel");
        return;
    }
    currentLevel++;
    sceneManager.changeScene(levels[currentLevel]);
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

void LevelManager::spawn() {
    Entity* player = scene->getEntityByHandler("Player");   
    player->getComponent<RigidBody>()->setPosition(spawnpoint);
}

