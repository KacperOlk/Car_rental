#pragma once
#include "Car.h"
#include <vector>
using namespace std;

void menu_gl();
void samochody(vector<Car> L);				// wyswietla samochody
void wyswietl(int nr_auta, vector<Car> L);	//wyswietla jeden wybrany samochod
void terminy(int nr, vector<Car> L);		//wyswietla terminy rezerwacji jednego auta
void admin(vector<Car>& L);
void edytuj_cene(int nr, vector<Car>& L);	//edytuje cene samochodu
void nowy_samochod(vector<Car>& L);			//dodaje nowy samochod do wektora
void wypozycz_samochod(vector<Car>& L);
bool dostepny(string ustart, string ustop, string start, string stop);

