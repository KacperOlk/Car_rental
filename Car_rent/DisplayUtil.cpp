#include "DisplayUtil.h"
#include "Car.h"
#include "CarListUtil.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void menu_gl()
{
	system("cls");
	cout << "  WYPOZYCZALNIA SAMOCHODOW\n";
	cout << "--------------MENU--------------\n";
	cout << "1. Wypozycz samochod \n";
	cout << "2. Nasze samochody \n";
	cout << "3. Wyjdz\n";
	cout << "--------------------------------\n";
	cout << "4. Opcje administratora\n";
	cout << "--------------------------------\n\n";
}

void wypozycz_samochod(vector<Car>& L)
{
	if (L.size() == 0)
	{
		cout << "Chwilowy brak samochodow w systemie. Przepraszamy za niedogodnosci.\n";
		system("pause");
		return;
	}
	string start, stop, r, m, d, imie, nazwisko;
	int data;
	bool blad = false;
	vector<int> mapa;

	system("cls");
	cout << "Podaj date poczatku najmu:\n";
	cout << "Rok (RRRR):\t";

	while (!(cin >> data) || data < 2020 || data > 2030) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
	{
		cout << "Podaj rok w formacie RRRR!!!:\t";
		cin.clear(); //kasowanie flagi b³êdu strumienia
		cin.sync(); //kasowanie zbêdnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	r = to_string(data);

	cout << "Nr Miesiaca:\t";

	while (!(cin >> data) || data < 1 || data > 12) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
	{
		cout << "Podaj numer miesiaca!!!:\t";
		cin.clear(); //kasowanie flagi b³êdu strumienia
		cin.sync(); //kasowanie zbêdnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	if (data < 10) m = "0" + to_string(data);
	else m = to_string(data);

	cout << "Dzien :\t";
	while (!(cin >> data) || data < 1 || data > 31) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
	{
		cout << "Podaj numer dnia miesiaca!!!:\t";
		cin.clear(); //kasowanie flagi b³êdu strumienia
		cin.sync(); //kasowanie zbêdnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	if (data < 10) d = "0" + to_string(data);
	else d = to_string(data);
	start = r + m + d;

	cout << "Podaj date konca najmu:\n";
	cout << "Rok (RRRR):\t";
	while (!(cin >> data) || data < 2020 || data > 2030) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
	{
		cout << "Podaj rok w formacie RRRR!!!:\t";
		cin.clear(); //kasowanie flagi b³êdu strumienia
		cin.sync(); //kasowanie zbêdnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	r = to_string(data);
	cout << "Nr Miesiaca:\t";
	while (!(cin >> data) || data < 1 || data > 12) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
	{
		cout << "Podaj numer miesiaca!!!:\t";
		cin.clear(); //kasowanie flagi b³êdu strumienia
		cin.sync(); //kasowanie zbêdnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	if (data < 10) m = "0" + to_string(data);
	else m = to_string(data);
	cout << "Dzien :\t";
	while (!(cin >> data) || data < 1 || data > 31) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
	{
		cout << "Podaj numer dnia miesiaca!!!:\t";
		cin.clear(); //kasowanie flagi b³êdu strumienia
		cin.sync(); //kasowanie zbêdnych znaków z bufora
		cin.ignore(1000, '\n');
	}
	if (data < 10) d = "0" + to_string(data);
	else d = to_string(data);
	stop = r + m + d;

	cout << "Podaj imie:\n";
	cin >> imie;
	cout << "Podaj nazwisko:\n";
	cin >> nazwisko;

	if (start > stop)
	{
		cout << "Data odbioru nie moze byc po dacie zwrotu!!!\n";
		system("pause");
		return;
	}

	vector<Car>L2;
	for (size_t i = 0; i < L.size(); i++)
	{
		if (dostepny(start, stop, L[i].get_start(), L[i].get_stop()))
		{
			L2.push_back(L[i]);
			mapa.push_back(i);
		}
		else if (L[i].get_start() == "00000000")
		{
			L2.push_back(L[i]);
			mapa.push_back(i);
		}
	}

	do
	{
		system("cls");

		if (L2.size() == 0)
		{
			cout << "BRAK DOSTEPNYCH SAMOCHODOW W WYBRANYM TERMINIE\n";
			system("pause");
			//return;
		}
		samochody(L2);			//wyswietla dostepne samochody od najtanszego

		cout << "1.Wybierz samochod\t|\n" << "2.Wstecz\t\t|\n";
		cout << "------------------------\n";

		int wybor;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << "Podaj numer samochodu: ";
			while (!(cin >> wybor)) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
			{
				cout << "BLAD!!! Wybierz numer samochodu!\n";
				cin.clear(); //kasowanie flagi b³êdu strumienia
				cin.sync(); //kasowanie zbêdnych znaków z bufora
				cin.ignore(1000, '\n');
			}

			if (wybor <= L2.size() && wybor > 0)
			{
				wyswietl(wybor, L2);
				cout << "------------------------\n";
				cout << "1.REZERWUJ\t\t|\n" << "2.Wstecz\t\t|\n";
				cout << "------------------------\n";
				int wybor2;
				while (!(cin >> wybor2)) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
				{
					cout << "BLAD!!! Wybierz numer opcji!\n";
					cin.clear(); //kasowanie flagi b³êdu strumienia
					cin.sync(); //kasowanie zbêdnych znaków z bufora
					cin.ignore(1000, '\n');
				}
				if (wybor2 == 1)
				{
					if (L[mapa[wybor - 1]].get_start() == "00000000")
					{
						L[mapa[wybor - 1]].set_start("");
						L[mapa[wybor - 1]].set_stop("");
						L[mapa[wybor - 1]].set_imie("");
						L[mapa[wybor - 1]].set_nazwisko("");

					}
					L[mapa[wybor - 1]].rezerwuj(start, stop, imie, nazwisko);
					blad = false;
					system("cls");
					cout << "\t\tZAREZERWOWANO!\n";
					zapisz(L);
					system("pause");
				}
				else
				{
					blad = true;
				}

			}
			else blad = true;
			break;
		case 2:
			blad = false;
			break;

		default:
			cout << "Wybrana opcja nie istnieje!";
			blad = true;
			break;
		}
	} while (blad);
}

bool dostepny(string ustart, string ustop, string start, string stop)
{
	int l = start.length();

	for (int i = 0; i < l / 8; i++)
	{
		string nowy;
		for (int j = 0; j < 8; j++)
		{
			nowy += start[j + (i * 8)];
		}
		string nowy2;
		for (int j = 0; j < 8; j++)
		{
			nowy2 += stop[j + (i * 8)];
		}

		if ((ustart <= nowy2 && ustart >= nowy) || (ustop <= nowy2 && ustop >= nowy)) return false;
	}
	return true;
}


void samochody(vector<Car> L)	// wyswietla samochody
{
	system("cls");
	for (size_t i = 0; i < L.size(); ++i)
	{
		cout << "------------------------------------------------------------------------\n";
		cout << i + 1 << "." << L[i].get_marka();
		if (L[i].get_marka().length() < 6) cout << "\t\t";
		else cout << "\t";
		cout << L[i].get_model();
		if (L[i].get_model().length() < 8) cout << "\t\t";
		else cout << "\t";
		cout << L[i].get_typ();
		if (L[i].get_typ().length() < 8) cout << "\t\t";
		else cout << "\t";

		cout << "l.miejsc: " << L[i].get_liczba_miejsc() << "\t" << L[i].get_cena() << "zl/dobe" << endl;
	}
	cout << "------------------------------------------------------------------------\n";
}

void wyswietl(int nr_auta, vector<Car> L) //wyswietla jeden wybrany samochod
{
	nr_auta--;
	system("cls");
	cout << "Marka:\t\t\t";
	cout << L[nr_auta].get_marka() << endl;
	cout << "Model:\t\t\t";
	cout << L[nr_auta].get_model() << endl;
	cout << "Typ samochodu:\t\t";
	cout << L[nr_auta].get_typ() << endl;
	cout << "Liczba miejsc:\t\t";
	cout << L[nr_auta].get_liczba_miejsc() << endl;
	cout << "Paliwo:\t\t\t";
	cout << L[nr_auta].get_paliwo() << endl;
	cout << "Cena za dobe:\t\t";
	cout << L[nr_auta].get_cena() << endl;
}

void terminy(int nr, vector<Car> L)		//wyswietla terminy rezerwacji jednego auta
{
	nr--;
	if (L[nr].get_start() == "00000000")
	{
		cout << "\tBrak rezerwacji\n";
		return;
	}
	string start = L[nr].get_start();
	string stop = L[nr].get_stop();
	stringstream imiona;
	stringstream nazwiska;
	imiona << L[nr].get_imiona();
	nazwiska << L[nr].get_nazwiska();
	string aaa;
	vector<string>Imiona;
	vector<string>Nazwiska;

	while (getline(imiona, aaa, '_'))
	{
		Imiona.push_back(aaa);
	}
	while (getline(nazwiska, aaa, '_'))
	{
		Nazwiska.push_back(aaa);
	}



	int l = L[nr].get_start().length();
	cout << "-------------------------------------------------\n";
	cout << "|\t\tTERMINY REZERWACJI\t\t|\n";
	cout << "-------------------------------------------------\n";
	cout << "|\tOd\t\t|\tDo\t\t|\n";
	cout << "-------------------------------------------------\n";
	for (int i = 0; i < l / 8; i++)
	{
		cout << "|\t";
		cout << start[i * 8 + 6] << start[i * 8 + 7] << "." << start[i * 8 + 4] << start[i * 8 + 5] << "." << start[i * 8] << start[i * 8 + 1] << start[i * 8 + 2] << start[i * 8 + 3];
		cout << "\t|\t";
		cout << stop[i * 8 + 6] << stop[i * 8 + 7] << "." << stop[i * 8 + 4] << stop[i * 8 + 5] << "." << stop[i * 8] << stop[i * 8 + 1] << stop[i * 8 + 2] << stop[i * 8 + 3];
		cout << "\t|\t" << Imiona[i] << "\t" << Nazwiska[i] << "\n-------------------------------------------------\n";
	}
}



void admin(vector<Car>& L)
{
	bool blad = true;
	int wybor;
	do
	{
		samochody(L);
		cout << "1.Edytuj cene samochodu\t|\n" << "2.Dodaj samochod\t|\n" << "3.Usun samochod\t\t|\n" << "4.Wroc\t\t\t|\n";
		cout << "------------------------\n";


		while (!(cin >> wybor) || cin.peek() != char_traits<char>::to_int_type('\n')) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
		{
			cout << "BLAD!!! Wybierz numer opcji!\n";
			cin.clear(); //kasowanie flagi b³êdu strumienia
			cin.sync(); //kasowanie zbêdnych znaków z bufora
			cin.ignore(1000, '\n');
		}

		switch (wybor)
		{
		case 1:
			cout << "wybierz numer samochodu:\t";
			while (!(cin >> wybor) || cin.peek() != char_traits<char>::to_int_type('\n')) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
			{
				cout << "BLAD!!! Wybierz numer samochodu!\n";
				cin.clear(); //kasowanie flagi b³êdu strumienia
				cin.sync(); //kasowanie zbêdnych znaków z bufora
				cin.ignore(1000, '\n');
			}

			if (wybor <= L.size() && wybor > 0)
			{
				edytuj_cene(wybor, L);
				zapisz(L);
			}
			else cout << "Ten samochod nie istnieje!\n";
			system("pause");
			break;

		case 2:
			nowy_samochod(L);
			sortuj(L);
			zapisz(L);
			break;
		case 3:
			cout << "wybierz numer samochodu:\t";
			while (!(cin >> wybor) || cin.peek() != char_traits<char>::to_int_type('\n')) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
			{
				cout << "BLAD!!! Wybierz numer samochodu!\n";
				cin.clear(); //kasowanie flagi b³êdu strumienia
				cin.sync(); //kasowanie zbêdnych znaków z bufora
				cin.ignore(1000, '\n');
			}

			if (wybor <= L.size() && wybor > 0)
			{
				usun(wybor, L);
				zapisz(L);
			}
			else cout << "Ten samochod nie istnieje!\n";
			system("pause");
			break;
		case 4:
			blad = false;
			break;
		default:
			break;
		}
	} while (blad);

}

void edytuj_cene(int nr, vector<Car>& L)		//edytuje cene samochodu
{
	system("cls");
	string cena;
	cin.get();
	cout << "Podaj nowa cene za dobe: ";
	getline(cin, cena);
	L[nr - 1].set_cena(cena);

	cout << "Zapisano.\n";
	system("break");

}

void nowy_samochod(vector<Car>& L) //dodaje nowy samochod do wektora
{
	system("cls");
	cin.get();

	cout << "Marka:\t";
	string Marka;
	getline(cin, Marka);

	cout << "Model:\t";
	string Model;
	getline(cin, Model);

	cout << "Typ nadwozia:\t";
	string Typ;
	getline(cin, Typ);

	cout << "Liczba miejsc:\t";
	string Miejsca;
	getline(cin, Miejsca);

	cout << "Cena za dobê:\t";
	string Cena;
	getline(cin, Cena);

	cout << "Rodzaj paliwa:\t";
	string Paliwo;
	getline(cin, Paliwo);

	bool blad;
	do
	{
		cout << "Dodaj samochod --> 1\t";
		cout << "Anuluj --> 2\n";
		int wybor;
		//cin >> wybor;
		while (!(cin >> wybor)) //dopóki strumieñ jest w stanie b³êdu -> dopóki podawane s¹ b³êdne dane
		{
			cout << "BLAD!!! Wybierz numer opcji!\n";
			cin.clear(); //kasowanie flagi b³êdu strumienia
			cin.sync(); //kasowanie zbêdnych znaków z bufora
			cin.ignore(1000, '\n');

		}
		switch (wybor)
		{
		case 1:
			blad = false;
			L.push_back(Car(Marka, Model, Miejsca, Typ, Cena, "00000000", "00000000", Paliwo, "0", "0"));   //dodawanie nowego samochodu
			zapisz(L);
			cout << "Dodano nowy samochod do bazy." << endl;
			system("pause");
			break;
		case 2:
			blad = false;
			break;
		default:
			cout << "Wybrana opcja nie instnieje. Wybierz jeszcze raz\n";
			blad = true;
			break;
		}
	} while (blad);

}