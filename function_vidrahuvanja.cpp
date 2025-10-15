#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

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
            {"Дискретна математика", 45},
            {"Математичний аналіз", 30},
            {"Фізкультура", 55}
        }}
    }}
};

// ─── Функція для обчислення середнього бала студента ──────────────
double avg_grade(const map<string, int>& subjects) {
    if (subjects.empty()) return 0;
    double sum = 0;
    for (auto& subj : subjects) sum += subj.second;
    return sum / subjects.size();
}

// ─── Таблиця студентів на відрахування (середній < 50) ────────────
void table_na_vidraxuvanni() {
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
}

// ─── Головна функція для тесту ────────────────────────────────────
int main() {
    table_na_vidraxuvanni();
    return 0;
}