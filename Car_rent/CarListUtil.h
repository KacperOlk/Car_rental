#pragma once
#include <vector>
#include "Car.h"
using namespace std;
void wczytaj(vector<Car>& L);
void zapisz(vector<Car>& L);
bool cena_sort(Car a, Car b);
void sortuj(vector<Car>& L);
void usun(int nr_samochodu, vector<Car>& L);
