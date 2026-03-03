// Review of Procedural Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Constants for array limits and grading scale
const int MAXSTUDENTS = 10;
const int NUMTESTS = 5;

// Function Prototypes
int readData(string names[], double scores[][NUMTESTS], string filename);
char calculateGrade(double average);
void Print(const string names[], const double scores[][NUMTESTS], int count);

int main() {
    string names[MAXSTUDENTS];
    double scores[MAXSTUDENTS][NUMTESTS];
    string filename = "studentgrades.txt";

    int studentCount = readData(names, scores, filename);

    if (studentCount > 0) {
        Print(names, scores, studentCount);
    }
    else {
        cout << "No data found or file error." << endl;
    }

    return 0;
}


//Function Declarations
// Reads data into parallel arrays and returns the actual count
int readData(string names[], double scores[][NUMTESTS], string filename) {
    ifstream inFile(filename);
    if (!inFile) return 0;

    int count = 0;
    while (count < MAXSTUDENTS && inFile >> names[count]) {
        for (int j = 0; j < NUMTESTS; j++) {
            inFile >> scores[count][j];
        }
        count++;
    }
    inFile.close();
    return count;
}

// Logic for assigning letter grades
char calculateGrade(double average) {
    if (average >= 90) return 'A';
    if (average >= 80) return 'B';
    if (average >= 70) return 'C';
    if (average >= 60) return 'D';
    return 'F';
}

// Formats and displays the final grade report
void Print(const string names[], const double scores[][NUMTESTS], int count) {
    cout << left << setw(15) << "Name" << setw(10) << "Average" << "Grade" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < count; i++) {
        double sum = 0;
        for (int j = 0; j < NUMTESTS; j++) {
            sum += scores[i][j];
        }
        double avg = sum / NUMTESTS;

        cout << left << setw(15) << names[i]
            << setw(10) << fixed << setprecision(2) << avg
            << calculateGrade(avg) << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
