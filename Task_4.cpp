#include <iostream>


bool isDivisibleBy3(int num) {
    if (num < 0) num = -num; 

    int oddSum = 0, evenSum = 0;
    int position = 0;

    while (num > 0) {
        if (position % 2 == 0) {
            evenSum += num & 1; 
        } else {
            oddSum += num & 1; 
        }
        num >>= 1; 
        position++;
    }

    int diff = oddSum - evenSum;
    return (diff % 3 == 0); 
}

int main() {
    int num;
    std::cout << "Введите число: ";
    std::cin >> num;

    if (isDivisibleBy3(num)) {
        std::cout << "Число делится на 3." << std::endl;
    } else {
        std::cout << "Число не делится на 3." << std::endl;
    }

    return 0;
}