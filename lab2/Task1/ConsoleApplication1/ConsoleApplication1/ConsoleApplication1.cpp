#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

// Функция для считывания массива чисел с плавающей запятой из стандартного ввода в вектор
std::vector<double> readInput() {
    std::vector<double> numbers;
    double num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

// Функция для обработки вектора значений
void processVector(std::vector<double>& numbers) {
    // Находим минимальный и максимальный элементы вектора
    auto minmax = std::minmax_element(numbers.begin(), numbers.end());
    double min = *minmax.first;
    double max = *minmax.second;

    // Умножаем каждый отрицательный элемент на произведение минимального и максимального элементов
    for (double& num : numbers) {
        if (num < 0) {
            num *= min * max;
        }
    }
}

// Функция для вывода результата вектора в стандартный вывод
void printVector(const std::vector<double>& numbers) {
    for (const auto& num : numbers) {
        std::cout << std::fixed << std::setprecision(2) << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Введите числа с плавающей запятой, разделяемые пробелами (для завершения ввода используйте EOF):\n";

    // Считываем входные данные в вектор
    std::vector<double> numbers = readInput();

    // Обрабатываем вектор
    processVector(numbers);

    // Выводим результат
    std::cout << "Результат обработки:\n";
    printVector(numbers);

    return 0;
}
