#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	Pistol() = default;
	Pistol(std::string n, float dmg) : Weapon(n, dmg){}
	float Shoot();
};

