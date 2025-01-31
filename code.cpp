#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;
void SetConsoleWindowSize(int width, int height) { // Код взят с интернета для увеличения окна
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
int main() {
    srand(time(0));
    SetConsoleWindowSize(1200, 1000);
    setlocale(LC_ALL, "");
    system("cls");
    int balance = 200;
    while (true) {
        cout << "Добро пожаловать в казино" << endl;
        cout << "1 - Начать играть" << endl;
        cout << "2 - Баланс" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выбор функции: ";
        int option;
        cin >> option;
        if (option == 0) {
            system("cls");
            cout << "Хорошего дня";
            break;
        }
        else if(option == 2) {
            system("cls");
            int act;
            while (true) {
                cout << "1 - Посмотреть баланс" << endl;
                cout << "0 - Выйти" << endl;
                cout << "Выберите функцию: ";
                cin >> act;
                if (act == 0) {
                    system("cls");
                    break;
                }
                else if (act == 1) {
                    system("cls");
                    cout << "Баланс игрока: " << balance << endl;
                }
                else {
                    system("cls");
                    cout << "Неизвестная команда" << endl;
                }
            }
        }
        else if (option == 1) {
            system("cls");
            while (true) {
                cout << "1 - Кубик Больше меньше" << endl;
                cout << "2 - Монетка" << endl;
                cout << "3 - Рулетка" << endl;
                cout << "0 - Назад" << endl;
                cout << "Выбор функции: ";
                cin >> option;
                if (option == 0) {
                    system("cls");
                    break;
                }
                else if (option == 2) {
                    system("cls");
                    while (true) {
                        int a = rand() % 2 + 1;
                        int choose;
                        cout << "Игра в монетку" << endl;
                        cout << "Выбор стороны" << endl;
                        cout << "1 - Орел" << endl;
                        cout << "2 - Решка" << endl;
                        cout << "0 - Назад" << endl;
                        cout << "Выбор стороны: ";
                        cin >> choose;
                        if (a == 1 && choose == 1) {
                            system("cls");
                            cout << "Вы выиграли +50" << endl;
                            balance += 50;
                        }
                        else if (a == 2 && choose == 2) {
                            system("cls");
                            cout << "Вы выиграли +50" << endl;
                            balance += 50;
                        }
                        else if (a == 1 && choose == 2) {
                            system("cls");
                            cout << "Вы проиграли -50" << endl;
                            balance -= 50;
                        }
                        else if (a == 2 && choose == 1) {
                            system("cls");
                            cout << "Вы проиграли -50" << endl;
                            balance -= 50;
                        }
                        else if (choose == 0) {
                            system("cls");
                            break;
                        }
                    }
                }
                else if (option == 3) {
                    system("cls");
                    while (true) {
                        int bet, color;
                        cout << "Введите ставку (число от 1 до 36): " << endl;
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
                            system("cls");
                            cout << "Некорректный выбор! Попробуйте снова." << endl;
                            continue;
                        }
                        int result = rand() % 36 + 1; // Генерируем число от 1 до 36
                        int resultColor = (result % 2 == 0) ? 2 : 1; // Четные - черные (2), нечетные - красные (1)
                        cout << "Выпало число: " << result;
                        if (resultColor == 1) {
                            cout << " (Красный)" << endl;
                        }
                        else {
                            cout << " (Чёрный)" << endl;
                        }
                        if (bet == result && color == resultColor) {
                            system("cls");
                            cout << "Поздравляем! Вы угадали число и цвет!" << endl;
                        }
                        else if (color == resultColor) {
                            system("cls");
                            cout << "Вы угадали цвет!" << endl;
                        }
                        else {
                            system("cls");
                            cout << "Вы проиграли." << endl;
                        }
                        char again;
                        cout << "Хотите сыграть снова?: " << endl;
                        cout << "y - да" << endl;
                        cout << "n - нет" << endl;
                        cin >> again;
                        if (again != 'y') {
                            system("cls");
                            break;
                        }
                    }
                }
                else {
                    system("cls");
                    cout << "Неизвестная команда" << endl;
                }
            }
        }
        else {
            system("cls");
            cout << "Неизвестная команда" << endl;
        }
    }
    return 0;
}
