#include <iostream>

using namespace std;

struct Product {
    char name[50];  // Назва товару
    float price;    // Ціна товару
    int quantity;   // Кількість товару на складі
};

int main() {

    system("chcp 1251 > nul"); //підключення української мови

    Product products[10];  // Масив для 10 товарів
    int count = 0;         // Лічильник для кількості товарів
    int choice;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Додати товар\n";
        cout << "2. Оновити кількість товару\n";
        cout << "3. Показати всі товари\n";
        cout << "4. Вийти\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Введіть назву товару: ";
            cin >> products[count].name;
            cout << "Введіть ціну товару: ";
            cin >> products[count].price;
            cout << "Введіть кількість товару: ";
            cin >> products[count].quantity;
            count++;
        }
        else if (choice == 2) {
            char name[50];
            cout << "Введіть назву товару: ";
            cin >> name;

            bool found = false;
            for (int i = 0; i < count; i++) {
                // Порівнюємо рядки по символах
                for (int j = 0; products[i].name[j] != '\0' || name[j] != '\0'; j++) {
                    if (products[i].name[j] != name[j]) {
                        found = false;
                        break;
                    }
                    else {
                        found = true;
                    }
                }

                if (found) {
                    int quantity;
                    cout << "Введіть нову кількість товару: ";
                    cin >> quantity;
                    products[i].quantity = quantity;
                    break;
                }
            }

            if (!found) {
                cout << "Товар не знайдено.\n";
            }
        }
        else if (choice == 3) {
            for (int i = 0; i < count; i++) {
                cout << "Товар: " << products[i].name
                    << ", Ціна: " << products[i].price
                    << ", Кількість: " << products[i].quantity << endl;
            }
        }
        else if (choice == 4) {
            cout << "Вихід з програми.\n";
            break;
        }
    }

    return 0;
}
