// Review of Procedural Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

const int MAX_STUDENTS = 100; // Maximum capacity of arrays

// Function Prototypes
int readData(string names[], vector<int> scores[], int capacity, const string& filename);
char assignGrade(double average);
void computeAveragesAndGrades(const vector<int> scores[], double averages[], char grades[], int count);
void printReport(const string names[], const double averages[], const char grades[], int count);

int main() {
    string names[MAX_STUDENTS];
    // Using a vector of ints for each student to handle variable number of scores
    vector<int> scores[MAX_STUDENTS];
    double averages[MAX_STUDENTS];
    char grades[MAX_STUDENTS];
    int studentCount = 0;

    // Read data from file
    studentCount = readData(names, scores, MAX_STUDENTS, "StudentGrades.txt");

    if (studentCount == 0) {
        cout << "No student data read. Exiting program." << endl;
        return 1;
    }

    // Compute averages and assign grades
    computeAveragesAndGrades(scores, averages, grades, studentCount);

    // Output the formatted report
    printReport(names, averages, grades, studentCount);

    return 0;
}

// Function to read student data from a file into parallel, partially filled arrays
int readData(string names[], vector<int> scores[], int capacity, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return 0;
    }

    int count = 0;
    string firstName, lastName;
    int score;

    while (count < capacity && inFile >> firstName >> lastName) {
        names[count] = firstName + " " + lastName;

        // Read all scores for the current student from the same line
        // The while loop continues as long as there are integers to read on the line
        while (inFile >> score) {
            scores[count].push_back(score);
        }
        // Clear the error flags for the stream and ignore the rest of the line
        // to prepare for the next student's line
        inFile.clear();
        string dummy;
        getline(inFile, dummy);

        count++;
    }

    inFile.close();
    return count;
}

// Function to compute averages and assign grades
void computeAveragesAndGrades(const vector<int> scores[], double averages[], char grades[], int count) {
    for (int i = 0; i < count; ++i) {
        int sum = 0;
        for (int score : scores[i]) {
            sum += score;
        }
        // Calculate average; avoid division by zero
        if (!scores[i].empty()) {
            averages[i] = static_cast<double>(sum) / scores[i].size();
            grades[i] = assignGrade(averages[i]);
        }
        else {
            averages[i] = 0.0;
            grades[i] = 'F'; // Assign 'F' if no scores found
        }
    }
}

// Function to assign a letter grade based on the average score
char assignGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

// Function to print the formatted grade report
void printReport(const string names[], const double averages[], const char grades[], int count) {
    cout << "\n--- Student Grade Report ---\n";
    cout << left << setw(20) << "Name" << setw(15) << "Average Score" << setw(10) << "Grade" << endl;
    cout << "------------------------------------------\n";

    for (int i = 0; i < count; ++i) {
        cout << left << setw(20) << names[i]
            << setw(15) << fixed << setprecision(2) << averages[i]
            << setw(10) << grades[i] << endl;
    }
    cout << "------------------------------------------\n";
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
