#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


int passwordLength;

string generatePassword(int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+=<>?";
    const int charsetSize = sizeof(charset) - 1;

    srand(static_cast<unsigned int>(time(0)));

    std::string password;
    for (int i = 0; i < length; ++i) {
        password += charset[rand() % charsetSize];
    }

    return password;
}

void getPassLength() {
    cout << "Введите длину пароля: ";
    cin >> passwordLength;

    if (passwordLength <= 0) {
        cout << "Ошибка: Длина пароля должна быть положительным числом.\n";
        getPassLength();
    }
    else if (passwordLength > 0 && passwordLength < 8) {
        cout << "Ошибка: Введите длину пароля не менее 8 символов\n";
        getPassLength();
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    getPassLength();

    string generatedPassword = generatePassword(passwordLength);

    cout << "Сгенерированный пароль: " << generatedPassword << std::endl;

    return 0;
}
