#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>

#include "1lib.h"

using namespace std;

vector<int> wczytajWektor()
{
    int n = 0;
    vector<int> wektor;
    cout << "Ile liczb chcesz podac?: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cout << "Podaj " << i + 1 << " liczbe: ";
        cin >> temp;
        wektor.push_back(temp);
    }

    return wektor;
}

tuple<int, int, int, int> znajdz(vector<int> wektor)
{
    int max = wektor.at(0), min = wektor.at(0), max_pozycja = 0, min_pozycja = 0;
    for (int i = 0; i < wektor.size(); i++)
    {
        if (max <= wektor.at(i))
        {
            max = wektor.at(i);
            max_pozycja = i + 1;
        }

        if (min >= wektor.at(i))
        {
            min = wektor.at(i);
            min_pozycja = i + 1;
        }
    }

    return make_tuple(max, max_pozycja, min, min_pozycja);
}

float srednia(vector<int> wektor)
{
    float srednia = 0.0;

    for (int i = 0; i < wektor.size(); i++)
    {
        srednia = srednia + wektor.at(i);
    }

    srednia = srednia / wektor.size();
    cout << srednia << endl;
    return srednia;
}

tuple<int, int> szukajWartosci(vector<int> wektor)
{
    int szukana, szukana_poz;

    cout << "Jaka liczbe chcesz znalezc: ";
    cin >> szukana;

    for (int i = 0; i < wektor.size(); i++)
    {
        if (wektor.at(i) == szukana)
        {
            szukana_poz = i + 1;
        }
    }

    return make_tuple(szukana, szukana_poz);
}