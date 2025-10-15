#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <vector>


void add_grade(map<string, map<string, map<string,vector <int> >>> &students,string group, string name, string subject, int grade)
    {       
            if(students.find(group)==students.end())
            {
                cout <<"Такої групи не існує\n";
                return;
            }   
            if(students[group].find(name)==students[group].end())
            {
                cout <<"Такого студента не має в списках\n";
                return;
            }
            if(students[group][name].find(subject)==students[group][name].end())
            {
                cout <<"Такого предмету немає у студента\n";
                return;
            }
            if(!(grade>=0 && grade <=100))
            {
            cout << "Вибачте ваша оцінка не в діапазоні можливих оцінок яку ви можете поставити студенту,введіть оцінку з діапазону від 0 до 100\n";
            return ;
            }
             
            
                students[group][name][subject].push_back(grade);
                cout <<"Оцінку додано\n";
            
    }

int main()
{  
     return 0;
}

