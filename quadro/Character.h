#pragma once
#include "Weapon.h"
#include <memory>
#include <vector>

class Character
{
private:
	std::vector<std::unique_ptr<Weapon>> arsenal;
	std::unique_ptr<Weapon> choosed_weapon;
public:
	Character();
	void SetWeapon(int choise);
	void PickUpWeapon(std::unique_ptr<Weapon> droped_weapon);
	void GetWeapon();
};

