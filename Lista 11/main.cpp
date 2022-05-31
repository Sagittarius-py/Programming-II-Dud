#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <ctime>

using namespace std;

//! Przedmiot poniżej =====================

class Przedmiot
{
public:
    int ocena;
    string data;
    string przedmiot;
    string prowadzacyImie;
    string prowadzacyNazwisko;

    Przedmiot(int ocena,
              string data,
              string przedmiot,
              string prowadzacyImie,
              string prowadzacyNazwisko)
    {
        this->ocena = ocena;
        this->data = data;
        this->przedmiot = przedmiot;
        this->prowadzacyImie = prowadzacyImie;
        this->prowadzacyNazwisko = prowadzacyNazwisko;
    }
};

//? Semestr poniżej =====================

class Semestr
{
public:
    int nrSemestru;
    map<string, Przedmiot *> przedmioty;

    Semestr();
};

//! Student poniżej =====================

class Student
{
public:
    int nrIndeksu;
    string imie;
    string nazwisko;
    int semestr;

    map<int, Semestr *> semestry;

    Student()
    {
        this->nrIndeksu = nrIndeksu;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->semestr = semestr;
    };

    int dodajStudenta(int nrIndeksu,
                      string imie,
                      string nazwisko,
                      int semestr)
    {

        this->nrIndeksu = nrIndeksu;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->semestr = semestr;
        cout << "gówno";

        return 0;
    }

    // this->semestry[klucz]->ocena;

    void dodajOcene(int semestr,
                    int ocena,
                    string przedmiot,
                    string prowadzacyImie,
                    string prowadzacyNazwisko)
    {
        time_t now = time(0);
        char *data = ctime(&now);
    }
};

//? Funkcje =====================

void dodajNowegoStudenta(map<int, Student *> *studenci)
{
    int nrIndeksu, semestr;
    string imie, nazwisko;

    cout << "Podaj nr indeksu studenta:";
    cin >> nrIndeksu;
    cout << "Podaj imie studenta: ";
    cin >> imie;
    cout << "Podaj nazwisko studenta: ";
    cin >> nazwisko;
    semestr = 1;

    Student *temp;

    temp->dodajStudenta(nrIndeksu, imie, nazwisko, semestr);

    (*studenci)[nrIndeksu] = temp;
};

int main()
{

    map<int, Student *> studenci;
    dodajNowegoStudenta(&studenci);

    int klucz;
    cin >> klucz;

    cout << studenci.size() << endl
         << studenci[klucz]->nazwisko;

    return 0;
}