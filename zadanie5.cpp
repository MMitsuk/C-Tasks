#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;
int random();
void print(int number);
uint16_t crc16_ccitt(const vector<uint8_t> data, size_t length) 
{
    const uint16_t polynomial = 0x1021;
    uint16_t crc = 0x1D0F;

    for (size_t i = 0; i < length; ++i) 
    {
        crc ^= static_cast<uint16_t>(data[i]) << 8;

        for (int j = 0; j < 8; ++j) 
        {
            crc = crc & 0x8000 ? (crc << 1) ^ polynomial : crc << 1;
        }
    }

    return crc;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    vector<uint8_t> data;
    int n;

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
            int number = random();
            cout << dec << number << endl;
            print(number);

            {
                while (number != 0) 
                {
                    data.insert(data.begin(), uint8_t(number%256));
                    number/=256;
                }

                size_t length = data.size();

                uint16_t result = crc16_ccitt(data, length);
                cout << endl << "CRC-16/AUG-CCITT для заданного числа: " << result << endl;
                data.clear();
            }
        }
    }
}

int random()
{
    return rand();
}

void print(int number)
{
    cout << hex << number;
}