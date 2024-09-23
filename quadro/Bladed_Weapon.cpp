#include "Bladed_Weapon.h"

void Bladed_Weapon::Stab() // Stab(Character* hero)
{
	//hero->ApplyDamage();
	if (damage - 5 >= blunted_damage) damage -= 5;
}

void Bladed_Weapon::Sharpen()
{
	damage = max_damage;
}
