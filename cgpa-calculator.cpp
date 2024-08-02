#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

#define SEMESTERS 8
#define NUMBER_OF_COURSES 7

double *storeSemesterGPAs(double *semesterGPAs, double *semesterCredits, int currentSemester)
{
    double semGPA = 0.0;
    for (int i = 0; i < currentSemester-1; i++)
    {
        cout << "Enter Semester " << i + 1 << " GPA : ";
        cin >> semesterGPAs[i];
        cout << "Number of Credits in Sem " << i + 1 << " : ";
        cin >> semesterCredits[i];
    }
    return semesterGPAs;
}

double calculateCGPA(double *semesterGPAs, double *semesterCredits, int currentSemester)
{
    double totalCGPA = 0.0;
    double numerator, denominator = 0;
    for (int i = 0; i < currentSemester; i++){
        numerator += semesterGPAs[i] * semesterCredits[i];
        denominator += semesterCredits[i];
    }
    totalCGPA = numerator / denominator;
    return totalCGPA;
}

float calculateSemesterCredits(float *credit_array, int size)
{
    float totalCredits = 0.0;
    for (int i = 0; i < size; i++)
    {
        totalCredits += credit_array[i];
    }
    return totalCredits;
}

float GPAuntilSemesterToGet9CGPA()
{

}

void printArray(double *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%2f", array[i]);
    }
    cout << endl;
}

int main()
{
    double semesterGPAs[SEMESTERS]{0};
    double semesterCredits[SEMESTERS]{0};
    int currentSemester = 0;
    cout << "Which semester are you in right now? ";
    cin >> currentSemester;
    storeSemesterGPAs(semesterGPAs, semesterCredits, currentSemester);
    printArray(semesterGPAs, SEMESTERS);
    printArray(semesterCredits, SEMESTERS);
    double CGPA = calculateCGPA(semesterGPAs, semesterCredits, currentSemester);
    cout << "Your CGPA till now = " << CGPA << endl;;
    string Courses[NUMBER_OF_COURSES] = {"Database Systems", "Operating Systems", "Compiler Design", "Computer Networks", "Artificial Intelligence", "Amazon Web Services", "Advanced Competitive Coding"};
    float Credits[NUMBER_OF_COURSES] = {4, 4, 4, 4, 3, 3, 1.5};
    float credsForthisSemester = calculateSemesterCredits(Credits, NUMBER_OF_COURSES);
    cout << "Total Credits for this Semester : " << credsForthisSemester << endl;
}