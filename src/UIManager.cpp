#include "UIManager.h"
#include <Entity.h>
#include <ComponentData.h>
#include <Scene.h>
#include <Text.h>
#include <ForgeError.h>

const std::string UIManager::id = "UIManager";

UIManager::UIManager() :
    kelpText(nullptr),
    deathText(nullptr) {
}

UIManager::~UIManager()
{
}

bool UIManager::initComponent(ComponentData* data) {
    Entity* kelpEntity = scene->getEntityByHandler("kelpText");
    if (kelpEntity != nullptr) {
        kelpText = kelpEntity->getComponent<Text>();
    }
    Entity* deathEntity = scene->getEntityByHandler("deathText");
    if (deathEntity != nullptr) {
        deathText = deathEntity->getComponent<Text>();
    }
    if (kelpText != nullptr && deathText != nullptr) {
        return true;
    }
    throwError(false, "No se han podido encontrar los textos para el UIManager");
}

void UIManager::updateKelpText(int kelp) {
    kelpText->setText("Algas: " + std::to_string(kelp));
}

void UIManager::enableKelpText(bool enabled) {
    kelpText->setTextOpacity(enabled ? 1 : 0);
}

void UIManager::enableDeathText(bool enabled) {
    deathText->setTextOpacity(enabled ? 1 : 0);
}
