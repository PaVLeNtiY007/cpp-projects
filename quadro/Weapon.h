#pragma once
#include <string>
class Weapon
{
protected:
	float damage = 50;
	std::string name = "Weapon";
public:
	Weapon() = default;
	Weapon(std::string n, float dmg);
	std::string GetName();
	float GetDamage() const;
};

