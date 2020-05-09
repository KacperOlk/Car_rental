#pragma once
#include <string>
using namespace std;
class Car
{
private:
	string _marka;
	string _model;
	string _liczba_miejsc;
	string _typ;			//typ nadwozia
	string _cena;			//cena za dobê
	string _start;		//data poczatku najmu
	string _stop;			//konec najmu
	string _paliwo;			//rodzaj paliwa
	string _imiona;
	string _nazwiska;		//dane osob wypozyczajacych
public:
	Car(string, string, string, string, string, string, string, string, string, string);

	string get_marka(void);
	string get_model(void);
	string get_liczba_miejsc(void);
	string get_typ(void);
	string get_cena(void);
	string get_start(void);
	string get_stop(void);
	string get_paliwo(void);
	string get_imiona(void);
	string get_nazwiska(void);

	void set_start(string start);
	void set_stop(string stop);
	void set_cena(string cena);
	void set_imie(string imiona);
	void set_nazwisko(string nazwiska);

	void rezerwuj(string start, string stop, string imie, string nazwisko);		//dodaje rezerwacje
};

