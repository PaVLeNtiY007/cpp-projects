#include "Character.h"
#include "Bladed_Weapon.h"
#include "Explosive.h"
#include "Pistol.h"
#include <memory>
#include <iostream>

int main()
{
	std::unique_ptr<Character> MainHero = std::make_unique<Character>();

	std::unique_ptr<Bladed_Weapon> Knife = std::make_unique<Bladed_Weapon>("Knife", 35);
	std::unique_ptr<Explosive> C4 = std::make_unique<Explosive>("C4", 250);
	std::unique_ptr<Pistol> USP = std::make_unique<Pistol>("USP", 25);

	MainHero->PickUpWeapon(move(Knife));
	MainHero->PickUpWeapon(move(C4));
	MainHero->PickUpWeapon(move(USP));
	MainHero->SetWeapon(1);
	MainHero->GetWeapon();
	std::cout << std::endl;
	MainHero->SetWeapon(1);
	MainHero->GetWeapon();
	std::cout << std::endl;
	MainHero->SetWeapon(1);
	MainHero->GetWeapon();
}