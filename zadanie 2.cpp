#include <iostream>
#include <math.h>
#include <iomanip>
#define M_PI 3.14159265358979323846
using namespace std;

void function_output(long double radian);
long double convertation(long double radian);

int main()
{
    setlocale(LC_ALL, "Russian");
    float radianf;
    double radiand;
    long double radian;
    const long double a = 90.0, p = 180.0, c = 270.0, d = 360.0;
    int i;
    while (1)
    {
        cout << "В каких значениях вы хотите ввести значение?\n1 - Радиан\n2 - Градусы\n";
        cin >> i;
        start:
        cout << "Введите значение: ";
        switch (i)
        {
        case 1:
            cin >> radian;
            radiand = radian;
            radianf = radiand;
            function_output(radianf);
            function_output(radiand);
            function_output(radian);
            break;
        case 2:
            cin >> radian;
            if (radian > 360.0) { cout << "Введите значение меньше 360 "; goto start; }
            if (radian == a)
            {
                cout << setprecision(7) << "Синус: " << 1 << endl
                    << "Косинус: " << 0 << endl
                    << "Тангенс: " <<  "inf" << endl
                    << "Котангенс: " << 0 <<endl;
                break;
            }
            else if (radian == c)
            {
                cout << setprecision(7) << "Синус: " << 0 << endl
                    << "Косинус: " << -1 << endl
                    << "Тангенс: " << 0 << endl
                    << "Котангенс: " << "inf" << endl;
                break;
            }
            else if (radian == p)
            {
                cout << setprecision(7) << "Синус: " << 0 << endl
                    << "Косинус: " << -1 << endl
                    << "Тангенс: " << 0 << endl
                    << "Котангенс: " << "inf" << endl;
                break;
            }
            else if (radian == d)
            {
                cout << setprecision(7) << "Синус: " << 0 << endl
                    << "Косинус: " << 1 << endl
                    << "Тангенс: " << 0 << endl
                    << "Котангенс: " << "inf" << endl;
                break;
            }
            radian = convertation(radian);
            function_output(radian);
            break;
        }
    }
}
long double convertation(long double grad)
{
    long double radian;
    radian = (grad * M_PI) / 180.0;
    return radian;
}

void function_output(long double radian)
{
    float radianf;
    double radiand;
    radiand = radian;
    radianf = radiand;
    cout << setprecision(100) << "Синус: " << endl << "f: " << sin(radianf) << endl << "d: " << sin(radiand) << endl << "ld : " << sin(radian) << endl
        << "Косинус: " << endl << "f: " << cos(radianf) << endl << "d: " << cos(radiand) << endl << "ld: " << cos(radian) << endl
        << "Тангенс: " << endl << "f: " << tan(radianf) << endl << "d: " << tan(radiand) << endl << "ld: " << tan(radian) << endl
        << "Котангенс: " << endl << "f: " << 1.0 / tan(radianf) << endl << "d: " << 1.0 / tan(radiand) << endl << "ld: " << 1.0 / tan(radian) << endl;
}
