#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Macierze
{
    template <typename F>
    void loopunkt2d(Macierze a, Macierze &b, size_t width, size_t height, F func)
    {
        for (size_t y = 0; y < height; y++)
            for (size_t x = 0; x < width; x++)
                func(a, b, x, y);
    }

    // przeciążyć operator negacji

public:
    vector<vector<T>> m;

    Macierze operator!()
    {

        for (size_t y = 0; y < 3; y++)
            for (size_t x = 0; x < 3; x++)
                m[y][x] = -m[y][x];
        return (*this);
    }

    Macierze operator+(Macierze a)
    {
        loopunkt2d(*this, a, a.m.size(), a.m[0].size(), [](Macierze a, Macierze &b, int x, int y)
                   { b.m[x][y] = a.m[x][y] + b.m[x][y]; });
        return a;
    }

    Macierze operator-(Macierze a)
    {
        loopunkt2d(*this, a, a.m.size(), a.m[0].size(), [](Macierze a, Macierze &b, int x, int y)
                   { b.m[x][y] = a.m[x][y] - b.m[x][y]; });
        return a;
    }

    Macierze operator*(Macierze a)
    {
        loopunkt2d(*this, a, a.m.size(), a.m[0].size(), [](Macierze a, Macierze &b, int x, int y)
                   { b.m[x][y] = a.m[x][y] * b.m[x][y]; });
        return a;
    }

    Macierze operator/(Macierze a)
    {
        loopunkt2d(*this, a, a.m.size(), a.m[0].size(), [](Macierze a, Macierze &b, int x, int y)
                   { b.m[x][y] = a.m[x][y] / b.m[x][y]; });
        return a;
    }

    friend ostream &operator<<(ostream &out, const Macierze &m)
    {
        for (size_t y = 0; y < m.m[0].size(); y++)
        {
            for (size_t x = 0; x < m.m.size(); x++)
                out << m.m[x][y] << " ";

            out << endl;
        }
        return out;
    }
};

class Point3d
{
public:
    int x, y, z;

    Point3d operator+(Point3d a)
    {
        return {x + a.x, y + a.y, z + a.z};
    }

    Point3d operator-(Point3d a)
    {
        return {a.x - x, a.y - y, a.z - z};
    }

    Point3d operator*(Point3d a)
    {
        return {x * a.x, y * a.y, z * a.z};
    }

    Point3d operator/(Point3d a)
    {
        return {x / a.x, y / a.y, z / a.z};
    }

    Point3d operator!()
    {
        return {-x, -y, -z};
    }

    Point3d operator-()
    {
        return {-x, -y, -z};
    }

    friend ostream &operator<<(ostream &out, const Point3d &p)
    {
        out << p.x << "," << p.y << "," << p.z;
        return out;
    }
};

int main()
{
    srand(time(NULL));
    Macierze<int> macierz[2];
    Macierze<Point3d> punkt[2];

    const int w = 3, h = 3;

    for (int n = 0; n < 2; n++)
    {
        macierz[n].m.resize(w);
        punkt[n].m.resize(w);
        for (int x = 0; x < w; x++)
            for (int y = 0; y < h; y++)
            {
                macierz[n].m[x].push_back(rand() % 5 + 1);
                punkt[n].m[x].push_back({rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1});
            }
    }

    cout << "================================================" << endl
         << "Macierze: " << endl
         << "================================================" << endl
         << endl;

    cout << macierz[0] << endl
         << macierz[1] << endl;
    cout << "macierz1 + macierz2:\n"
         << macierz[0] + macierz[1] << endl;
    cout << "macierz1 - macierz2:\n"
         << macierz[0] - macierz[1] << endl;
    cout << "macierz1 * macierz2:\n"
         << macierz[0] * macierz[1] << endl;
    cout << "macierz1 / macierz2:\n"
         << macierz[0] / macierz[1] << endl;
    cout << "!macierz1 & !macierz2:\n"
         << !macierz[0] << endl
         << !macierz[1] << endl;

    cout << "================================================" << endl
         << "Punkty: " << endl
         << "================================================" << endl
         << endl;

    cout << punkt[0] << endl
         << punkt[1] << endl;
    cout << "punkt1 + punkt2:\n"
         << punkt[0] + punkt[1] << endl;
    cout << "punkt1 - punkt2:\n"
         << punkt[0] - punkt[1] << endl;
    cout << "punkt1 * punkt2:\n"
         << punkt[0] * punkt[1] << endl;
    cout << "punkt1 / punkt2:\n"
         << punkt[0] / punkt[1] << endl;
    cout << "!punkt[0] & !punkt[1]" << endl
         << !punkt[0] << endl
         << !punkt[1] << endl;
}