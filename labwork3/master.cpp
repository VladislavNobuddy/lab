#include <iostream>
#include <windows.h>
#include <algorithm>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

    using namespace std;

	int userNumber{};

	cout << "Введите целое положительное число: ";
	cin >> userNumber;

	if (userNumber < 2) {
        return 0;
	}

	for (int start = 0, end = 10; start <= userNumber; start = end + 1; end += 10) {
        int last = std::min(end, userNumber);
        bool printed = false; // поскольку в интервале от 201 до 210 нет ни одного простого числа, далее также существуют подобные интервалы

        if (
            start == 0
            &&
            userNumber >= 2
            )
        {
            cout << 2;
            printed = true;
        };

        // найдем первое нечетное число, начиная с 3, чтобы проверять только их, ибо четные также делятся на два помимо себя самих и 1
        int firstOdd = max(start, 3); //в первом интервале = 3, в последующих = start 

        for (int x = firstOdd; x <= last; x += 2) { //нечетное + 2 = нечетное. четное число никогда не простое

            bool prime = true; //проверка на то, является ли простым число. если у x есть делитель нацело помимо себя самого и 1
            for (int j = 3; j * j <= x; j += 2) { // проверяем только нечетные делители, поскольку нечетное не может делиться на четное без остатка. j <= x / j: множитель (j) не должен превосходить корень из числа (x), ибо тогда мы повторно получим пары делителей
                if (x % j == 0) { // делится ли число x на j без остатка? (тогда простое)
                    prime = false;
                    break;
                }
            }

            if (prime) {
                if (printed) cout << ' ';
                cout << x;
                printed = true;
            }
        }
        

        if (printed) {
            cout << '\n';
        }
    }

    return 0;
}
