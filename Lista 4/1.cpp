#include <stdio.h>
#include <iostream>
#include <vector>
#include "1lib.hpp"

using namespace std;

int main()
{
    vector<int> wektor = wczytajWektor();

    for (int i = 0; i < 5; i++)
    {
        cout << wektor[i] << endl;
    }
    return 0;
}
