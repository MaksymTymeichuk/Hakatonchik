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

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline

    cout << "Введіть ПІБ: ";
    getline(cin, name);

    cout << "Введіть групу: ";
    cin >> group;

    if(group=="ai_11" or group=="ai_12" or group=="ai_13" or group=="ai_14"){

        students[group][name] = {
            {"Дискретна математика", 0},
            {"Математичний аналіз", 0},
            {"Фізкультура", 0}
        };
    }
    else{
        cout<<"Данні були введені некоректно";
        return ;
    }




    return;
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
    cout << "Введіть групу\n";
    cin >> group;
    cout << "Ви вибрали " << group <<" групу\n";
    if(students.find(group)==students.end())
    {
        cout <<"Такої групи не існує\n";
        return "" ;
    }
    cout << "Введіть ПІБ\n";
    cin.ignore();
    getline(cin,name);

    if(students[group].find(name)==students[group].end())
    {
        cout <<"Такого студента не має в списках\n";
        return "";
    }
    cout << "Введіть предмет\n";
    getline(cin,subject);
    cout << "Ви вибрали предмет" << subject <<"\n";
    if(students[group][name].find(subject)==students[group][name].end())
    {
        cout <<"Такого предмету немає у студента\n";
        return "";
    }
    cout << "Введіть оцінку, яку хочете поставити студенту " << name << "\n";
    cin >> grade;



    if(!(grade>=0 && grade <=100))
    {
        cout << "Вибачте ваша оцінка не в діапазоні можливих оцінок яку ви можете поставити студенту,введіть оцінку з діапазону від 0 до 100\n";
        return "" ;
    }


    students[group][name][subject]=grade;
    cout <<"Оцінку додано\n";

    return "";
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

int table_vidminik(map<string, map<string, map<string, int>>> students) {

    avrrg_table(students);

    vector<pair<string, double>> excellentOnly;

    for (const auto& student : rating) {
        if (student.second >= 88) {
            excellentOnly.push_back(student);
        }
    }

    sort(excellentOnly.begin(), excellentOnly.end(),
         [](const pair<string, double>& a, const pair<string, double>& b) {
             return a.second > b.second;
         });

    cout << left << setw(3) << "#" << setw(35) << "Ім’я студента" << "Середній бал" << endl;
    cout << string(55, '-') << endl;

    for (size_t i = 0; i < excellentOnly.size(); ++i) {
        cout << left << setw(3) << i + 1
             << setw(35) << excellentOnly[i].first
             << fixed << setprecision(1) << excellentOnly[i].second << endl;
    }
    cout << "\nЗагальна кількість відмінників: " << excellentOnly.size() << "\n";
    return excellentOnly.size(); // кількість відмінників
}

int table_stepdiati(map<string, map<string, map<string, int>>> students) {
    if (students.empty()){
        cout << "Помилка: база даних порожня" << endl;
        return 1;
    }
    bool is_there_a_student = false;
    cout << "\nТаблиця студентів на стипендіат: (>=70)" << endl;
    for (const auto& group : students){ //групи
        const string& group_name = group.first;
        bool group_printed = false;

        for (const auto& student : group.second){ //студіки
            const string& student_name = student.first;
            double avg = avg_grade(student.second);
            if (avg>=70){
                is_there_a_student = true;
                if (!group_printed){
                    cout << string(54, '=') << endl;
                    cout << "Група: " << group_name << endl;
                    cout << setw(40) << left << "ПІБ студента" << " | " << "Середній бал" << endl;
                    cout << string(54, '-') << endl;
                    group_printed = true;
                }
                cout << setw(40) << left << student_name << " | " << avg << "\n";

            }
        }
    }
    if (!is_there_a_student){
        cout << "\nСтипендіатів не найдено" << endl;
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
    cin >> choice;

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