#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	float hero_health, health_change, damage_distance;
	cout << "Введіть здоров'я персонажа - ";
	cin >> hero_health;
	while (hero_health > 0) {
		cout << "\nВведіть зміну здоров'я персонажа: ";
		cin >> health_change;
		cout << "Введіть дистанцію до персонажа: ";
		cin >> damage_distance;
		if (damage_distance <= 100) {
			if (health_change < 0) health_change *= (1 - damage_distance / 100); //лікування не залежить від дистанції (наче логічніше)
			hero_health += health_change;
			if (hero_health <= 0) cout << "Персонаж загинув!";
			else if (hero_health < 1) hero_health = 1;
			cout << "Здоров'я персонажа після впливу - " << hero_health << endl;
		}
		else cout << "Персонаж не зазнав впливу!\n";
	}
}