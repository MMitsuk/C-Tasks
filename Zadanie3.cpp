#include <iostream>

using namespace std;

struct seed_t
{
  unsigned x = 100; // Начальные значения могут быть любыми
  unsigned y = 123;
  unsigned z = 300;
  unsigned w = 768;
};

int srandom();

unsigned XorShift128()
{
  static seed_t s;
  unsigned t = s.x^(s.x<<11);
  s.x = s.y;
  s.y = s.z;
  s.z = s.w;
  s.w = (s.w^(s.w>>19)) ^ (t^(t>>8));
  return s.w%30000;
}

int main()
{
    int n, k;
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    while (1)
    {
        cout << "Введите способ: 1 - случайный 2 - псевдослучайный\n";
    start:
        cin >> k;
        if (!cin || k != 1 && k != 2)
        {
            cout << "Неверный формат данных. Повторите еще раз\n";
            cin.clear();
            cin.ignore();
            goto start;
        }
        cout << "Введите количество чисел: ";
        cin >> n;
        if (!cin || n > 100 || n < 0)
        {
            cout << "Неверный формат данных. Повторите еще раз\n";
            cin.clear();
            cin.ignore();
            goto start;
        }
        if( k == 1){
        for (int i = 0; i < n; i++)
        {
            cout << srandom() << endl;
        }
        }
        else {
            for (int i = 0; i < n; i++)
            {
                cout << XorShift128() << endl;
            }
        }
    }
}
int srandom()
{
    return rand();
}
