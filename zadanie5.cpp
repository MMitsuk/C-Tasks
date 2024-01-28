#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;
int srandom();
void print(int number);
uint16_t crc16_ccitt(vector<uint8_t> data, size_t length, uint16_t crc = 0x1D0F) 
{
    const uint16_t polynomial = 0x1021;
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
    vector<int> number;
    int n, k;

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
        cout << endl << "DEC: " << endl;
        for (int i = 0; i < n; i++)
        {
            number.push_back(srandom());
            cout << dec << number[i] << endl;
        }
        cout << endl << "HEX: " << endl;
        for (int i = 0; i < n; i++)
        {
            print(number[i]);
        }
        for (int i = number.size(); i > 0; i--)
        {
            while (number[i-1] != 0)
            {
                data.insert(data.begin(),uint8_t(number[i-1]%256));
                number[i-1]/=256;
            }
        }
                size_t length = data.size();

                uint16_t result = crc16_ccitt(data, length);
                cout << endl << "CRC-16/AUG-CCITT для заданного массива чисел: " << result << endl;
                data.clear();
                number.clear();
    }
}

int srandom()
{
    return rand()%32000;
}

void print(int number)
{
    if(number/256 < 16){cout << hex << "0" << number << endl;}
    else cout << hex << number << endl;
}
