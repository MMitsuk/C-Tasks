#include <iostream>
using namespace std;

int random();

int main()
{
    int n;
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    while (1)
    {
        cout << "Введите количество чисел: ";
    start:
        cin >> n;
        if (!cin || n > 100 || n < 0)
        {
            cout << "Неверный формат данных. Повторите еще раз\n";
            cin.clear();
            cin.ignore();
            goto start;
        }
        for (int i = 0; i < n; i++)
        {
            cout << random() << endl;
        }
    }
}

int random()
{
    return rand();
}
