// ConsoleApplication17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <iomanip>
#define M_PI 3.14159265358979323846;
using namespace std;

void function_output(float radian);
void function_output(double radian);
void function_output(long double radian);
long double convertation(long double radian);

int main()
{
    setlocale(LC_ALL, "Russian");
    float radianf;
    double radiand;
    long double radian;
    int i;
    while (1)
    {
        cout << "В каких значениях вы хотите ввести значение?\n1 - Радиан\n2 - Градусы\n";
        cin >> i;
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
            radian = convertation(radian);
            radiand = radian;
            radianf = radiand;
            function_output(radianf);
            function_output(radiand);
            function_output(radian);
            break;
        }
    }
}
long double convertation(long double grad)
{
    long double radian;
    radian = grad * 0.00555555555 * M_PI;
    return radian;
}
void function_output(float radian)
{
    cout << setprecision(7) << "Синус: " << sin(radian) << endl 
        << "Косинус: " << cos(radian) << endl 
        <<  "Тангенс: " << tan(radian) << endl 
        << "Котангенс: " << 1.0 / tan(radian) << endl << endl;
}
void function_output(double radian)
{
    cout << setprecision(26) << "Синус: " << sin(radian) << endl
        << "Косинус: " << cos(radian) << endl
        << "Тангенс: " << tan(radian) << endl
        << "Котангенс: " << 1.0 / tan(radian) << endl << endl;
}
void function_output(long double radian) 
{
    cout << setprecision(35) << "Синус: " << sin(radian) << endl
        << "Косинус: " << cos(radian) << endl
        << "Тангенс: " << tan(radian) << endl
        << "Котангенс: " << 1.0 / tan(radian) << endl << endl;
}