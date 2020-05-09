#include "Car.h"
#include <string>
using namespace std;

Car::Car(string marka, string model, string liczba_miejsc, string typ, string cena, string start, string stop, string paliwo, string imiona, string nazwiska) : _marka{ marka }, _model{ model }, _liczba_miejsc{ liczba_miejsc }, _typ{ typ }, _cena{ cena }, _start{ start }, _stop{ stop }, _paliwo{ paliwo }, _imiona{ imiona }, _nazwiska{ nazwiska }{ }

string Car::get_marka(void) { return _marka; }
string Car::get_model(void) { return _model; }
string Car::get_liczba_miejsc(void) { return _liczba_miejsc; }
string Car::get_typ(void) { return _typ; }
string Car::get_cena(void) { return _cena; }
string Car::get_start(void) { return _start; }
string Car::get_stop(void) { return _stop; }
string Car::get_paliwo(void) { return _paliwo; }
string Car::get_imiona(void) { return _imiona; }
string Car::get_nazwiska(void) { return _nazwiska; }

void Car::set_start(string start) { _start = start; }
void Car::set_stop(string stop) { _stop = stop; }
void Car::set_cena(string cena) { _cena = cena; }
void Car::set_imie(string imiona) { _imiona = imiona; }
void Car::set_nazwisko(string nazwiska) { _nazwiska = nazwiska; }

void Car::rezerwuj(string start, string stop, string imie, string nazwisko)		//dodaje rezerwacje
{
	_start += start;
	_stop += stop;

	_imiona += imie;
	_imiona += '_';

	_nazwiska += nazwisko;
	_nazwiska += '_';
}
