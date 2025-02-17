#include <iostream> // ввод вывод 
#include <locale.h> // установка языков
#include <cstdlib> // используется для разных функций и так же rand
#include <windows.h> // для работы с windows API
#include <ctime> // для работы со временем
#include <fstream> // для работы с файлами 
#include <string> // для работы с строками
using namespace std;

// Функция для изменения размера консольного окна ВЗЯТА С ИНТЕРНЕТА!
void SetConsoleWindowSize(int width, int height) {
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) {
        RECT rect;
        GetWindowRect(hwnd, &rect);

        int newWidth = width;
        int newHeight = height;
        MoveWindow(hwnd, 0, 0, newWidth, newHeight, TRUE);

        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
        GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

        int newFontSizeX = (newWidth / 20);
        int newFontSizeY = (newHeight / 35);
        cfi.dwFontSize.X = newFontSizeX;
        cfi.dwFontSize.Y = newFontSizeY;

        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    }
}

// Функция для обновления баланса через указатель
void updateBalance(int* balance, int amount) {
    *balance += amount;
}

// Функция для сохранения истории игры в файл
void saveGameHistory(const string& filename, const string& history) {
    ofstream file(filename, ios::app); // выписывает , Открываем файл в режиме добавления так же не удаляет прошлые данные
    if (file.is_open()) {
        file << history << endl;
        file.close();
    }
    else {
        cout << "Ошибка при открытии файла!" << endl;
    }
}

// Функция для загрузки истории игр из файла
void loadGameHistory(const string& filename) { // указывает на ссылку filename
    ifstream file(filename);
    if (file.is_open()) {
        string line; 
        while (getline(file, line)) { // выполняется цикл для чтения
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Ошибка при открытии файла!" << endl;
    }
}

int main() {
    srand(time(0)); // random
    SetConsoleWindowSize(1200, 1000);
    setlocale(LC_ALL, "rus");
    system("cls");

    int balance = 200; // Баланс игрока
    const string HISTORY_FILE = "game_history.txt"; // Имя файла для истории игр

    while (true) {
        cout << "Добро пожаловать в казино Vishnya-Mania" << endl;
        cout << "1 - Начать играть" << endl;
        cout << "2 - Баланс" << endl;
        cout << "3 - История игр" << endl;
        cout << "0 - Выход" << endl;
        cout << "                                                             " << endl;
        cout << "                                                             " << endl;
        cout << "                                                             " << endl;
        cout << "                                                             " << endl;
        cout << "                           ███                               " << endl;
        cout << "                            ███                              " << endl;
        cout << "                      █████ ████                             " << endl;
        cout << "                  █████ ██  ██ ██                            " << endl;
        cout << "                █████  ███  █   ██                           " << endl;
        cout << "               █████  ████ ██    ██                          " << endl;
        cout << "              █████  ████  █      ██                         " << endl;
        cout << "             ████  █████  █        █                         " << endl;
        cout << "             ███  █████  ██         █                        " << endl;
        cout << "             ████████   ██          ██                       " << endl;
        cout << "             ██████     █            █                       " << endl;
        cout << "            ████       ██            ██                      " << endl;
        cout << "                      ██              █                      " << endl;
        cout << "             █████████████        ███████████                " << endl;
        cout << "           ██  ███████ █████   █████████████████            " << endl;
        cout << "          █ ████  ███████████  █  ██ █  ███  █  █           " << endl;
        cout << "         █ ███    ██        ███████      ██ ██   █          " << endl;
        cout << "         █ ████████████████ ███████████████████  █          " << endl;
        cout << "          █████████████████ ███████████████████  █          " << endl;
        cout << "          ██████ ██████████ █ █████    ████████ █           " << endl;
        cout << "           █████ ███████████   ██████  █████████            " << endl;
        cout << "             ██████████████     ███████████████             " << endl;
        cout << "                ██████              ███████                 " << endl;
        cout << "                                                             " << endl;
        cout << "                                                             " << endl;
        cout << "                                                             " << endl;
        cout << "                                                             " << endl;
        cout << "Выбор функции: ";
        int option;
        cin >> option;

        switch (option) {
        case 0: // Выход
            system("cls");
            cout << "Хорошего дня!" << endl;
            return 0;

        case 1: { // Начать играть
            system("cls");
            while (true) {
                cout << "1 - Монетка" << endl;
                cout << "2 - Рулетка" << endl;
                cout << "0 - Назад" << endl;
                cout << "Выбор функции: ";
                cin >> option;

                if (option == 0) {
                    system("cls");
                    break;
                }

                switch (option) {
                case 1: { // Монетка
                    system("cls");
                    char playAgain;
                    do {
                        int a = rand() % 2 + 1;
                        int choose;
                        cout << "Игра в монетку" << endl;
                        cout << "Выбор стороны:" << endl;
                        cout << "1 - Орел" << endl;
                        cout << "2 - Решка" << endl;
                        cout << "0 - Назад" << endl;
                        cout << "Выбор стороны: ";
                        cin >> choose;

                        if (choose == 0) {
                            system("cls");
                            break;
                        }

                        bool win = (a == choose);
                        updateBalance(&balance, win ? 50 : -50); // тернарный оператор 
                        cout << (win ? "Вы выиграли +50" : "Вы проиграли -50") << endl;
                        saveGameHistory(HISTORY_FILE, win ? "Монетка: Выигрыш" : "Монетка: Проигрыш");

                        cout << "Хотите сыграть снова? (y/n): ";
                        cin >> playAgain;
                    } while (playAgain == 'y');
                    break;
                }

                case 2: { // Рулетка
                    system("cls");
                    char playAgain; // указывает на переменную
                    do {
                        int bet, color;
                        cout << "Введите ставку (число от 1 до 36): ";
                        cin >> bet;
                        if (bet < 1 || bet > 36) {
                            cout << "Некорректное число! Попробуйте снова." << endl;
                            continue;
                        }

                        cout << "Выберите цвет:" << endl;
                        cout << "1 - Красный" << endl;
                        cout << "2 - Чёрный" << endl;
                        cin >> color;
                        if (color != 1 && color != 2) {
                            cout << "Некорректный выбор! Попробуйте снова." << endl;
                            continue;
                        }

                        auto result = rand() % 36 + 1; // Генерируем число от 1 до 36
                        auto resultColor = (result % 2 == 0) ? 2 : 1; // Четные - черные (2), нечетные - красные (1)
                        cout << "Выпало число: " << result;
                        cout << (resultColor == 1 ? " (Красный)" : " (Чёрный)") << endl;

                        bool winNumber = (bet == result); // правда ложь
                        bool winColor = (color == resultColor);
                        if (winNumber && winColor) {
                            updateBalance(&balance, 100); //  амперант
                            cout << "Поздравляем! Вы угадали число и цвет!" << endl;
                            saveGameHistory(HISTORY_FILE, "Рулетка: Угадано число и цвет");
                        }
                        else if (winColor) {
                            updateBalance(&balance, 50);
                            cout << "Вы угадали цвет!" << endl;
                            saveGameHistory(HISTORY_FILE, "Рулетка: Угадан цвет");
                        }
                        else {
                            updateBalance(&balance, -50);
                            cout << "Вы проиграли." << endl;
                            saveGameHistory(HISTORY_FILE, "Рулетка: Проигрыш");
                        }

                        cout << "Хотите сыграть снова? (y/n): ";
                        cin >> playAgain;
                    } while (playAgain == 'y');
                    break;
                }

                default:
                    cout << "Неизвестная команда" << endl;
                }
            }
            break;
        }

        case 2: { // Баланс
            system("cls");
            cout << "Баланс игрока: " << balance << endl;
            break;
        }

        case 3: { // История игр
            system("cls");
            cout << "История игр:" << endl;
            loadGameHistory(HISTORY_FILE);
            break;
        }

        default:
            cout << "Неизвестная команда" << endl;
        }
    }

    return 0;
}