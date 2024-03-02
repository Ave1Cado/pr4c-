#include <iostream>
#include <string>
#include <algorithm>
#include <random>

// Функция для переворачивания строки задом наперед
std::string reverse(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Функция для удаления гласных букв из строки
std::string removeVowels(const std::string& str) {
    std::string result;
    for (char ch : str) {
        if (tolower(ch) != 'a' && tolower(ch) != 'e' && tolower(ch) != 'i' && tolower(ch) != 'o' && tolower(ch) != 'u') {
            result += ch;
        }
    }
    return result;
}

// Функция для удаления согласных букв из строки
std::string removeConsonants(const std::string& str) {
    std::string result;
    for (char ch : str) {
        if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') {
            result += ch;
        }
    }
    return result;
}

// Функция для перемешивания букв в строке
std::string shuffle(const std::string& str) {
    std::string shuffled = str;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffled.begin(), shuffled.end(), g);
    return shuffled;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    int choice;
    std::cout << "Выберите действие:\n";
    std::cout << "1. Слово выводится задом наперед.\n";
    std::cout << "2. Вывести слово без гласных.\n";
    std::cout << "3. Вывести слово без согласных.\n";
    std::cout << "4. Рандомно раскидывать буквы заданного слова.\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Результат: " << reverse(word) << std::endl;
        break;
    case 2:
        std::cout << "Результат: " << removeVowels(word) << std::endl;
        break;
    case 3:
        std::cout << "Результат: " << removeConsonants(word) << std::endl;
        break;
    case 4:
        std::cout << "Результат: " << shuffle(word) << std::endl;
        break;
    default:
        std::cout << "Неверный выбор.\n";
        break;
    }

    return 0;
}
