#include <iostream>

using namespace std;

struct Book {
    char title[100];
    char author[100];
    int year;
};

int main() {

    system("chcp 1251 > nul"); //підключення української мови

    Book library[100];
    int count = 0, choice;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Додати книгу\n";
        cout << "2. Пошук книги за автором\n";
        cout << "3. Пошук книги за роком видання\n";
        cout << "4. Показати всі книги\n";
        cout << "5. Вихід\n";
        cout << "Виберіть опцію: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Введіть назву книги: ";
            cin >> library[count].title;
            cout << "Введіть автора книги: ";
            cin >> library[count].author;
            cout << "Введіть рік видання книги: ";
            cin >> library[count].year;
            count++;
        }
        else if (choice == 2) {
            char author[100];
            cout << "Введіть автора для пошуку: ";
            cin >> author;
            bool found = false;
            for (int i = 0; i < count; i++) {
                bool match = true;
                for (int j = 0; library[i].author[j] != '\0' || author[j] != '\0'; j++) {
                    if (library[i].author[j] != author[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    cout << "Знайдена книга: " << library[i].title << ", рік видання: " << library[i].year << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "Книги цього автора не знайдено.\n";
            }
        }
        else if (choice == 3) {
            int year;
            cout << "Введіть рік видання для пошуку: ";
            cin >> year;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (library[i].year == year) {
                    cout << "Знайдена книга: " << library[i].title << " автора: " << library[i].author << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "Книги цього року видання не знайдено.\n";
            }
        }
        else if (choice == 4) {
            for (int i = 0; i < count; i++) {
                cout << "Назва: " << library[i].title << ", Автор: " << library[i].author << ", Рік видання: " << library[i].year << endl;
            }
        }
        else if (choice == 5) {
            cout << "До побачення!\n";
            break;
        }
        else {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }


}
