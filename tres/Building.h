#pragma once
class Building {
	static int ID;
	float InitCost = 10000, MaxAge = 10, CurrentAge = 0;
	void Destroy();
public:
	float GetCost();
	void AddYears(float AddedAge);
	Building();
	[] Building();
	Building(float _InitCost);
	Building(float _InitCost, float _MaxAge);
	Building(float _InitCost, float _MaxAge, float _CurrentAge);
};
