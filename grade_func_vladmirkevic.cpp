#include <iostream>
#include <map>
#include <string>
#include <windows.h>

using namespace std;

string add_student(string name, string group) {
    return "";
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

int table_potik() {
    
    return 0;
}

int table_stepdiati() {
    return 0;
}

int table_na_vidraxuvani() {
    return 0;
}

int avrg_table() {
    return 0;
}

int table_vidminik() {
    return 0;
}

int avrg_grade() {
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
            case 1: add_student("", ""); break;

                case 2: add_grade(students); break;
            case 3: table_potik(); break;
            case 4: table_stepdiati(); break;
            case 5: table_na_vidraxuvani(); break;
            case 6: avrg_table(); break;
            case 7: table_vidminik(); break;
        }
    } else {
        switch (choice) {
            case 1: table_potik(); break;
            case 2: table_stepdiati(); break;
            case 3: table_na_vidraxuvani(); break;
            case 4: avrg_table(); break;
            case 5: table_vidminik(); break;
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