#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int litery = 0, literyBezSpacji = 0, literyBezZnaku = 0;
    string zdanie, slowo;
    char znak, znak2;

    cout << "Wpisz zdanie do analizy: ";
    getline(cin, zdanie);

    cout << "Jaki znak chcesz pominac: ";
    cin >> znak;

    cout << "Jaki znak wg ktorego chcesz podzielic zdanie: ";
    cin >> znak2;

    for (int i = 0; i < zdanie.length(); i++)
    {
        litery++;
        if (zdanie[i] != ' ')
        {
            literyBezSpacji++;
        }

        if (zdanie[i] != znak)
        {
            literyBezZnaku++;
        }
    }

    cout << endl
         << zdanie << endl
         << "Ilosc liter: " << litery << endl
         << "Ilosc liter bez spacji : " << literyBezSpacji << endl
         << "Ilosc liter bez podanego znaku: " << literyBezZnaku << endl;

    cout << endl
         << "Podzial slowa na wyrazy: " << endl
         << " ";
    for (int i = 0; i <= zdanie.length(); i++)
    {
        if (zdanie[i] != ' ')
        {
            slowo += zdanie[i];
            // cout << slowo << endl;
        }
        else
        {
            cout << slowo << endl;
            slowo = ' ';
        }

        if (i == zdanie.length())
        {
            cout << slowo << endl;
        }
    }

    slowo = ' ';

    cout << endl
         << "Podzial slowa wg. znaku podanego przez uzytkownika: " << endl
         << " ";
    for (int i = 0; i <= zdanie.length(); i++)
    {
        if (zdanie[i] != znak2)
        {
            slowo += zdanie[i];
            // cout << slowo << endl;
        }
        else
        {
            cout << slowo << endl;
            slowo = ' ';
        }

        if (i == zdanie.length())
        {
            cout << slowo << endl;
        }
    }

    return 0;
}
