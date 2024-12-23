#include <iostream>
#include <string>
#include <algorithm>


int charToValue(char c) {
    if (isdigit(c)) return c - '0';
    return toupper(c) - 'A' + 10;
}


char valueToChar(int value) {
    if (value < 10) return value + '0';
    return value - 10 + 'A';
}


std::string addNumbers(const std::string& num1, const std::string& num2, int base) {
    std::string result = "";
    int carry = 0;

    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? charToValue(num1[i--]) : 0;
        int digit2 = (j >= 0) ? charToValue(num2[j--]) : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / base;
        result += valueToChar(sum % base);
    }

    std::reverse(result.begin(), result.end());
    return result;
}

// Вычитание двух чисел в заданной системе счисления
std::string subtractNumbers(const std::string& num1, const std::string& num2, int base) {
    std::string result = "";
    int borrow = 0;

    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? charToValue(num1[i--]) : 0;
        int digit2 = (j >= 0) ? charToValue(num2[j--]) : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += valueToChar(diff);
    }

    // Удаление ведущих нулей
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int base;
    std::string num1, num2;

    std::cout << "Введите основание системы счисления (2-36): ";
    std::cin >> base;

    if (base < 2 || base > 36) {
        std::cout << "Недопустимое основание!" << std::endl;
        return 1;
    }

    std::cout << "Введите первое число: ";
    std::cin >> num1;

    std::cout << "Введите второе число: ";
    std::cin >> num2;

    std::string sum = addNumbers(num1, num2, base);
    std::string difference = subtractNumbers(num1, num2, base);

    std::cout << "Сумма: " << sum << std::endl;
    std::cout << "Разность: " << difference << std::endl;

    return 0;
}