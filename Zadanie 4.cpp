#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
boost::multiprecision::cpp_int fibonacci(int n, std::unordered_map<int, boost::multiprecision::cpp_int>& memo);
void Fibonacci(int N);
int main()
{
    setlocale(LC_ALL, "Russian");
    int N, Fibonacci_cout, c;
    while (1)
    {
    start:
        cout << "Введите каким способом будем решать\n1-линейным(96 точных чисел),\n2-рекурсивным(абосолютная точность): ";
        cin >> c;
        cout << "Введите количество чисел ряда: ";
        cin >> N;
        if (!cin || N < 0 || c != 1 && c != 2)
        {
            cout << "Неверный формат данных. Повторите еще раз\n";
            cin.clear();
            cin.ignore();
            goto start;
        }
        switch (c) {
        case 1: {
            Fibonacci(N);
            break; }
        case 2: {
            if (N > 1 || N == 0) cout << 0 << " " << 0 << endl;
            if (N > 1 || N == 1) cout << 1 << " " << 1 << endl;
            std::unordered_map<int, boost::multiprecision::cpp_int> memo;
            boost::multiprecision::cpp_int result = fibonacci(N + 2, memo);
            break;
        }
        }
    }
}
void Fibonacci(int N)
{
    vector<long double> vector_1;
    vector<long double> vector_2;
    long double tmp = 0;
    vector_1.push_back(0);
    vector_2.push_back(1);
    cout << 0 << " " << vector_1[0] << endl;
    cout << 1 << " " << vector_2[0] << endl;
    for (int i = 1; i < N; i++)
    {
        tmp = vector_2[0];
        vector_2.clear();
        vector_2.push_back(tmp + vector_1[0]);
        vector_1.clear();
        vector_1.push_back(tmp);
        cout << setprecision(256) << i + 1 << " " << vector_2[0] << endl;
    }
}

boost::multiprecision::cpp_int fibonacci(int n, std::unordered_map<int, boost::multiprecision::cpp_int>& memo)
{
    if (n <= 1)
    {
        return n;
    }
    if (memo.find(n) != memo.end()) {
        cout << n << " " << memo[n] << endl;
        return memo[n];
    }
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}