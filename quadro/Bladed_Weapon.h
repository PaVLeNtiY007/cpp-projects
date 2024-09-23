#pragma once
#include "Weapon.h"
class Bladed_Weapon : public Weapon
{
protected:
	float max_damage = 35, blunted_damage = 20;
public:
	Bladed_Weapon() = default;
	Bladed_Weapon(std::string n, float dmg) : Weapon(n, dmg) {}
	void Stab();
	void Sharpen();
};

