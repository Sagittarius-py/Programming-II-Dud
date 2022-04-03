#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

constexpr int wiersze = 10;
constexpr int kolumny = 10;
int tablica[wiersze][kolumny];

//! Oblicz średnią macierzy, w zależności od decyzji z przekątnymi albo bez

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

int sumaPow(int rozmiar, int tablica[wiersze][kolumny])
{
    int suma;
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
    return suma;
}

int sumaPon(int rozmiar, int tablica[wiersze][kolumny])
{
    int suma;
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
    return suma;
}

int sumaWiersz(int rozmiar, int tablica[wiersze][kolumny])
{
    int tmp = 0, suma;
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
    return suma;
}

int sumaKolumna(int rozmiar, int tablica[wiersze][kolumny])
{
    int tmp = 0, suma;
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
    return suma;
}

float sredniaMac(int rozmiar, int tablica[wiersze][kolumny])
{
    int wybor;
    float temp = 0.0;
    cout << "Czy chcesz obliczyc srednia z przekatnymi czy bez: ";
    cin >> wybor;

    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            temp = temp + tablica[i][j];
        }
    }
    float srednia = temp / (rozmiar * rozmiar);
    wyswietl(rozmiar, tablica);

    return srednia;
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
         << "    5) Oblicz srednia macierzy" << endl
         << "    6) Wyjscie" << endl;

    cin >> wybor;

    switch (wybor)
    {
    case 1:
    {
        int suma = sumaPow(rozmiar, tablica);
        cout
            << endl
            << "Suma wynosi:" << suma;
        goto znacznik;
        break;
    }
    case 2:
    {
        int suma = sumaPon(rozmiar, tablica);
        cout << endl
             << "Suma wynosi:" << suma;
        goto znacznik;
        break;
    }
    case 3:
    {
        int suma = sumaWiersz(rozmiar, tablica);
        cout << endl
             << "Suma wynosi:" << suma;
        goto znacznik;
        break;
    }
    case 4:
    {
        int suma = sumaKolumna(rozmiar, tablica);

        cout << endl
             << "Suma wynosi:" << suma;
        goto znacznik;
        break;
    }
    case 5:
    {
        float srednia = sredniaMac(rozmiar, tablica);
        cout << "Srednia wynosi: " << srednia << endl
             << endl;

        goto znacznik;
        break;
    }
    case 6:
    {
        break;
    }
    }

    return 0;
}
