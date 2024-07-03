#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

// ������� ��� ���������� ������� ����� � ��������� ������� �� ������������ ����� � ������
std::vector<double> readInput() {
    std::vector<double> numbers;
    double num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

// ������� ��� ��������� ������� ��������
void processVector(std::vector<double>& numbers) {
    // ������� ����������� � ������������ �������� �������
    auto minmax = std::minmax_element(numbers.begin(), numbers.end());
    double min = *minmax.first;
    double max = *minmax.second;

    // �������� ������ ������������� ������� �� ������������ ������������ � ������������� ���������
    for (double& num : numbers) {
        if (num < 0) {
            num *= min * max;
        }
    }
}

// ������� ��� ������ ���������� ������� � ����������� �����
void printVector(const std::vector<double>& numbers) {
    for (const auto& num : numbers) {
        std::cout << std::fixed << std::setprecision(2) << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "������� ����� � ��������� �������, ����������� ��������� (��� ���������� ����� ����������� EOF):\n";

    // ��������� ������� ������ � ������
    std::vector<double> numbers = readInput();

    // ������������ ������
    processVector(numbers);

    // ������� ���������
    std::cout << "��������� ���������:\n";
    printVector(numbers);

    return 0;
}
