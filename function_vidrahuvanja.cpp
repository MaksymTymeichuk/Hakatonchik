#include <iostream>
#include <map>
#include <string>

#include <iomanip>
using namespace std;

string add_student(string name, string group) {
    return "";
}

string add_grade(string name, string group, int grade) {
    return "";
}

int avg_grade(const map<string, int>& subjects) {
    if (subjects.empty()) return 0;
    double sum = 0;
    for (auto& subj : subjects) sum += subj.second;
    return sum / subjects.size();
}

int table_potik() {
    return 0;
}

int table_stepdiati() {
    return 0;
}

int table_na_vidraxuvani(map<string, map<string, map<string, int>>> students) {
    cout << "\nСТУДЕНТИ НА ВІДРАХУВАННЯ (бал < 50)\n";
    cout << left << setw(40) << "Ім'я студента"
         << setw(10) << "Група"
         << setw(15) << "Середній бал" << endl;
    cout << string(65, '-') << endl;

    bool found = false;

    for (auto& group : students) {
        string group_name = group.first;

        for (auto& student : group.second) {
            string student_name = student.first;
            double avg = avg_grade(student.second);

            if (avg < 50) {
                found = true;
                cout << left << setw(40) << student_name
                     << setw(10) << group_name
                     << setw(15) << fixed << setprecision(2) << avg << endl;
            }
        }
    }

    if (!found)
        cout << "✅ Немає студентів на відрахування." << endl;

    return 0;
}
int avrg_table() {
    return 0;
}

int table_vidminik() {
    return 0;
}


int menu(const bool admin, const map<string, map<string, map<string, int>>>& students) {
    int choice;

    if (admin) {
        cout << "\n1. Додати студента\n"
             << "2. Додати оцінку\n"
             << "3. Вивести весь потік\n"
             << "4. Вивести таблицю стипендіатів\n"
             << "5. Вивести таблицю на відрахування\n"
             << "6. Вивести таблицю середніх оцінок\n"
             << "7. Вивести таблицю відмінників\n"
             << "0. Вихід\n";
    } else {
        cout << "\n1. Вивести весь потік\n"
             << "2. Вивести таблицю стипендіатів\n"
             << "3. Вивести таблицю на відрахування\n"
             << "4. Вивести таблицю середніх оцінок\n"
             << "5. Вивести таблицю відмінників\n"
             << "0. Вихід\n";
    }

    cout << "Ваш вибір: ";
    cin >> choice;

    if (admin) {
        switch (choice) {
            case 1: add_student("", ""); break;

                case 2: add_grade("", "", 0); break;
            case 3: table_potik(); break;
            case 4: table_stepdiati(); break;
            case 5: table_na_vidraxuvani(students); break;
            case 6: avrg_table(); break;
            case 7: table_vidminik(); break;
        }
    } else {
        switch (choice) {
            case 1: table_potik(); break;
            case 2: table_stepdiati(); break;
            case 3: table_na_vidraxuvani(students); break;
            case 4: avrg_table(); break;
            case 5: table_vidminik(); break;
        }
    }

    return choice;
}

int main() {


    map<string, map<string, map<string, int>>> students = {
        {"ai_14", {
            {"Віктор Ярмак Валентинович", {
                {"Дискретна математика", 70},
                {"Математичний аналіз", 90},
                {"Фізкультура", 80}
            }},
            {"Ягодзінська Олександра Сергіївна", {
                {"Дискретна математика", 100},
                {"Математичний аналіз", 100},
                {"Фізкультура", 100}
            }},
            {"Тимейчук Максим Юрійович", {
                {"Дискретна математика", 100},
                {"Математичний аналіз", 100},
                {"Фізкультура", 100}
            }}
        }},
        {"ai_11", {}},
        {"ai_12", {}},
        {"ai_13", {}}
    };


    string user;
    cout << "Хто ви (студент або викладач)?: ";
    cin >> user;

    bool isAdmin = (user == "викладач");

    cout << "Вітаємо, " << (isAdmin ? "викладачу!" : "студенте!") << endl;

    int choice = -1;
    while (choice != 0) {
        choice = menu(isAdmin, students);
    }

    cout << "До побачення!\n";
    return 0;
}