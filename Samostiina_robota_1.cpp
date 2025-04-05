#include <iostream>
using namespace std;

// Структура для збереження інформації про студента
struct Student {
    string name;
    int age;
    double average_grade;
};

int main() {
    
    system("chcp 1251 > nul"); //підключення української мови
    
    int count;
    cout << "Введіть кількість студентів: ";
    cin >> count;

    // Динамічне виділення пам'яті для масиву студентів
    Student* students = new Student[count];

    // Введення даних студентів
    for (int i = 0; i < count; ++i) {
        cout << "\nСтудент #" << i + 1 << ":\n";
        cout << "Ім'я: ";
        cin >> students[i].name;
        cout << "Вік: ";
        cin >> students[i].age;
        cout << "Середній бал: ";
        cin >> students[i].average_grade;
    }

    // Виведення інформації про студентів
    cout << "\nІнформація про студентів:\n";
    for (int i = 0; i < count; ++i) {
        cout << "Студент #" << i + 1 << ": ";
        cout << "Ім'я: " << students[i].name
            << ", Вік: " << students[i].age
            << ", Середній бал: " << students[i].average_grade << endl;
    }

    // Звільнення пам'яті
    delete[] students;


}
