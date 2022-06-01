#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
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

    Przedmiot()
    {
        this->ocena = 0;
        this->data = "none";
        this->przedmiot = "none";
        this->prowadzacyImie = "none";
        this->prowadzacyNazwisko = "none";
    }

    // Dodawanie oceny na poziomie przedmiotu

    void dodajPrzedmiot(int ocena,
                        string przedmiot,
                        string prowadzacyImie,
                        string prowadzacyNazwisko)
    {
        time_t now = time(0);
        char *data = ctime(&now);
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

    Semestr()
    {
        this->nrSemestru = 0;
    };

    // Dodawanie oceny na poziomie semestru

    void aktualizujSemestr(int semestr, int ocena, string przedmiot, string prowadzacyImie, string prowadzacyNazwisko)
    {
        this->nrSemestru = semestr;
        Przedmiot *tempPrzedmiot = new Przedmiot;

        tempPrzedmiot->dodajPrzedmiot(ocena, przedmiot, prowadzacyImie, prowadzacyNazwisko);
        przedmioty[przedmiot] = tempPrzedmiot;
    };
};

//! Student poniżej =====================

class Student
{
public:
    string nrIndeksu;
    string imie;
    string nazwisko;
    int semestr;

    map<int, Semestr *> semestry;

    Student()
    {
        this->nrIndeksu = "none";
        this->imie = "none";
        this->nazwisko = "none";
        this->semestr = 1;
    };

    void dodajStudenta(string nrIndeksu,
                       string imie,
                       string nazwisko,
                       int semestr)
    {

        this->nrIndeksu = nrIndeksu;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->semestr = semestr;
    }

    // Dodawanie oceny na poziomie studenta

    void dodajOcene(int ocena,
                    string przedmiot,
                    string prowadzacyImie,
                    string prowadzacyNazwisko)
    {

        Semestr *tempSemestr = new Semestr;
        tempSemestr->aktualizujSemestr(semestr, ocena, przedmiot, prowadzacyImie, prowadzacyNazwisko);
    }
};

//? Funkcje =====================

//* dodawanie nowego studenta - funkcja zewnętrzna do komunikacji z użytkownikiem

void dodajNowegoStudenta(map<string, Student *> *studenci)
{
    int semestr;
    string nrIndeksu, imie, nazwisko;

    cout << "Podaj nr indeksu studenta:";
    cin >> nrIndeksu;
    cout << "Podaj imie studenta: ";
    cin >> imie;
    cout << "Podaj nazwisko studenta: ";
    cin >> nazwisko;
    semestr = 1;

    Student *temp = new Student;

    temp->dodajStudenta(nrIndeksu, imie, nazwisko, semestr);

    (*studenci)[nrIndeksu] = temp;
    cout << "penis";
};

//* dodawanie nowej oceny - funkcja zewnętrzna do komunikacji z użytkownikiem

void dodajNowaOcene(map<string, Student *> *studenci)
{
    int ocena;
    string nrIndeksu, przedmiot, prowadzacyImie, prowadzacyNazwisko;

    cout << "Podaj nr indeksu studenta:";
    cin >> nrIndeksu;
    cout << "Podaj  przedmiot: ";
    cin >> przedmiot;
    cout << "Podaj ocene: ";
    cin >> ocena;
    cout << "Podaj imie prowadzacego: ";
    cin >> prowadzacyImie;
    cout << "Podaj nazwisko prowadzacego: ";
    cin >> prowadzacyNazwisko;

    Semestr *tempSemestr = new Semestr;
    (*studenci)[nrIndeksu]->dodajOcene(ocena, przedmiot, prowadzacyImie, prowadzacyNazwisko);
};

//* wyswietlanie wszystkich - funkcja zewnętrzna do komunikacji z użytkownikiem

void wyswietlWszystkich(map<string, Student *> *studenci)
{

    map<string, Student *>::iterator it;
    for (it = (*studenci).begin(); it != (*studenci).end(); it++)
    {
        cout << endl
             << it->second->nrIndeksu << endl
             << it->second->imie << endl
             << it->second->nazwisko << endl
             << it->second->semestr << endl
             << "==========" << endl;
    }
}

//* wyswietlanie studenta - funkcja zewnętrzna do komunikacji z użytkownikiem

void wyswietlStudeta(map<string, Student *> *studenci)
{
    int semestr;
    string nrIndeksu;
    cout << "Podaj nr indeksu studenta:";
    cin >> nrIndeksu;

    Student *tempStudent = (*studenci)[nrIndeksu];
    cout << endl
         << "Imie: " << tempStudent->imie << endl
         << "Nazwisko: " << tempStudent->nazwisko << endl
         << "Semestr: " << tempStudent->semestr << endl;

    cout << "Czy chcesz wyswietlic oceny studenta(jesli tak podaj semestr, jesli nie wpisz 0): ";
    cin >> semestr;

    if (semestr > 0)
    {
        map<string, Przedmiot *> listaOcen = (*studenci)[nrIndeksu]->semestry[semestr]->przedmioty;
        
        map<string, Przedmiot *>::iterator it;
        for (it = (listaOcen).begin(); it != (listaOcen).end(); it++)
        {
            cout << endl
                 << it->first << " : " << endl
                 << it->second->ocena << endl
                 << it->second->data << endl
                 << it->second->prowadzacyImie << " " << it->second->prowadzacyNazwisko << endl
                 << "==========" << endl;
        }
    }
};

//* main

int main()
{
    int wybor = 0;
    map<string, Student *> studenci;

    do
    {
        cout << "Co chcesz zrobic: " << endl
             << "   1) Dodaj studenta" << endl
             << "   2) Wyswietl studenta wg. nr dziennika" << endl
             << "   3) Wyswietl wszystkich studentow" << endl
             << "   4) Dodaj ocene dla studenta" << endl;
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            dodajNowegoStudenta(&studenci);
            break;
        case 2:
            wyswietlStudeta(&studenci);
            break;
        case 3:
            wyswietlWszystkich(&studenci);
            break;
        case 4:
            dodajNowaOcene(&studenci);
            break;
        }
    } while (wybor < 10);

    return 0;
}