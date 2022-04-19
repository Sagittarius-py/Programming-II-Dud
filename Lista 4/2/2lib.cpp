#include <time.h>
#include <iostream>
#include <vector>

#include "2lib.h"

using namespace std;

typedef vector<vector<int>> Macierz;

Macierz generujMacierz(int wys, int szer)
{
    vector<vector<int>> wektor;

    for (int i = 0; i < wys; i++)
    {
        vector<int> wiersz = {};

        for (int j = 0; j < szer; j++)
        {
            // int temp = 0;
            // cout << "Podaj liczbe: ";
            // cin >> temp;
            // wiersz.push_back(temp);
            wiersz.push_back(rand() % 10);
        }
        wektor.push_back(wiersz);
    }

    return wektor;
}

Macierz operacja(const Macierz &macierz1, const Macierz &macierz2, int wybor)
{
    Macierz macierzWyjsciowa;

    for (int i = 0; i < macierz1.size(); i++)
    {
        vector<int> wiersz = {};

        for (int j = 0; j < macierz1[i].size(); j++)
        {
            int temp;
            if (wybor == 1)
            {
                temp = macierz1[i][j] + macierz2[i][j];
            }
            else if (wybor == 2)
            {
                temp = macierz1[i][j] - macierz2[i][j];
            }
            wiersz.push_back(temp);
        }
        macierzWyjsciowa.push_back(wiersz);
    }

    return macierzWyjsciowa;
}

Macierz mnozenie(const Macierz &macierz1, const Macierz &macierz2)
{
    Macierz macierzWyjsciowa;

    for (int i = 0; i < macierz1.size(); i++)
    {
        vector<int> wiersz = {};
        for (int j = 0; j < macierz2[j].size(); j++)
        {
            int temp = 0;
            for (int k = 0; k < macierz2[i].size(); k++)
            {
                temp = temp + macierz1[i][k] * macierz2[k][j];
            }
            wiersz.push_back(temp);
        }

        macierzWyjsciowa.push_back(wiersz);
    }

    return macierzWyjsciowa;
}

void wyswietlMacierz(const Macierz &macierz)
{
    for (int i = 0; i < macierz.size(); i++)
    {

        vector<int> wiersz = {};

        for (int j = 0; j < macierz[i].size(); j++)
        {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

Macierz dopelnienie(const Macierz &macierz1, const Macierz &macierz2)
{
    Macierz macierzWyjsciowa;
    int dopelniana = 0, wybor = 1;
    cout << "Podaj wartosc do dopelnienia: ";
    cin >> dopelniana;
    cout << "Czy chcesz przeprowadzic operacje na macierzy 1 czy 2?: ";
    cin >> wybor;

    for (int i = 0; i < macierz1.size(); i++)
    {
        vector<int> wiersz = {};;

        for (int j = 0; j < macierz1[i].size(); j++)
        {
            if (wybor == 1)
            {
                int temp = dopelniana - macierz1[i][j];
                wiersz.push_back(temp);
            }
            else
            {
                int temp = dopelniana - macierz2[i][j];
                wiersz.push_back(temp);
            }
        }
        macierzWyjsciowa.push_back(wiersz);
    }

    return macierzWyjsciowa;
}