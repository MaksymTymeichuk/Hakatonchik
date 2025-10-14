#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
#include <locale.h>

void avgRating ( vector<pair<string, double>> &rating) {
    vector<pair<string, double>> sortedRating = rating;
        if (rating.empty()) cout << "Рейтинг порожній!" << endl;
        
       sort(sortedRating.begin(), sortedRating.end(),
         [](const auto& a, const auto& b) {
             return a.second > b.second; 
        });

        cout << "Рейтинг студентiв за середнiм балом: " << endl;
        for (int i = 0; i < rating.size(); i++) {
            cout << i + 1 << ". " << sortedRating[i].first << " - " << sortedRating[i].second << endl;
    }
}

int main(){
     //setlocale(LC_ALL, "uk_UA.UTF-8"); 
    // map<string, map<string, map<string, int>>> students = {
    //     {"ai_14", {
    //         {"Віктор Ярмак Валентинович", {
    //             {"Дискретна математика", 70},
    //             {"Математичний аналіз", 90},
    //             {"Фізкультура", 80}
    //         }},
    //         {"Ягодзінська Олександра Сергіївна", {
    //             {"Дискретна математика", 100},
    //             {"Математичний аналіз", 100},
    //             {"Фізкультура", 100}
    //         }},
    //         {"Тимейчук Максим Юрійович", {
    //             {"Дискретна математика", 100},
    //             {"Математичний аналіз", 100},
    //             {"Фізкультура", 100}
    //         }}
    //     }}
    // };

    vector<pair<string, double>> rating; 
    
    // for (const auto& groupPair : students) {
    //     const string& groupName = groupPair.first; 
    //     const auto& studentMap = groupPair.second; 

    //     cout << "Група: " << groupName << endl;

    //     double groupSum = 0;
    //     int groupCount = 0;

        
    //     for (const auto& studentPair : studentMap) {
    //         const string& studentName = studentPair.first;
    //         const auto& subjects = studentPair.second;     

    //         double studentSum = 0;
    //         for (const auto& subjectPair : subjects) {
    //             studentSum += subjectPair.second; 
    //         }

    //         double studentAvg = studentSum / subjects.size();
    //         cout << "  " << studentName << " — середній бал: " << studentAvg << endl;

            rating.push_back({studentName, studentAvg});

    //         groupSum += studentAvg;
    //         groupCount++;
    //     }

    //     double groupAvg = (groupCount > 0) ? groupSum / groupCount : 0;
    //     cout << "Середній бал групи " << groupName << ": " << groupAvg << "\n\n";
    // }

    
   avgRating(rating);

    return 0;

}
