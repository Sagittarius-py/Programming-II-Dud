#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int liczby[15], temp = 0, pozycja, liczbaDoSprawdzenia, pozycja2;
    float srednia;

    //! Tworzenie zbioru

    cout << "Podaj 15 liczb." << endl;
    for (int i = 0; i < 15; i++)
    {
        // liczby[i] = rand() % 1000 + 1;

        cout << "Liczba " << i + 1 << ": ";
        cin >> liczby[i];
    }

    cout << "Podaj wartosc ktorej pozycje chcesz otwierdzic: ";
    cin >> liczbaDoSprawdzenia;

    //! Największa

    for (int i = 0; i < 15; i++)
    {
        if (liczby[i] > temp && liczby[i] > liczby[i + 1])
        {
            temp = liczby[i];
            pozycja = i;
        }
    }

    //! średnia

    for (int i = 0; i < 15; i++)
    {
        srednia = srednia + liczby[i];
    }
    srednia = srednia / 15.0;

    //! Pozycja
    for (int i = 0; i < 15; i++)
    {
        if (liczby[i] == liczbaDoSprawdzenia)
        {
            pozycja2 = i + 1;
        }
    }

    //! Wynik

    cout << "Najwieksza liczba w zbiorze to: " << temp << ", a jej pozycja to: " << pozycja << endl
         << "Srednia zbioru wynosi: " << srednia << endl
         << "Podana liczba znajduje sie na pozycji: " << pozycja2;

    return 0;
}
