#include "Explosive.h"
#include <iostream>

float Explosive::Armed()
{
	std::cout << "Armed!";
	return time_to_explode;
}

float Explosive::Explode()
{
	std::cout << "BOOM!!!";
	return damage;
}
