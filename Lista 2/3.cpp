#include <stdio.h>
#include <iostream>

using namespace std;


int main()
{
    int ilosc = 0, czyPusta = 0;

    cout << "Podaj ilosc poziomow piramidy: ";
    cin >> ilosc;

    cout << "Czy piramida ma byc pusta(podaj 0) czy pelna w srodku(podaj 1): ";
    cin >> czyPusta;

    int cokolwiek = 0;

    if (czyPusta == 1)
    {
        for (int i = 0; i <= ilosc; i++)
        {
            for (int l = 0; l < cokolwiek; l++)
            {
                cout << " ";
            }
            for (int j = ilosc; j > i; j--)
            {
                cout << "*"
                     << " ";
            }
            cokolwiek++;
            cout << endl;
        }
    }
    else if (czyPusta == 0)
    {
        for (int i = 0; i <= ilosc; i++)
        {
            for (int l = 0; l < cokolwiek; l++)
            {
                cout << " ";
            }
            for (int j = ilosc; j > i; j--)
            {
                if (j == ilosc || j == i + 1 || i == 0)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
                cout << " ";
            }
            cokolwiek++;
            cout << endl;
        }
    }
    else
    {
        cout << "Podano nieprawidlowa wartosc pelna czy pusta";
    }

    return 0;
}
