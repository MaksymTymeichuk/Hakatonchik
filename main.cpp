#include <iostream>
#include <map>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <limits>

#include <iomanip>

using namespace std;

using RatingVector = vector<pair<string, double>>;

vector<pair<string, double>> rating;

void add_student(map<string, map<string, map<string, int>>> &students) {
    string group, name;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Введдіть 0 для поверння до меню" << endl;

    cout << "Введіть ПІБ: ";
    getline(cin, name);

    if (name == "0") {
        cout << "Вихід до головного меню" << endl;
        return;
    }

    while (true) {

        cout << "Введіть групу: ";

        cin >> group;

        if (group == "0") {
            cout << "Вихід до головного меню." << endl;
            return;
        }

        if(group=="ai_11" or group=="ai_12" or group=="ai_13" or group=="ai_14"){

        students[group][name] = {
            {"Дискретна математика", 0},
            {"Математичний аналіз", 0},
            {"Фізкультура", 0}
        };


            cout << "Студента " << name << " було додано у групу " << group;
            return ;
    }

    else
        {
        cout<<"Данні були введені некоректно" << endl;

    }
    }

};

RatingVector avvrg_grade(map<string, map<string, map<string, int>>> students) {
    RatingVector rating;
    for (const auto& groupPair : students) {
        const string& groupName = groupPair.first;
        const auto& studentMap = groupPair.second;

        double groupSum = 0;
        int groupCount = 0;


        for (const auto& studentPair : studentMap) {
            const string& studentName = studentPair.first;
            const auto& subjects = studentPair.second;

            double studentSum = 0;
            for (const auto& subjectPair : subjects) {
                studentSum += subjectPair.second;
            }

            double studentAvg = studentSum / subjects.size();

            rating.push_back({studentName, studentAvg});
            groupSum += studentAvg;
            groupCount++;
        }
        // double groupAvg = (groupCount > 0) ? groupSum / groupCount : 0;
        // cout << "Середній бал групи " << groupName << ": " << groupAvg << "\n\n";
    }

    return rating;
}

int avrrg_table(map<string, map<string, map<string, int>>> students) {
    rating.clear();

    for (const auto& groupPair : students) {
        const string& groupName = groupPair.first;
        const auto& studentMap = groupPair.second;

        cout << "\nГрупа: " << groupName << endl;

        double groupSum = 0;
        int groupCount = 0;

        for (const auto& studentPair : studentMap) {
            const string& studentName = studentPair.first;
            const auto& subjects = studentPair.second;

            double studentSum = 0;
            for (const auto& subjectPair : subjects) {
                studentSum += subjectPair.second;
            }

            double studentAvg = studentSum / subjects.size();
            cout << "  " << studentName << " — середній бал: " << fixed << setprecision(1) << studentAvg << endl;

            rating.push_back({studentName, studentAvg});

            groupSum += studentAvg;
            groupCount++;
        }

        double groupAvg = (groupCount > 0) ? groupSum / groupCount : 0;
        cout << "Середній бал групи " << groupName << ": " << fixed << setprecision(1) << groupAvg << "\n";
    }

    return rating.size(); // кількість студентів у рейтингу
}

string add_grade(map<string, map<string, map<string, int>>> &students) {
    string name;
    string group;
    string subject;
    int grade;

    cout << "Введдіть 0 для повернення до меню" << endl;

    while (true) {
        cout << "Введіть групу: ";
        cin >> group;

        if (group == "0") {
            cout << "Вихід до головного меню" << endl;
            return "";
        }

        if (students.find(group) == students.end()) {
            cout << "Такої групи не існує" << endl;
        } else {
            cout << "Ви вибрали " << group <<" групу" << endl;
            break;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "Введіть ПІБ студента: ";
        getline(cin, name);

        if (name == "0") {
            cout << "Вихід до головного меню" << endl;
            return "";
        }

        if(students[group].find(name) == students[group].end()) {
            cout <<"Такого студента не має в списках групи " << group << "\n";
        }
        else {
            cout << "Студента знайдено" << endl;
            break;
        }
    }


    while (true) {

        cout << "Введіть предмет: ";

        getline(cin, subject);

        if (subject == "0") {
            cout << "Вихід до головного меню" << endl;
            return "";
        }

        if (students[group][name].find(subject) == students[group][name].end())
        {
            cout <<"Такого предмету немає у списку предметів\n";
            cout << "Доступні предмети: ";
            for (const auto& pair : students[group][name]) {
                 cout << pair.first << " | ";
            }
            cout << endl;
        }
        else {
            cout << "Ви вибрали предмет " << subject << endl;
            break;
        }
    }

    cout << "Введдіть -1 для повернення до меню" << endl;

    while (true) {
        cout << "Введіть оцінку (0-100) для " << name << " з предмету " << subject << ": ";

        if (subject == "-1") {
            cout << "Вихід до головного меню" << endl;
            return "";
        }

        if (!(cin >> grade)) {
            cout << "Вибачте, ввід некоректний. Введіть число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if(!(grade >= 0 && grade <= 100))
        {
            cout << "Вибачте, ваша оцінка не в діапазоні від 0 до 100.\n";
        }
        else {
            students[group][name][subject] = grade;
            cout << "✅ Оцінку " << grade << " додано студенту " << name << " з предмету " << subject << "\n";
            cin.clear();
            return "";
        }
    }
}

int avg_grade(const map<string, int>& subjects) {
    if (subjects.empty()) return 0;
    double sum = 0;
    for (auto& subj : subjects) sum += subj.second;
    return sum / subjects.size();
}

int table_potik(const map<string, map<string, map<string, int>>>& students) {
    cout << "\n--- ЗАГАЛЬНИЙ СПИСОК СТУДЕНТІВ ---\n";
    cout << string(80, '=') << endl;
    for (const auto& group : students) {
        cout << "Група: " << group.first << endl;
        cout << string(80, '-') << endl;
        if (group.second.empty()) {
            cout << "  У групі немає студентів.\n";
        } else {
            for (const auto& student : group.second) {
                cout << "  Студент: " << student.first << "\n";
                if (student.second.empty()) {
                    cout << "    Предмети та оцінки відсутні.\n";
                } else {
                    for (const auto& subject : student.second) {
                        cout << "    -> " << left << setw(30) << subject.first << ": " << subject.second << endl;
                    }
                }
            }
        }
        cout << endl;
    }
    cout << string(80, '=') << endl;

    return 0;
}

int table_stepdiati() {
    return 0;
}



int table_na_vidraxuvani(map<string, map<string, map<string, int>>> students) {
    cout << "\nСТУДЕНТИ НА ВІДРАХУВАННЯ (бал < 50)\n";

    cout << left << setw(40) << "Ім'я студента"
         << " | " << setw(10) << "Група"
         << " | " << right << setw(12) << "Середній бал" << endl;

    cout << string(68, '-') << endl;

    bool found = false;

    for (const auto& group : students) {
        string group_name = group.first;

        for (const auto& student : group.second) {
            string student_name = student.first;
            double avg = avg_grade(student.second);

            if (avg < 50) {
                found = true;
                cout << left << setw(40) << student_name
                     << " | " << setw(10) << group_name
                     << " | " << right << setw(12)
                     << fixed << setprecision(2) << avg << endl;
            }
        }
    }

    if (!found)
        cout << "✅ Немає студентів на відрахування." << endl;

    return 0;
}


int avrg_table(const RatingVector& rating) {
    if (rating.empty()) cout << "Рейтинг порожній!" << endl;
    RatingVector sortedRating = rating;
    sort(sortedRating.begin(), sortedRating.end(),
      [](const auto& a, const auto& b) {
          return a.second > b.second;
     });

    cout << "Рейтинг студентiв за середнiм балом: " << endl;
    for (int i = 0; i < rating.size(); i++) {
        cout << i + 1 << ". " << sortedRating[i].first << " - " << sortedRating[i].second << endl;
    }

    return 0;
}

int table_vidminik(const map<string, map<string, map<string, int>>>& students) {

    vector<pair<string, double>> excellentOnly;

    for (const auto& groupPair : students) {
        const auto& studentMap = groupPair.second;

        for (const auto& studentPair : studentMap) {
            const string& studentName = studentPair.first;
            double avg = 0;
            if (!studentPair.second.empty()) {
                double sum = 0;
                for (const auto& subject : studentPair.second)
                    sum += subject.second;
                avg = sum / studentPair.second.size();
            }

            if (avg >= 88) {
                excellentOnly.push_back({studentName, avg});
            }
        }
    }


    sort(excellentOnly.begin(), excellentOnly.end(),
         [](const pair<string, double>& a, const pair<string, double>& b) {
             return a.second > b.second;
         });


    if (excellentOnly.empty()) {
        cout << "Відмінників немає.\n";
        return 0;
    }

    cout << left << setw(3) << "#"
         << setw(35) << "Ім’я студента"
         << right << setw(12) << "Середній бал" << endl;
    cout << string(55, '-') << endl;

    for (size_t i = 0; i < excellentOnly.size(); ++i) {
        cout << left << setw(3) << i + 1
             << setw(35) << excellentOnly[i].first
             << right << setw(12) << fixed << setprecision(1) << excellentOnly[i].second
             << endl;
    }

    cout << "\nЗагальна кількість відмінників: " << excellentOnly.size() << "\n";

    return excellentOnly.size();
}

int table_stepdiati(map<string, map<string, map<string, int>>> students) {
    if (students.empty()) {
        cout << "Помилка: база даних порожня" << endl;
        return 1;
    }

    bool is_there_a_student = false;
    cout << "\nТаблиця студентів на стипендіат: (>=70)" << endl;

    for (const auto& group : students) {
        const string& group_name = group.first;
        bool group_printed = false;

        for (const auto& student : group.second) {
            const string& student_name = student.first;
            double avg = avg_grade(student.second);

            if (avg >= 70) {
                is_there_a_student = true;

                if (!group_printed) {
                    cout << string(60, '=') << endl;
                    cout << "Група: " << group_name << endl;
                    cout << left << setw(40) << "ПІБ студента"
                         << " | " << right << setw(12) << "Середній бал" << endl;
                    cout << string(60, '-') << endl;
                    group_printed = true;
                }

                // красиве вирівнювання: ім’я ліворуч, бал праворуч
                cout << left << setw(40) << student_name
                     << " | " << right << setw(12)
                     << fixed << setprecision(1) << avg << endl;
            }
        }
    }

    if (!is_there_a_student) {
        cout << "\nСтипендіатів не знайдено" << endl;
    }

    return 0;
}



int menu(const bool admin, map<string, map<string, map<string, int>>>& students) {
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

    if (!(cin >> choice)) {
        // якщо ввід некоректний (наприклад, переповнення або літера)
        cin.clear(); // скидаємо помилку
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаємо буфер
        cout << "❌ Некоректний ввід! Спробуйте ще раз.\n";
        return -1; // повертаємо фіктивне значення, щоб цикл не зламався
    }

    // якщо choice вийшов за межі меню
    if (choice < 0 || choice > 7) {
        cout << "❌ Такого пункту меню не існує.\n";
        return -1;
    }

    // решта switch без змін...
    if (admin) {
        switch (choice) {
            case 1: add_student(students); break;
            case 2: add_grade(students); break;
            case 3: table_potik(students); break;
            case 4: table_stepdiati(students); break;
            case 5: table_na_vidraxuvani(students); break;
            case 6: avrg_table(avvrg_grade(students)); break;
            case 7: table_vidminik(students); break;
        }
    } else {
        switch (choice) {
            case 1: table_potik(students); break;
            case 2: table_stepdiati(students); break;
            case 3: table_na_vidraxuvani(students); break;
            case 4: avrg_table(avvrg_grade(students)); break;
            case 5: table_vidminik(students); break;
        }
    }

    return choice;
}

int main() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    map<string, map<string, map<string, int>>> students = {
        {"ai_14", {
            {"Віктор Ярмак Валентинович", {
                {"Дискретна математика", 70},
                {"Математичний аналіз", 90},
                {"Фізкультура", 80}
            }},
            {"Ягодзінська Олександра Сергіївна", {
                {"Дискретна математика", 100},
                {"Математичний аналіз", 10},
                {"Фізкультура", 10}
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
    cout << "Хто ви (студент (с) або викладач (в)?: ";
    cin >> user;

    bool isAdmin = false;

    if (user == "викладач" || user == "в") {
        isAdmin = true; // присвоюємо зовнішній змінній
        cout << "Вітаємо, викладачу!";
    }
    else if (user == "студент" || user == "с") {
        cout << "Вітаємо, студенте!";
    }
    else {
        cout << "Я таких не знаю";
        return -999;
    }

    int choice = -1;
    while (choice != 0) {
        choice = menu(isAdmin, students);
    }

    cout << "До побачення!\n";
    return 0;
}