#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Car.h"
#include "CarListUtil.h"
#include "DisplayUtil.h"
using namespace std;

void program(int wybor, vector<Car> &L, bool &wyl, bool w, string haslo)
{
	menu_gl();
	while (!(cin >> wybor) || cin.peek() != char_traits<char>::to_int_type('\n')) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
	{
		cout << "BLAD!!! Wybierz numer opcji!\n";
		cin.clear(); //kasowanie flagi błędu strumienia
		cin.sync(); //kasowanie zbędnych znaków z bufora
		cin.ignore(1000, '\n');
	}

	switch (wybor)
	{
	case 1:
		wypozycz_samochod(L);
		break;
	case 2:
		do
		{
			samochody(L);
			cout << "1.Wybierz samochod\t|\n" << "2.Wstecz\t\t|\n";
			cout << "------------------------\n";

			while (!(cin >> wybor) || (wybor != 1 && wybor != 2) || cin.peek() != char_traits<char>::to_int_type('\n')) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
			{
				cout << "BLAD!!! Wybierz numer opcji!\n";
				cin.clear(); //kasowanie flagi błędu strumienia
				cin.sync(); //kasowanie zbędnych znaków z bufora
				cin.ignore(1000, '\n');
			}

			if (wybor == 1)
			{
				int wybor2;
				cout << "Podaj numer samochodu: ";
				while (!(cin >> wybor2) || cin.peek() != char_traits<char>::to_int_type('\n')) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
				{
					cout << "BLAD!!! Wybierz numer samochodu!\n";
					cin.clear(); //kasowanie flagi błędu strumienia
					cin.sync(); //kasowanie zbędnych znaków z bufora
					cin.ignore(1000, '\n');
				}

				if (wybor2 <= L.size() && wybor2 > 0)
				{
					wyswietl(wybor2, L);
					terminy(wybor2, L);
				}
				else cout << "Ten samochod nie istnieje!\n";
				system("pause");
			}
			else w = false;
		} while (w);
		break;

	case 3:
		wyl = true;
		break;
	case 4:
		system("cls");
		cout << "Podaj haslo:\t";
		cin >> haslo;
		if (haslo == "admin") admin(L);
		else
		{
			cout << "Niepoprawne haslo!\n";
			system("pause");
		}
		break;
	default:
		break;
	}

}

int main()
{
	vector<Car>L;

	wczytaj(L);
	sortuj(L);
	int wybor = 0;
	bool wyl = false;
	bool w = true;
	string haslo;
	do
	{
		program(wybor, L, wyl, w, haslo);
	} while (!wyl);
	zapisz(L);
}
