#include <time.h>
#include <iostream>
#include <vector>

#include "2lib.h"

using namespace std;

vector<vector<int>> generujMacierz(int wys, int szer)
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

vector<vector<int>> operacja(const vector<vector<int>> &macierz1, const vector<vector<int>> &macierz2, int wybor)
{
    vector<vector<int>> macierzWyjsciowa;

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

vector<vector<int>> mnozenie(const vector<vector<int>> &macierz1, const vector<vector<int>> &macierz2)
{
    vector<vector<int>> macierzWyjsciowa;

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

void wyswietlMacierz(const vector<vector<int>> &macierz)
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