#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

const float pi = 3.141592;

// dodać stożek ścięty!

float kula()
{
    float r = 0;

    cout << "Podaj srednice: ";
    cin >> r;

    cout << endl
         << "Objetosc kuli wynosi: " << (4 / 3.0) * pi * (r * r * r) << endl;

    cout << endl
         << "Pole kuli wynosi: " << 4 * pi * (r * r) << endl;

    return 0;
};

float kostka()
{
    float a = 0, b = 0, c = 0;
    cout << "Podaj pierwszy wymiar: ";
    cin >> a;
    cout << "Podaj drugi wymiar: ";
    cin >> b;
    cout << "Podaj trzeci wymiar: ";
    cin >> c;

    cout << endl
         << "Objetosc prostopadloscianu wynosi: " << a * b * c << endl;

    cout << endl
         << "Pole prostopadloscianu wynosi: " << 2 * (a * b + a * c + b * c) << endl;

    return 0;
};

float stozek()
{
    float r = 0, h = 0, l = 0;

    cout << "Podaj srednice: ";
    cin >> r;
    cout << "Podaj wysokosc: ";
    cin >> h;

    l = sqrt(r * r + h * h);

    cout << endl
         << "Objetosc stozka wynosi: " << (r * r * pi) * h / 3.0 << endl;
    cout << endl
         << "Pole stozka wynosi: " << (r * r * pi) + pi * r * l << endl;

    return 0;
}

float stozekSciety()
{
    float r = 0, h = 0, l = 0, R = 0;

    cout << "Podaj srednice 1: ";
    cin >> r;
    cout << "Podaj srednice 2: ";
    cin >> R;
    cout << "Podaj wysokosc: ";
    cin >> h;
    cout << "Podaj dlugosc tworzacej: ";
    cin >> l;

    cout << endl
         << "Objetosc stozka wynosi: " << pi / 3.0 * ((R * R) + (R * r) + (r * r)) * h << endl;
    cout << endl
         << "Pole stozka wynosi: " << pi * ((R * R) + (r * r) + (R + r) * l) << endl;

    return 0;
}

float walec()
{
    float r = 0, h = 0;

    cout << "Podaj srednice: ";
    cin >> r;
    cout << "Podaj wysokosc: ";
    cin >> h;

    cout << endl
         << "Objetosc walca wynosi: " << (r * r * pi) * h << endl;
    cout << endl
         << "Pole walca wynosi: " << (2 * r * pi * h) + (2 * r * r * pi) << endl;

    return 0;
}

int main()
{
    int wybor = 0, stan = 0, obj = 0;
    do
    {
        cout << "Wybierz figure do obliczenia:" << endl
             << "  1) Kula" << endl
             << "  2) Prostopadloscian" << endl
             << "  3) Stozek" << endl
             << "  4) Walec" << endl
             << "  5) Stozek sciety" << endl;

        cout << "-->";
        cin >> wybor;

        if ((wybor > 5) || (wybor < 1))
        {
            cout << "Wybrano zla opcje, prosze wybrac ponownie." << endl
                 << endl;
            ;
            stan = 0;
        }
        else
        {
            stan = 1;
        }

    } while (stan == 0);

    switch (wybor)
    {
    case 1:
        kula();
        break;

    case 2:
        kostka();
        break;

    case 3:
        stozek();
        break;

    case 4:
        walec();
        break;
    case 5:
        stozekSciety();
        break;
    }

    return 0;
}
