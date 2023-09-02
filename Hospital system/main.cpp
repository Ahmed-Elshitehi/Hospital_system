/*
 *    Author       : Ahmed Salah El-din Elshitehi
 *    Description  : Hospital system
 *    Start coding : 4 / 1 / 2023
 *    Finished     : 5 / 1 / 2023
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
const int specializations_Number = 5;
int queue_capacity = 5;
string specializations_name[specializations_Number + 1] ={"","Internal medicine","General surgery","Orthopedics","Emergency medicine","Radiology"};
// every specialization has a queue and eny patiant in the queue has his name and his specialization#s
vector<deque<string>> patient(21);
vector<pair<string, string>> Archives;
void Welcome (){
    cout << "\t\t\t Welcome to Hospital System\n";
}
int menu() {
    int choice = 0;
    while (!choice) {
        cout << "\n\t\t\tEnter your choice:\n\n"
                "\t\t\t1) Add new patient\n"
                "\t\t\t2) Print all rows\n"
                "\t\t\t3) Get next patient\n"
                "\t\t\t4) print all old patients\n"
                "\t\t\t5) edit row capacity\n"
                "\t\t\t6) Exit\n";

        cin >> choice;

        if (!(1 <= choice && choice <= 6)) {
            cout << "Invalid choice. Try again\n";
            choice = 0;    // loop keep working
        }
    }
    return choice;
}
void add_patient(){
    int spec, statis;
    string name;
    cout << "\n Chose specialization :\n";
    for (int i = 1; i <= specializations_Number; ++i)
        cout <<i<< " : "<< specializations_name[i] << "\n";
    cin >> spec;
    if (patient[spec].size() == queue_capacity) {
        cout << "Sorry we can't add more patients for this specialization the queue is busy\n";
        return;
    }
    cout << "\n what is patiants name :";
    cin >> name;
    cout << "\n Is it  a critical condition"
            "\n 1)YES"
            "\n 2)NO"
            "\n";
    cin >> statis;
    statis /= 2;
    if (statis)
        patient[spec].push_back(name);
    else
        patient[spec].push_front(name);
}
void print_queues() {
    cout << "* * * * * * * * * * * * * * * \n";
    for (int i = 1; i <= specializations_Number; ++i) {
        cout << specializations_name[i] << " : ";
        for (int j = 0; j < patient[i].size(); ++j) {
            cout << char(220);
        }
        cout << " " << (double(patient[i].size()) / queue_capacity)*100 << "%\n";
    }
}
void next_patient(){
    int spec;
    cout << "Enter specialization: ";
    cin >> spec;
    if (patient[spec].empty()) {
        cout << "No patients at the moment. Have rest, Dr\n";
        return;
    }
    cout << patient[spec].front() << " please go with the Dr\n";
    pair<string, string> temp;
    temp.first = patient[spec].front();
    patient[spec].pop_front();
    temp.second = specializations_name[spec];
    Archives.push_back(temp);
}
void print_Archives(){
    cout << "* * * * * * * * * * * * * * * * * * \n";
    for (int i = 0; i < Archives.size(); ++i) {
        cout << i + 1 << ") Name :" << Archives[i].first << "specialization : " << Archives[i].second << "\n";
    }
    cout << "* * * * * * * * * * * * * * * * * * \n";
}
void edit_row(){
    int NEW;
    cout << "Please inter new capacity ";
    cin >> NEW;
    queue_capacity = NEW;
    cout << "Row capacity updated Successfully" << char(3) << "\n";
}
int main() {
    Welcome();
    bool f = true;
    while (f) {
        int choice = menu();
        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                print_queues();
                break;
            case 3:
                next_patient();
                break;
            case 4:
                print_Archives();
                break;
            case 5:
                edit_row();
                break;
            case 6:
                f = false;
                break;
        }
    }
    return 0;
}

#pragma clang diagnostic pop
