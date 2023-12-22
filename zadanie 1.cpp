#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;
int calculate(int a, int b, char c);                                        //Калькулятор целых значений
long double calculate(long double a, long double b, char c);                //Калькулятор вещественных значений
long double ConvertStringToLongDouble(string str, long double value = 0);   //Конвертация из строки в тип long double(128 бит)
bool is_digits(const std::string& str);                                     //Проверка входных значений

int main()
{
    while (1)
    {
    start:
        setlocale(LC_ALL, "Russian");

        string a, b;
        char c;
        long double sum;

        cout << "Введите выражение вида a + b\nДоступные функции: +,-,/,*\n";
        cin >> a >> c >> b;

        if (is_digits(a) == false)                                                  //Проверка входных значений
        {
            cout << "Неверные входные аргументы, поробуйте еще раз\n";
            goto start;
        }

        long double a1 = ConvertStringToLongDouble(a);                              //Конвертация
        long double b1 = ConvertStringToLongDouble(b);

        if (a.find(".") == std::string::npos && b.find(".") == std::string::npos)   //Проверка целое ли число
        {
            sum = calculate(int(a1), int(b1), c);
        }
        else sum = calculate(a1, b1, c);

        cout << sum << endl << "Нажмите любую клавишу, чтобы продолжить, ESC для выхода из программы\n";

        c = _getch();
        if (c == 27) return 0;
    }
}

bool is_digits(const std::string& str)
{
    return (str.find_first_not_of("0123456789.") == std::string::npos && str.find_first_not_of(".") != std::string::npos);
}

long double ConvertStringToLongDouble(string str, long double value)
{
    stringstream ss(str);
    ss >> value;
    return value;
}

long double calculate(long double a, long double b, char c)
{
    switch (c)
    {
    case '+': {return a + b; }
    case '-': {return a - b; }
    case '/': {if (b != 0) return a / b; else cout << "Деление на ноль?! ∞ -"; return 0; }
    case '*': {return a * b; }
    }
    cout << "Ошибка в выражении! -";
    return 0;
}
int calculate(int a, int b, char c)
{
    switch (c)
    {
    case '+': {return a + b; }
    case '-': {return a - b; }
    case '/': {if (b != 0) return a / b; else cout << "Деление на ноль?! ∞ -"; return 0; }
    case '*': {return a * b; }
    }
    cout << "Ошибка в выражении! -";
    return 0;
}
