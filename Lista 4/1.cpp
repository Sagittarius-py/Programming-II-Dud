#include <stdio.h>
#include <iostream>
#include <vector>

#include "1headers.hpp"

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

int znajdz(vector<int> wektor)
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

    cout << max << " : " << max_pozycja << endl
         << min << " : " << min_pozycja << endl;

    // int lista[4] = {max, max_pozycja, min, min_pozycja};

    // return lista;
    return 0;
}

int main()
{
    vector<int> wektor = wczytajWektor();
    znajdz(wektor);
    // int wynik[4] = znajdz(wektor);

    for (int i = 0; i < wektor.size(); i++)
    {
        cout << wektor.at(i) << endl;
    }

    return 0;
}
