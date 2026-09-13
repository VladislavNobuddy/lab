#include <iostream>
#include <windows.h>
#include <limits>  // Чтобы пользователь не ввел слишком большое значение. Компилятор уходил в разнос после этого

int function(short x) {
	int y = x;

	return y;
};

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	using namespace std;
	
	short userCords[2];

	string goodAnswer{"Точка попала в треугольник, по крайней мере, на его границу"};
	string badAnswer{ "Точка не попала в треугольник" };

	cout << "Задать x координату катета, параллельного оси ординат? Введите числовое значение или N, если хотите оставить координату → ∞" << endl;
	
	short border{};

	cin >> border;

	if (cin.fail()) {
		cout << "Считаем, что длина катетов треугольника → ∞, а также что координаты принадлежат множеству натуральных чисел" << endl;

		cin.clear();

		cin.ignore((std::numeric_limits<streamsize>::max)(), '\n'); //Очищает буфер ввода. как это работает по отдельности я х знает и знать не хочу
	}

	else {
		cout << "Считаем, что катет треугольника, лежит на координате x = " << border << ", а также что координаты принадлежат множеству натуральных чисел" << endl;

		cin.ignore((std::numeric_limits<streamsize>::max)(), '\n'); //Очищаем буфер, если с прошлого ввода осталась отброшенная дробная часть
	};

	while (true) {
		cout << "Введите координаты для проверки в формате x, y: " << endl;

		unsigned short i{};
		while (i < size(userCords)) {
			if (i == 0) {
				cout << "x: ";
			}
			else {
				cout << "y: ";
			};
			cin >> userCords[i];
			
			if (cin.fail()) {
				cout << "Было введено значение, превышающее допустимое для переменной или же не соответствующее. Зачем?" << endl;

				cin.clear();

				cin.ignore((std::numeric_limits<streamsize>::max)(), '\n'); //Очищает буфер ввода. как это работает по отдельности я х знает и знать не хочу
			}

			else {
				cin.ignore((std::numeric_limits<streamsize>::max)(), '\n'); //Очищаем буфер, если с прошлого ввода осталась отброшенная дробная часть

				i++;
			};
		};

		if (
			userCords[1] < 0 
			||
			userCords[0] < 0
			) {
			cout << badAnswer << endl;
		}

		else {
			short yCord = function(userCords[0]);

			if (
				userCords[1] <= yCord
				&&
				userCords[1] >= 0
				&&
				(border == 0 ? true : userCords[0] <= border)
				)
			{
				cout << goodAnswer << endl;
			}
			else if (
				userCords[1] > yCord
				||
				userCords[0] > border
				) {
				cout << badAnswer << endl;
			};
		}
	};

	return 0;
}