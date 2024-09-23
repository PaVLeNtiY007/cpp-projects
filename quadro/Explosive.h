#pragma once
#include "Weapon.h"
#include <string>

class Explosive : public Weapon
{
protected:
	std::string explosion_type, explosion_effect;
	float time_to_explode;
public:
	Explosive() = default;
	Explosive(std::string n, float dmg) : Weapon(n, dmg) {}
	float Armed();
	float Explode();
};

