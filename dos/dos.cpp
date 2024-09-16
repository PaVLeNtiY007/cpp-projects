#include <iostream>
#include <Windows.h>
#include <vector>
#include <iomanip>

using namespace std;

struct Player {
	string name;
	float damage = 0, health = 0;
};

void line() {
	cout << endl;
	for (int i = 0; i <= 70; i++) {
		cout << '-';
	}
	cout << endl;
}

void OutputTeams(vector<Player>& team1, vector<Player>& team2) {
	line();
	int maxsize;
	if (team1.size() > team2.size()) maxsize = team1.size();
	else maxsize = team2.size();
	cout << setw(24) << "Команда 1" << setw(36) << "Команда 2";
	line();
	cout << setw(15) << "Ім'я" << setw(12) << "Здоров'я" << setw(8) << "Урон"
		 << setw(16) << "Ім'я" << setw(12) << "Здоров'я" << setw(8) << "Урон" << endl;
	for (int i = 0; i < maxsize; i++) {
		if (i < team1.size()) {
			cout << setw(15) << team1[i].name << setw(12) << team1[i].health << setw(8) << team1[i].damage;
		}
		else {
			cout << setw(35) << ""; 
		}
		if (i < team2.size()) {
			cout << setw(16) << team2[i].name << setw(12) << team2[i].health << setw(8) << team2[i].damage << endl;
		}
		else {
			cout << setw(45) << "" << endl;
		}

	}
	line();
}

void AddPlayer(vector<Player>& team1, vector<Player>& team2) {
	line();
	bool team_id;
	Player temp;
	cout << "Введіть ім'я гравця - ";
	cin >> temp.name;
	cout << "Введіть урон - ";
	cin >> temp.damage;
	cout << "Введіть здоров'я - ";
	cin >> temp.health;
	cout << "Введіть id команди (0 або 1) - ";
	cin >> team_id;
	if (team_id) team2.push_back(temp);
	else team1.push_back(temp);
}

void RemovePlayer(vector<Player>& team1, vector<Player>& team2) {
	line();
	string tname;
	bool tid;
	cout << "Введіть ім'я - ";
	cin >> tname;
	cout << "Введіть id команди (0 або 1) - ";
	cin >> tid;
	if (tid) {
		for (auto i = team2.begin(); i != team2.end(); i++) 
			if (i->name == tname) {
				team2.erase(i);
				break;
			}
	}
	else {
		for (auto i = team1.begin(); i != team1.end(); i++) 
			if (i->name == tname) {
				team1.erase(i);
				break;
			}
	}
	cout << "\nГравця видалено!";
	line();
}

void StartFight(vector<Player>& team1, vector<Player>& team2) {
	while (team1.size() && team2.size()) {
		OutputTeams(team1, team2);
		if (rand() % 2) {
			team1[0].health -= team2[0].damage;
		}
		else team2[0].health -= team1[0].damage;
		auto i1 = team1.begin();
		if (i1->health <= 0) team1.erase(i1);
		auto i2 = team2.begin();
		if (i2->health <= 0) team2.erase(i2);
	}
	OutputTeams(team1, team2);
	cout << "Бій завершено\n";
	if (team1.size() > team2.size()) cout << "Перемогла перша команда";
	else cout << "Перемогла друга команда";
}

int main(){	
	srand(time(NULL));
	SetConsoleOutputCP(1251);
	int choise = 0;
	vector<Player> first_team;
	vector<Player> second_team;
	cout << "\nОберіть пункт меню:\n";
	cout << "   0 - додати до бою гравця\n";
	cout << "   1 - вилучити гравця з бою\n";
	cout << "   2 - провести бій\n";
	while (true) {
		cout << "\n -> ";
		cin >> choise;
		switch (choise) {
		case 0:
			AddPlayer(first_team, second_team);
			break;
		case 1:
			RemovePlayer(first_team, second_team);
			break;
		case 2:
			StartFight(first_team, second_team);
			return 0;
		default:
			cout << "Введіть коректне значення!!!";
		}
	}
}