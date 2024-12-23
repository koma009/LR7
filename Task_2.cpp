#include <iostream>
#include <string>

int main() {
    std::string text, substring;
    char target;

    // Ввод текста
    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    // Ввод символа, после которого нужно вставить подстроку
    std::cout << "Введите символ, после которого нужно вставить подстроку: ";
    std::cin >> target;
    std::cin.ignore(); // Убираем оставшийся символ новой строки

    // Ввод подстроки
    std::cout << "Введите подстроку для вставки: ";
    std::getline(std::cin, substring);

    std::string result = "";

    for (size_t i = 0; i < text.size(); ++i) {
        result += text[i]; // Добавляем текущий символ
        if (text[i] == target) {
            result += substring; // Вставляем подстроку, если найден символ
        }
    }

    // Вывод результата
    std::cout << "Результат: " << result << std::endl;

    return 0;
}