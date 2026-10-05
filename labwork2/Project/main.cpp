#include <iostream>
#include <windows.h>
#include <cmath>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    using namespace std;

    while (true)
    {
        int temp;
        int count = 0;
        double sum = 0;
        int minElement = 0;
        int maxElement = 0;
        int c_answer = 0;
        int d_answer = 0;
        int e_answer = 0;
        int prev1 = 0;
        int prev2 = 0;

        cout << "Введите числовой массив:" << endl;

        while (cin >> temp)
        {
            if (temp == 0)
            {
                break;
            }

            if (count == 0)
            {
                minElement = temp;
                maxElement = temp;
                prev1 = temp;
            }
            else
            {
                if (temp < minElement)
                {
                    minElement = temp;
                }
                if (temp > maxElement)
                {
                    maxElement = temp;
                }

                if (count == 1)
                {
                    prev2 = prev1;
                    prev1 = temp;
                }
                else
                {
                    if (prev2 + prev1 < temp)
                    {
                        e_answer++;
                    }
                    prev2 = prev1;
                    prev1 = temp;
                }
            }

            sum += temp;
            count++;

            if (temp % 5 == 0 && temp > 0)
            {
                c_answer++;
            }

            if (temp > 0)
            {
                for (int k = 0; k < 100; k++)
                {
                    if (temp == pow(2, k))
                    {
                        d_answer++;
                        break;
                    }
                }
            }
        }

        if (count != 0)
        {
            double a_answer = sum / count;
            int b_answer = maxElement - minElement;

            cout << "a) " << a_answer << endl;
            cout << "b) " << b_answer << endl;
            cout << "c) " << c_answer << endl;
            cout << "d) " << d_answer << endl;
            cout << "e) " << e_answer << endl;
        }
    }
}