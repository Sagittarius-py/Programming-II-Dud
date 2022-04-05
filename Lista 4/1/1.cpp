#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>

#include "1lib.h"

using namespace std;

int main()
{
    int max, max_pozycja, min, min_pozycja, szukana, szukana_poz;

    vector<int> wektor = wczytajWektor();

    tie(max, max_pozycja, min, min_pozycja) = znajdz(wektor);

    for (int i = 0; i < wektor.size(); i++)
    {
        cout << wektor.at(i) << endl;
    }

    float sr = srednia(wektor);

    tie(szukana, szukana_poz) = szukajWartosci(wektor);

    cout
        << max << " : " << max_pozycja << endl
        << min << " : " << min_pozycja << endl;

    if (szukana_poz != 0)
    {
        cout << endl
             << "Szukana liczba ostatni raz wystapila na pozycji: " << szukana_poz;
    }
    else
    {
        cout << endl
             << "Podana wartosc nie znajduje sie w zbiorze liczb";
    }

    return 0;
}
