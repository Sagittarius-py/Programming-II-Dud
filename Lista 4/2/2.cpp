#include <time.h>
#include <iostream>
#include <vector>

#include "2lib.h"

using namespace std;

int main()
{
    srand(time(NULL));

    int szer = 1, wys = 1, wybor = 1;

    cout << "Podaj jakiej szerokosci ma byc macierz: ";
    cin >> szer;

    cout << "Podaj jakiej wysokosci ma byc macierz: ";
    cin >> wys;

    vector<vector<int>> macierz1 = generujMacierz(wys, szer);
    wyswietlMacierz(macierz1);

    vector<vector<int>> macierz2 = generujMacierz(wys, szer);
    wyswietlMacierz(macierz2);

    do
    {
        cout << "Co chcesz zrobic: " << endl
             << "   1) Dodac macierze." << endl
             << "   2) Odjac macierze." << endl
             << "   3) Przemnorzyc macierze przez siebie." << endl
             << "   4) Obliczyc dopelnienie macierzy 1." << endl
             << "   5) Wyjsc."
             << endl;
        cin >> wybor;
        cout << endl;

        if (wybor > 0 && wybor < 3)
        {
            vector<vector<int>> wynik = operacja(macierz1, macierz2, wybor);
            wyswietlMacierz(wynik);
        }
        if (wybor == 3)
        {
            vector<vector<int>> wynik = mnozenie(macierz1, macierz2);
            wyswietlMacierz(wynik);
        }
        if (wybor == 4)
        {
            vector<vector<int>> wynik = dopelnienie(macierz1, macierz2);
            wyswietlMacierz(wynik);
        }

    } while (wybor > 0 && wybor < 5);
    return 0;
}