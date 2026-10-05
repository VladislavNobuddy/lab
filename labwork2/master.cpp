#include <iostream>
#include <windows.h>
#include <vector>
#include <cmath> //для функции pow()

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	using namespace std;

	vector<int> array;
	vector<double> secondPowerArray;

	int temp;

	for (short i{ 0 }; i < 100; i++) {
		secondPowerArray.push_back(pow(2, i));
	}

	while (true)
	{
		int temp;
		std::cout << "Введите числовой массив:" << endl;
		while (cin >> temp) {
			if (temp == 0) {
				break;
			}
			else {
				array.push_back(temp);
			};

		}

		double elementsAmount = array.size();

		if (elementsAmount != 0) {
			double elementsSum{ 0 };

			for (short i{ 0 }; i < elementsAmount; i++) {
				elementsSum += array[i];
			};

			double a_answer = (elementsSum) / (elementsAmount);

			int minElement = array[0];
			int maxElement = array[0];

			for (int i{ 1 }; i < elementsAmount; ++i) {
				if (array[i] < minElement) {
					minElement = array[i];
				}
				if (array[i] > maxElement) {
					maxElement = array[i];
				}
			}

			int b_answer = maxElement - minElement;

			int c_answer{ 0 };
			for (int i{ 0 }; i < elementsAmount; i++) {
				if ((array[i] % 5 == 0) && (array[i] > 0)) {
					c_answer++;
				};
			};

			int d_answer{ 0 };

			for (int i{ 0 }; i < elementsAmount; i++) {
				for (int j{ 0 }; j < secondPowerArray.size(); j++) {
					if ((array[i] == secondPowerArray[j]) && (array[i] > 0)) {
						d_answer++;
					};
				};
			};


			int e_answer{ 0 };

			for (int i{ 2 }; i < elementsAmount; i++) {
				if ((array[i - 2] + array[i - 1]) < array[i]) {
					e_answer++;
				};
			};

			std::cout << "a) " << a_answer << endl;
			std::cout << "b) " << b_answer << endl;
			std::cout << "c) " << c_answer << endl;
			std::cout << "d) " << d_answer << endl;
			std::cout << "e) " << e_answer << endl;
		}

		array.clear();
	}
}