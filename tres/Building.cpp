#include "Building.h"
#include <iostream>

int Building::ID = 0;

float Building::GetCost() {
	return InitCost - (InitCost / MaxAge) * CurrentAge;
}

void Building::AddYears(float AddedAge) {
	CurrentAge += AddedAge;
	if (CurrentAge > MaxAge) Destroy();
}

void Building::Destroy() {
	std::cout << std::endl << "Building with ID " << ID << " was destroyed" << std::endl;
}

Building::Building() {
	ID += 1;
}

Building::Building(float _InitCost) {
	InitCost = _InitCost;
	ID += 1;
}

Building::Building(float _InitCost, float _MaxAge) {
	MaxAge = _MaxAge;
	InitCost = _InitCost;
	ID += 1;
}

Building::Building(float _InitCost, float _MaxAge, float _CurrentAge) {
	CurrentAge = _CurrentAge;
	MaxAge = _MaxAge;
	InitCost = _InitCost;
	ID += 1;
	if (CurrentAge > MaxAge) Destroy();
}
