#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

//! wyświwtl wszystkie wyliczenia odsetek

float obliczanieLokaty(float lokata, float wartosc, int procet, int okres)
{
    int czas = 0;
    float czasNaliczki = 12.0 / okres, temp = lokata, wzrost = procet / czasNaliczki;

    int i = 1;
    while (temp - lokata <= wartosc)
    {
        temp = temp + temp * (wzrost * 0.01);
        czasNaliczki--;
        czas = czas + okres;
        i++;
        cout << temp << " zl" << endl;
    };

    wartosc = temp - lokata;
    lokata = temp;

    cout << endl
         << "Dokladna uzyskana wartosc wynosi: " << round(wartosc * 100) / 100;

    return czas;
}

int main()
{
    float lokata, wartosc;
    int procet, okres;

    cout << "Podaj wartosc lokaty: ";
    cin >> lokata;

    cout << "Podaj oprocetowanie roczne: ";
    cin >> procet;

    cout << "Podaj okres kapitalizacji (co ile miesiecy nastepuje wzrost): ";
    cin >> okres;

    cout << "Podaj ile chcesz uzyskac z odsetek: ";
    cin >> wartosc;

    int czas = obliczanieLokaty(lokata, wartosc, procet, okres);

    cout << endl
         << "Oczekiwana kwote otrzymasz po: "
         << czas << " miesiacach";

    return 0;
}
