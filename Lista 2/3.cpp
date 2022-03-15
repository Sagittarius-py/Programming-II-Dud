#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int ilosc = 0;

    cout << "Podaj ilosc poziomow piramidy: ";
    cin >> ilosc;

    int cokolwiek = ilosc;

    for (int i = 0; i <= ilosc; i++)
    {
        for (int l = cokolwiek; l > 0; l--)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "*"
                 << " ";
        }
        cokolwiek--;
        cout << endl;
    }

    return 0;
}
