#include <iostream>
using namespace std;

struct BankAccount {
    string ownerName;
    string accountNumber;
    double balance = 0;
};

int main() {
    system("chcp 1251 > nul"); // підключення української мови

    BankAccount account;
    int choice;
    double amount;

    cout << "Введіть ім'я власника рахунку: ";
    cin >> account.ownerName;

    cout << "Введіть номер рахунку: ";
    cin >> account.accountNumber;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Поповнити рахунок\n";
        cout << "2. Зняти гроші\n";
        cout << "3. Показати баланс\n";
        cout << "4. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть суму для поповнення: ";
            cin >> amount;
            if (amount > 0) {
                account.balance += amount;
                cout << "Баланс поповнено. Поточний баланс: " << account.balance << endl;
            }
            else {
                cout << "Сума повинна бути позитивною.\n";
            }
            break;

        case 2:
            cout << "Введіть суму для зняття: ";
            cin >> amount;
            if (amount > 0 && amount <= account.balance) {
                account.balance -= amount;
                cout << "Зняття успішне. Поточний баланс: " << account.balance << endl;
            }
            else {
                cout << "Недостатньо коштів або неправильна сума.\n";
            }
            break;

        case 3:
            cout << "Поточний баланс: " << account.balance << endl;
            break;

        case 4:
            cout << "Вихід з програми.\n";
            return 0;

        default:
            cout << "Невірний вибір. Спробуйте знову.\n";
        }
    }

   
}
