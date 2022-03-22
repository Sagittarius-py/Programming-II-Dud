#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

constexpr int wiersze = 10;
constexpr int kolumny = 10;
int tablica[wiersze][kolumny];

void wyswietl(int rozmiar, int wyswietlana[wiersze][kolumny])
{
    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            cout << "|" << tablica[i][j];
        }
        cout << "|" << endl;
    }
}

int main()
{
    srand(time(NULL));

    int rozmiar, wybor, suma;
    cout << "Podaj rozmiar 2-wymiarowej macierzy kwadratowej: ";
    cin >> rozmiar;

    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            tablica[i][j] = rand() % 10;
        }
    }

    wyswietl(rozmiar, tablica);

znacznik:

    cout << endl
         << endl
         << "Ktora z sum chcesz obliczyc: " << endl
         << "    1) Oblicz sume powyzej przekatnej" << endl
         << "    2) Oblicz sume ponizej przekatnej" << endl
         << "    3) Oblicz sume podanego wiersza" << endl
         << "    4) Oblicz sume podanej kolumny" << endl
         << "    5) Wyjscie" << endl;

    cin >> wybor;

    switch (wybor)
    {
    case 1:
    {
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if (j > i)
                {
                    suma = suma + tablica[i][j];
                }
            }
        }
        wyswietl(rozmiar, tablica);
        cout << endl
             << "Suma wynosi:" << suma;
        goto znacznik;
        break;
    }
    case 2:
    {
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if (j < i)
                {

                    suma = suma + tablica[i][j];
                }
            }
        }
        wyswietl(rozmiar, tablica);
        cout << endl
             << "Suma wynosi:" << suma;
        goto znacznik;
        break;
    }
    case 3:
    {
        int tmp = 0;
        cout << "Podaj nr. wiersza ktorego sume chcesz obliczyc: ";
        cin >> tmp;

        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if (i == tmp - 1)
                {

                    suma = suma + tablica[i][j];
                }
            }
        }
        wyswietl(rozmiar, tablica);
        cout << endl
             << "Suma wynosi:" << suma;
        goto znacznik;
        break;
    }
    case 4:
    {
        int tmp = 0;
        cout << "Podaj nr. kolumny ktorej sume chcesz obliczyc: ";
        cin >> tmp;

        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if (j == tmp - 1)
                {

                    suma = suma + tablica[i][j];
                }
            }
        }
        wyswietl(rozmiar, tablica);
        cout << endl
             << "Suma wynosi:" << suma;
        goto znacznik;
        break;
    }
    case 5:
    {
        break;
    }
    }

    return 0;
}
