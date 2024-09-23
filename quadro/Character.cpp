#include "Character.h"
#include <iostream>

Character::Character()
{

	arsenal.push_back(move(choosed_weapon)); //empty weapon on 1 slot
}

void Character::SetWeapon(int choise)
{
	arsenal.push_back(std::move(choosed_weapon));
	if (choise < arsenal.size())
		if (choise != 0) {
			choosed_weapon = std::move(arsenal[choise]);
			arsenal.erase(arsenal.begin() + choise);
		}
}

void Character::PickUpWeapon(std::unique_ptr<Weapon> droped_weapon)
{
	arsenal.push_back(std::move(droped_weapon));
}

void Character::GetWeapon()
{
	if(choosed_weapon != nullptr)
		std::cout << choosed_weapon->GetName() << ' ' << choosed_weapon->GetDamage();
}
