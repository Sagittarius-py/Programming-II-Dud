#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int ilosc = 0;
    float srednia = 0;

    cout << "Ile chcesz wpisac przedmiotow do obliczenia sredniej: ";
    cin >> ilosc;

    std::string _words[10];
    float ocena[10];

    for (int i = 0; i < ilosc; i++)
    {
        //! For wywołuje sie odpowiednio ale nie pyta o cin więcej niż za 1 razem cokolwiek

        cout << "Podaj " << i + 1 << " przedmiot: ";
        cin >> _words[i];

        cout << "Podaj ocene: ";
        cin >> ocena[i];
        cout << endl;
    }
    cout << endl
         << endl;

    cout << "Podales przedmioty: " << endl;
    for (int i = 0; i < ilosc; i++)
    {
        srednia = srednia + ocena[i];
        cout << _words[i] << ": " << ocena[i] << endl;
    }
    srednia = srednia / ilosc;
    cout << "Twoja srednia wynosi: " << srednia << endl;

    if (srednia > 4.1)
    {
        cout << "Przysluguje ci stypendium!";
    }
    else
    {
        cout << "Nie przysluguje ci stypendium!";
    }

    return 0;
}
