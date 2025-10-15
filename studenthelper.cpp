#include<iostream>
#include <map>
using namespace std;


map<string, map<string, map<string, int>>> add_student(string name, string group, map<string, map<string, map<string, int>>> students) {
    students[group][name] = {
        {"Дискретна математика", 0},
        {"Математичний аналіз", 0},
        {"Фізкультура", 0}
    };


    return students;
};

int main(){

    return 0;
}

