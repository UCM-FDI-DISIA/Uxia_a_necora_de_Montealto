#pragma once
#ifndef ATTACK_COMPONENT_H_
#define ATTACK_COMPONENT_H_
#include <Component.h>
#include <Vector3.h>
#include <string>

class Collider;

class AttackComponent : public Component
{
private:
	Collider* hitbox;
	int damage;

public:
	static const std::string id;

	AttackComponent();

	~AttackComponent();

	bool initComponent(ComponentData* data) override;

	/// 
	/// <summary>
 	/// Restar vida a Uxia
 	/// </summary>
 	void attack();
};

#endif // !ATTACK_COMPONENT_H_