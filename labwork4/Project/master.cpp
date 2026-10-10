#include <iostream>
#include <windows.h>
#include <algorithm>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int userInput[15];

    std::cout << "Введите 15 целых чисел:" << std::endl;
    for (int i{ 0 }; i < 15; i++) {
        std::cin >> userInput[i];
        std::cout << std::endl;
    };

    std::cout << "а)" << std::endl;
    for (int start{ 0 }; start < 15; start += 5) {
        int minim{ userInput[start] };
        for (int i{ start }; i < start + 5; i++) {
            minim = (std::min)(minim, userInput[i]);
        }
        std::cout << minim << " ";
    }

    std::cout << std::endl;

    std::cout << "б)" << std::endl;

    std::sort(userInput, userInput + 15);

    for (int i{ 0 }; i < 15; i++) {
        std::cout << userInput[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "в)" << std::endl;

    int duplicateCount = 0;
    for (int i = 0; i < 15; i++) {
        int count = 1;
        while (i < 14 && userInput[i] == userInput[i + 1]) { //массив уже отсортирован
            count++;
            i++;
        }
        if (count > 1) {
            duplicateCount++;
        }
    }
    std::cout << duplicateCount << std::endl;

    std::cout << "г)" << std::endl;
    int startIndex = -1;
    int maxLen = 0;
    for (int i = 0; i < 15; i++) {
        if (userInput[i] == 1) {
            int currentLen = 1;
            int expected = 2;
            int j = i + 1;
            while (j < 15 && userInput[j] == expected) {
                currentLen++;
                expected *= 2;
                j++;
            }
            if (currentLen > maxLen) {
                maxLen = currentLen;
                startIndex = i;
            }
        }
    }
    if (startIndex != -1) {
        std::cout << startIndex + 1 << std::endl;
    }
    else {
        std::cout << "Последовательность не найдена" << std::endl;
    }

    return 0;
}