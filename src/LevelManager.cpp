#include "LevelManager.h"
#include "PlayerHealthComponent.h"
#include "PlayerInputComponent.h"
#include "UIManager.h"
#include <SceneManager.h>
#include <ComponentData.h>
#include <Entity.h>
#include <Serializer.h>
#include <Scene.h>
#include <Collider.h>
#include <Animator.h>
#include <RigidBody.h>
#include <MainForge.h>

const std::string LevelManager::id = "LevelManager";

void LevelManager::registerFunctions() {
    entity->getInvoker().registerFunction("startGame", [&]() {
        returnToLevel(true);
        });
    entity->getInvoker().registerFunction("exitGame", [&]() {
        MainForge::Exit();
        });
    entity->getInvoker().registerFunction("goToMenu", [&]() {
        setMainMenu();
        });
}

LevelManager::LevelManager() :
    ui(nullptr),
    mainMenu(),
    pauseMenu(),
    victoryMenu(),
    levels(),
    spawnpoint(),
    currentLevel(0),
    currentKelp(0),
    maxLevel(0) {
    serializer(mainMenu, "mainMenu");
    serializer(pauseMenu, "pauseMenu");
    serializer(victoryMenu, "victoryMenu");
    serializer(levels, "levels");
    serializer(spawnpoint, "spawn");
    initialSpawnpoint = spawnpoint;
}

bool LevelManager::initComponent(ComponentData* data) {
    ui = entity->getComponent<UIManager>();
    if (levels.size() < 1 || pauseMenu == "" || mainMenu == "") {
        throwError(false, "Falta definir escenas en el level manager");
    }
    maxLevel = (int)levels.size() - 1;
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
    sceneManager.changeScene(levels[currentLevel], true);
}

int LevelManager::getLevel() {
    return currentLevel;
}

int LevelManager::getKelp() {
    return currentKelp;
}

void LevelManager::setKelp(int kelp) {
    currentKelp = kelp;
}

void LevelManager::returnToLevel(bool start) {
    ui->enableKelpText(true);
    sceneManager.changeScene(levels[currentLevel], start);
}

void LevelManager::setMainMenu() {
    setKelp(0);
    currentLevel = 0;
    setSpawnpoint(initialSpawnpoint);
    ui->updateKelpText(0);
    ui->enableKelpText(false);
    sceneManager.changeScene(mainMenu);
    
}

void LevelManager::setPauseMenu() {
    ui->enableKelpText(false);
    sceneManager.changeScene(pauseMenu);
}

void LevelManager::setVictoryMenu() {
    sceneManager.changeScene(victoryMenu);
}

void LevelManager::setSpawnpoint(forge::Vector3 newSpawn) {
    spawnpoint = newSpawn;
}

forge::Vector3 LevelManager::getSpawnpoint() {
    return spawnpoint;
}

void LevelManager::spawn() {
    Entity* player = scene->getEntityByHandler("Player");
    if (player != nullptr) {
        ui->enableDeathText(false);
        player->getComponent<PlayerInputComponent>()->setDead(false);
        player->getComponent<Animator>()->setActive("my_animation", true);
        player->getComponent<RigidBody>()->setPosition(spawnpoint);
    }
}

void LevelManager::restart() {
    
}

