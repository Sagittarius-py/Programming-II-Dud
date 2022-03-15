#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int litery = 0, literyBezSpacji = 0, literyBezZnaku = 0;
    string zdanie;
    char znak;

    cout << "Wpisz zdanie do analizy: ";
    getline(cin, zdanie);

    cout << "Jaki znak chcesz pominąć: ";
    cin >> znak;

    for (int i = 0; i < zdanie.length(); i++)
    {
        litery++;
        //! Błąd poniżej 
        // if (zdanie[i] != " ")
        // {
        //     literyBezSpacji++;
        // }

        if (zdanie[i] != znak)
        {
            literyBezZnaku++;
        }
    }

    cout << endl
         << zdanie << endl
         << litery << endl
         << literyBezZnaku;

    return 0;
}
