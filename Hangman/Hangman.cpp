#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <stdio.h>
#include <conio.h>;
using namespace std;

class Gallows {
private:
	vector <string> words;
	string selected_word;
	char user_letter;
	int counter;
	vector<string>Graphic{
	{
		"    _____  \n"
		"   |     | \n"
		"         | \n"
		"         | \n"
		"         | \n"
		"         | \n"
	},
	{
		"    _____	\n"
		"   |     | \n"
		"   O     | \n"
		"         | \n"
		"         | \n"
		"         | \n"
	},
	{
		"    _____	\n"
		"   |     | \n"
		"   O     | \n"
		"   |     | \n"
		"         | \n"
		"         | \n"
	},
	{
		"    _____	\n"
		"   |     | \n"
		"   O     | \n"
		"  /|     | \n"
		"         | \n"
		"         | \n"
	},
	{
		"    _____	\n"
		"   |     | \n"
		"   O     | \n"
		"  /|\\    | \n"
		"         | \n"
		"         | \n"
	},
	{
		"    _____	\n"
		"   |     | \n"
		"   O     | \n"
		"  /|\\    | \n"
		"  /      | \n"
		"         | \n"
	},
	{
		"    _____	\n"
		"   |     | \n"
		"   O     | \n"
		"  /|\\    | \n"
		"  / \\    | \n"
		"         | \n"
	},
	};
public:
	void Add_words();
	string Select_word();
	void Game();
};

void Gallows::Add_words() {
	string word;
	cout << "Введите слово, которое хотите добавить в библиотеку игры: ";
	cin >> word;
	ofstream out("file.txt", ios::app);
	out << word << endl;
	out.close();
};
string Gallows::Select_word() {
	string tmp;
	ifstream in("file.txt", ios::in);
	while (!in.eof()) {
		in >> tmp;
		words.push_back(tmp);
	}
	in.close();
	srand(time(NULL));
	int index = rand() % words.size();
	selected_word = words[index];
	return selected_word;
};
void Gallows::Game() {
	vector<char> vect(selected_word.c_str(), selected_word.c_str() + selected_word.size());
	vector<char> vect2;
	for (int i = 0; i < vect.size(); i++) {
		vect2.push_back('_');
	}

	cout << Graphic[0];
	int n = 0;
	int m = 0;
	do {
		n = rand() % vect.size();
		m = rand() % vect.size();
	} while (n == m);
	for (int i = 0; i < vect.size(); i++) {
		if (i == n || i == m) {
			if (i == n) {
				vect2[n] = vect[i];
				cout << vect2[n] << " ";
			}
			if (i == m) {
				vect2[m] = vect[i];
				cout << vect2[m] << " ";
			}
		}
		else {
			cout << vect2[i] << " ";
		}
	}
	cout << endl;

	vector<char>user_letters;
	do {
		cout << endl;
		cout << "Буква: ";
		cin >> user_letter;
		user_letters.push_back(user_letter);
		for (int i = 0; i < vect.size(); i++) {
			if (vect[i] == user_letter) {
				vect2.at(i) = user_letter;
			}
			cout << vect2[i] << " ";
		}
		if (find(vect2.begin(), vect2.end(), '_') == vect2.end()) {
			cout << endl;
			cout << "Вы выиграли!" << endl;
			cout << "Количество попыток: " << counter << endl;
			cout << "Слово: " << selected_word << endl;
			cout << "Буквы игрока: ";
			for (auto iter = user_letters.begin(); iter != user_letters.end(); iter++) {
				cout << *iter << " ";
			}
			break;
		}
		if (find(vect.begin(), vect.end(), user_letter) == vect.end()) {
			counter++;
			if (counter == 1) {
				system("cls");
				cout << Graphic[1];
				for (int i = 0; i < vect.size(); i++) {
					cout << vect2[i] << " ";
				}
			}
			if (counter == 2) {
				system("cls");
				cout << Graphic[2];
				for (int i = 0; i < vect.size(); i++) {
					cout << vect2[i] << " ";
				}
			}
			if (counter == 3) {
				system("cls");
				cout << Graphic[3];
				for (int i = 0; i < vect.size(); i++) {
					cout << vect2[i] << " ";

				}
			}
			if (counter == 4) {
				system("cls");
				cout << Graphic[4];
				for (int i = 0; i < vect.size(); i++) {
					cout << vect2[i] << " ";
				}
			}
			if (counter == 5) {
				system("cls");
				cout << Graphic[5];
				for (int i = 0; i < vect.size(); i++) {
					cout << vect2[i] << " ";

				}
			}
			if (counter == 6) {
				system("cls");
				cout << Graphic[6];
				cout << "Вы проиграли!" << endl;
				cout << "Количество попыток: " << counter << endl;
				cout << "Слово: " << selected_word << endl;
				cout << "Буквы игрока: ";
				for (auto iter = user_letters.begin(); iter != user_letters.end(); iter++) {
					cout << *iter << " ";
				}
			}
		}
	} while (counter != 6);
};

int main()
{
	setlocale(LC_ALL, "Russian");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Gallows p;
	do {
		cout << endl;
		system("cls");
		cout << "\tВаша цель - угадать слово, иначе Джонни погибнет!" << endl;
		cout << "\t ____________________________________________" << endl;
		cout << "\t| 1 - Начать новую игру                      |" << endl;
		cout << "\t| 2 - Добавить новое слово в библиотеку слов |" << endl;
		cout << "\t ********************************************" << endl;
		if (!_kbhit()) {
			switch (_getch())
			{
			case '1':
				system("cls");
				p.Select_word();
				p.Game();
				break;
			case '2':
				system("cls");
				p.Add_words();
				break;
			}
		}
		cout << endl;
		system("pause");
	} while (true);
}

