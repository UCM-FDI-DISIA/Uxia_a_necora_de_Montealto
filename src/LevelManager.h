#pragma once
#ifndef LEVEL_MANAGER_H_
#define LEVEL_MANAGER_H_
#include "Component.h"
#include <string>
#include <Vector3.h>

class UIManager;

class LevelManager : public Component {
private:
	std::string mainMenu;
	std::string pauseMenu;
	std::vector<std::string> levels;
	forge::Vector3 spawnpoint;
	UIManager* ui;
	int currentLevel;
	int maxLevel;
	int currentKelp;

	/// <summary>
	/// Registra las funciones de LevelManager
	/// </summary>
	void registerFunctions();

public:
	static const std::string id;

#pragma region Constructoras
	LevelManager();
#pragma endregion


#pragma region Getters/Setters
	/// <summary>
	/// Devuelve el numero del nivel actual
	/// </summary>
	/// <returns> Nivel actual</returns>
	int getLevel();

	/// <summary>
	/// Devuelve la cantidad de algas (vida) que tiene el jugador
	/// </summary>
	/// <returns> Cantidad de algas</returns>
	int getKelp();


	/// <summary>
	/// Devuelve el punto de spawn actual
	/// </summary>
	/// <returns> Vector3 con el punto de spawn</returns>
	forge::Vector3 getSpawnpoint();	

	/// <summary>
	/// Cambia la cantidad de algas (vida) que tiene el jugador
	/// </summary>
	/// <param name="kelp"> Cantidad de algas</param>
	void setKelp(int kelp);

	/// <summary>
	/// Establece un punto de spawn para el jugador
	/// </summary>
	/// <param name="spawnpoint"> Vector3 con el punto de spawn</param>
	void setSpawnpoint(forge::Vector3);

#pragma endregion

	/// <summary>
	/// Inicializa el componente LevelManager
	/// </summary>
	bool initComponent(ComponentData* data) override;
	
	/// <summary>
	/// Cambia el nivel actual al nivel indicado
	/// </summary>
	/// <param name="level"> Nivel al que se quiere cambiar</param>
	void changeLevel(int level);

	/// <summary>
	/// Cambia al siguiente nivel
	/// </summary>
	void nextLevel();

	/// <summary>
	/// Vuelve al nivel actual
	/// </summary>
	void returnToLevel();

	/// <summary>
	/// Cambia a la escena de menu principal
	/// </summary>
	void setMainMenu();

	/// <summary>
	/// Cambia a la escena de menu de pausa
	/// </summary>
	void setPauseMenu();

	/// <summary>
	/// Respawnea al jugador en el punto de spawn
	/// </summary>
	void spawn();
};

#endif // !LEVEL_MANAGER_H_