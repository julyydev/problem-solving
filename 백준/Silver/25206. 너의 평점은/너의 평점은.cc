#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string subject, credit, grade;

    double totalSum = 0, gradeNum;
    int creditSum = 0;

    for (int i = 0; i < 20; i++) {
        cin >> subject >> credit >> grade;
        if (grade == "A+") {
            gradeNum = 4.5;
        } else if (grade == "A0") {
            gradeNum = 4.0;
        } else if (grade == "B+") {
            gradeNum = 3.5;
        } else if (grade == "B0") {
            gradeNum = 3.0;
        } else if (grade == "C+") {
            gradeNum = 2.5;
        } else if (grade == "C0") {
            gradeNum = 2.0;
        } else if (grade == "D+") {
            gradeNum = 1.5;
        } else if (grade == "D0") {
            gradeNum = 1.0;
        } else if (grade == "F") {
            gradeNum = 0.0;
        } else if (grade == "P") {
            continue;
        }

        if (credit == "1.0") {
            creditSum += 1;
            totalSum += gradeNum * 1;
        } else if (credit == "2.0") {
            creditSum += 2;
            totalSum += gradeNum * 2;
        } else if (credit == "3.0") {
            creditSum += 3;
            totalSum += gradeNum * 3;
        } else if (credit == "4.0") {
            creditSum += 4;
            totalSum += gradeNum * 4;
        }
    }

    cout.precision(7);
    cout << totalSum / creditSum << "\n";

    return 0;
}