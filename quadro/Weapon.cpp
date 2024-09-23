#include "Weapon.h"

Weapon::Weapon(std::string n, float dmg)
{
    name = n;
    damage = dmg;
}

std::string Weapon::GetName()
{
    return name;
}

float Weapon::GetDamage() const
{
    return damage;
}
