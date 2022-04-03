#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> wczytajWektor()
{
    int n = 0;
    vector<int> wektor;
    cout << "Ile liczb chcesz podac?: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Podaj " << i + 1 << " liczbe: ";
        cin >> wektor[i];
    }

    return wektor;
}