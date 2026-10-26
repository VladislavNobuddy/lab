#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int first[5];
    int second[5];

    std::cout << "Введите 5 целых чисел для первого массива : " << std::endl;
    for (short i = 0; i < 5; i++) {
        std::cin >> first[i];
    }

    std::cout << "Введите 5 целых чисел для второго массива : " << std::endl;
    for (short i = 0; i < 5; i++) {
        std::cin >> second[i];
    }
    // В первом массиве будут положительные, а во втором - отрицательные
    //Обрабатываем числа из первого массива для замены 
    for (short i = 0; i < 5; i++) {
        //Ищем отрицательные в первом для замены на положительное из второго
        if (first[i] < 0) {
            bool swapped = false;

            // Ищем положительное число во втором массиве для обмена
            for (short j = 0; j < 5; j++) {
                if (second[j] > 0) {
                    int temp = first[i];

                    first[i] = second[j];
                    second[j] = temp;

                    swapped = true;
                    break;
                }
            }

            // Если нет положительных, то ищем ноль с последующей заменой
            if (!swapped) {
                for (short j = 0; j < 5; j++) {
                    if (second[j] == 0) {
                        second[j] = first[i]; 
                        first[i] = 0;         
                        swapped = true;
                        break;
                    }
                }
            }

            // Если же мы не нашли ни положительного числа, ни нуля, то, 
            // получается, что во втором массиве только отрицательные, тогда удаляем отрицательные из первого (меняем на 0), ибо дальше заполнять некуда
            if (!swapped) {
                first[i] = 0;
            }
        }
    }

    // Обрабатываем числа из второго массива для замены, ведь в нем могли остаться положительные числа
    for (short j = 0; j < 5; j++) {
        // Ищем положительные числа, чтобы перенести в первый массив
        if (second[j] > 0) {
            bool swapped = false;

            // Ищем ноль, так как можем заменить только на него, ибо в предыдущем блоке в первом массиве остались только нули и положительные числа
            for (short i = 0; i < 5; i++) {
                if (first[i] == 0) {
                    first[i] = second[j];
                    second[j] = 0;
                    swapped = true;
                    break;
                }
            }

            // Если ноль не нашли, то первый массив состоит из положительных, тогда заменяем положительное число во втором массиве на 0
            if (!swapped) {
                second[j] = 0;
            }
        }
    }

    std::cout << std::endl;

    std::cout << "1 массив:" << std::endl;
    for (short i = 0; i < 5; i++) {
        std::cout << first[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "2 массив:" << std::endl;
    for (short i = 0; i < 5; i++) {
        std::cout << second[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}