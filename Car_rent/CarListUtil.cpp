#include "CarListUtil.h"
#include "Car.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void wczytaj(vector<Car>& L) //wczytuje dane z plików do programu
{
	fstream Model;
	fstream Marka;
	fstream Liczba_miejsc;
	fstream Typ;
	fstream Cena;
	fstream Start;
	fstream Stop;
	fstream Paliwo;
	fstream Imie;
	fstream Nazwisko;


	Model.open("model.txt", ios::in);
	Marka.open("marka.txt", ios::in);
	Liczba_miejsc.open("liczba_miejsc.txt", ios::in);
	Typ.open("typ.txt", ios::in);
	Cena.open("cena.txt", ios::in);
	Start.open("start.txt", ios::in);
	Stop.open("stop.txt", ios::in);
	Paliwo.open("paliwo.txt", ios::in);
	Imie.open("imie.txt", ios::in);
	Nazwisko.open("nazwisko.txt", ios::in);

	if (Model.good() == false || Marka.good() == false || Liczba_miejsc.good() == false || Typ.good() == false || Cena.good() == false || Start.good() == false || Stop.good() == false || Paliwo.good() == false || Imie.good() == false || Nazwisko.good() == false)
	{
		cout << "Operacja nie powiodla sie!";
		return;
	}

	string marka;
	string model;
	string liczba_miejsc;
	string typ;			//typ nadwozia
	string cena;			//cena za dobê
	string start;		//data poczatku najmu
	string stop;			//konec najmu
	string paliwo;		//rodzaj paliwa
	string imie;
	string nazwisko;

	while (!Marka.eof())
	{
		getline(Marka, marka);
		getline(Model, model);
		getline(Liczba_miejsc, liczba_miejsc);
		getline(Typ, typ);
		getline(Cena, cena);
		getline(Start, start);
		getline(Stop, stop);
		getline(Paliwo, paliwo);
		getline(Imie, imie);
		getline(Nazwisko, nazwisko);


		L.push_back(Car(marka, model, liczba_miejsc, typ, cena, start, stop, paliwo, imie, nazwisko));

	};

	Marka.close();
	Model.close();
	Liczba_miejsc.close();
	Typ.close();
	Cena.close();
	Start.close();
	Stop.close();
	Paliwo.close();
	Imie.close();
	Nazwisko.close();
}

void zapisz(vector<Car>& L) //zapisuje wszystkie samochody do plików
{
	if (L.size() == 0)return;
	fstream Model;
	fstream Marka;
	fstream Liczba_miejsc;
	fstream Typ;
	fstream Cena;
	fstream Start;
	fstream Stop;
	fstream Paliwo;
	fstream Imie;
	fstream Nazwisko;


	Model.open("model.txt", ios::out);
	Marka.open("marka.txt", ios::out);
	Liczba_miejsc.open("liczba_miejsc.txt", ios::out);
	Typ.open("typ.txt", ios::out);
	Cena.open("cena.txt", ios::out);
	Start.open("start.txt", ios::out);
	Stop.open("stop.txt", ios::out);
	Paliwo.open("paliwo.txt", ios::out);
	Imie.open("imie.txt", ios::out);
	Nazwisko.open("nazwisko.txt", ios::out);


	if (Model.good() == false || Marka.good() == false || Liczba_miejsc.good() == false || Typ.good() == false || Cena.good() == false || Start.good() == false || Stop.good() == false || Paliwo.good() == false || Imie.good() == false || Nazwisko.good() == false)
	{
		cout << "Operacja nie powiodla sie!";
		return;
	}

	for (size_t i = 0; i < L.size() - 1; ++i)
	{
		Model << L[i].get_model() << endl;
		Marka << L[i].get_marka() << endl;
		Liczba_miejsc << L[i].get_liczba_miejsc() << endl;
		Typ << L[i].get_typ() << endl;
		Cena << L[i].get_cena() << endl;
		Start << L[i].get_start() << endl;
		Stop << L[i].get_stop() << endl;
		Paliwo << L[i].get_paliwo() << endl;
		Imie << L[i].get_imiona() << endl;
		Nazwisko << L[i].get_nazwiska() << endl;
	}
	Model << L[L.size() - 1].get_model();
	Marka << L[L.size() - 1].get_marka();
	Liczba_miejsc << L[L.size() - 1].get_liczba_miejsc();
	Typ << L[L.size() - 1].get_typ();
	Cena << L[L.size() - 1].get_cena();
	Start << L[L.size() - 1].get_start();
	Stop << L[L.size() - 1].get_stop();
	Paliwo << L[L.size() - 1].get_paliwo();
	Imie << L[L.size() - 1].get_imiona() << endl;
	Nazwisko << L[L.size() - 1].get_nazwiska() << endl;

	Marka.close();
	Model.close();
	Liczba_miejsc.close();
	Typ.close();
	Cena.close();
	Start.close();
	Stop.close();
	Paliwo.close();
	Imie.close();
	Nazwisko.close();
}

bool cena_sort(Car a, Car b)
{
	return a.get_cena() < b.get_cena();
}

void sortuj(vector<Car>& L)		//sortuje auta wg ceny
{
	sort(L.begin(), L.end(), cena_sort);
}

void usun(int nr_samochodu, vector<Car>& L) //usuwa wybrany samochod z wektora
{
	nr_samochodu--;
	L.erase(L.begin() + nr_samochodu);
}
