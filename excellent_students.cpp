#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;

void printExcellentStudents(const vector<pair<string, double>>& rating) {
    vector<pair<string, double>> excellentOnly;

    for (auto& student : rating) {
        if (student.second >= 88) {
            excellentOnly.push_back(student);
        }
    }

    sort(excellentOnly.begin(), excellentOnly.end(),
         [](const auto& a, const auto& b) {
             return a.second > b.second;
         });

    for (int i = 0; i < excellentOnly.size(); ++i) {
        cout << i + 1 << ". " << excellentOnly[i].first << " — " << excellentOnly[i].second << endl;
    }
}

int getGrade(const map<string, map<string, map<string, int>>>& students,
             const string& group,
             const string& name,
             const string& subject) {
    return students.at(group).at(name).at(subject);
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
        }}
    };

    vector<pair<string, double>> rating;

    // Заповнення рейтингу
    for (auto& group : students) {
        for (auto& student : group.second) {
            double sum = 0;
            for (auto& subject : student.second) {
                sum += subject.second;
            }
            double avg = sum / student.second.size();
            rating.push_back({student.first, avg});
        }
    }

    printExcellentStudents(rating);

    return 0;
}