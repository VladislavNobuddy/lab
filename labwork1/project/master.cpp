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
			
			i++;
		};

		if (
			userCords[0] == 0 
			&&
			userCords[1] == 0
			)
		{break;}
		else {
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
					)
				{
					cout << goodAnswer << endl;
				}
				else if (
					userCords[1] > yCord
					) {
					cout << badAnswer << endl;
				};
			}
		}

	};

	return 0;
}