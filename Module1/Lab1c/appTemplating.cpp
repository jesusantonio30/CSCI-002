#include <iostream>
#include <string>

using namespace std;

template <class T>
struct Student
{
    string name;
    int ID;
    T testAvg, hwAvg, finalAvg;
    float testWeight, hwWeight, finalWeight;

    Student(string argName="John Doe", int argID=10000, T argTestAvg=1, T argHwAvg=1, T argFinalAvg=1, float argTestWeight=0.55, float argHwWeight=0.10, float argFinalWeight=0.35);

    void display();
    double calculateWeightedAverage();
    char getGrade();
};



int main() {

    char runAgain = ' ';

    do {

        string studName = "";
        int studID = 0;
        double studHwAvg = 0.00;
        float studTestAvg = 0.0,
            studFinalAvg = 0.0,
            testW8 = 0.0,
            hwW8 = 0.0,
            finalW8 = 0.0;

        cout << "\n---------- Student Info ----------\n";
        cout << "\nEnter name (e.g. John Doe): ";
        getline(cin, studName);

        cout << "\nEnter ID (e.g. 99999): ";
        cin >> studID;

        cout << "\n---------- Student Avg Scores ----------\n";

        cout << "\nEnter homework score: ";
        cin >> studHwAvg;

        cout << "\nEnter test score: ";
        cin >> studTestAvg;

        cout << "\nEnter final score: ";
        cin >> studFinalAvg;

        cout << "\n---------- Weights ----------\n";

        while ((hwW8 + testW8 + finalW8) != 1.00) {
            cout << "**Weights need to add up to 100%**\n";

            cout << "\nHomework weight: ";
            cin >> hwW8;

            cout << "\nTest weight: ";
            cin >> testW8;

            cout << "\nFinal weight: ";
            cin >> finalW8;
        }

        cout << "\n---------- Results ----------\n";

        Student<float> randStudent(studName, studID, studTestAvg, studHwAvg, studFinalAvg, testW8, hwW8, finalW8);

        randStudent.display();
        cout << "\nweightedAvg = " << hwW8 << "(" << studHwAvg << ") + " << testW8 << "(" << studTestAvg << ") + " << finalW8 << "(" << studFinalAvg << ") = " << randStudent.calculateWeightedAverage() << " = " << randStudent.getGrade() << endl;

        cout << "\n\nCalculate another student's grade? (y/n): ";
        cin >> runAgain;

        cin.ignore();

    } while (tolower(runAgain) == 'y');

    return 0;
}



template <class T>
Student<T>::Student(string argName, int argID, T argTestAvg, T argHwAvg, T argFinalAvg, float argTestWeight, float argHwWeight, float argFinalWeight) {
    name = argName;
    ID = argID;
    testAvg = argTestAvg;
    hwAvg = argHwAvg;
    finalAvg = argFinalAvg;
    testWeight = argTestWeight;
    hwWeight = argHwWeight;
    finalWeight = argFinalWeight;
}

template <class T>
void Student<T>::display() {
    cout << "\n- Name: " << name << endl;
    cout << "- ID: " << ID << endl;
    cout << "- Homework Weight: " << hwWeight << endl;
    cout << "- Homework Grade: " << hwAvg << endl;
    cout << "- Test Weight: " << testWeight << endl;
    cout << "- Test Grade: " << testAvg << endl;
    cout << "- Final Weight: " << finalWeight << endl;
    cout << "- Final Grade: " << finalAvg << endl;
}

template <class T>
double Student<T>::calculateWeightedAverage() {
    return (hwWeight * hwAvg) + (testWeight * testAvg) + (finalWeight * finalAvg);
}

template <class T>
char Student<T>::getGrade() {
    double grade = calculateWeightedAverage();
    if (grade >= 90) return 'A';
    if (grade >= 80) return 'B';
    if (grade >= 70) return 'C';
    if (grade >= 60) return 'D';
    return 'F';
}