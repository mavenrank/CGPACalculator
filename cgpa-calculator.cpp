#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

#define SEMESTERS 8
#define NUMBER_OF_COURSES 7

void *storeSemesterGPAs(double *semesterGPAs, double *semesterCredits, int currentSemester)
{
    double semGPA = 0.0;
    for (int i = 0; i < currentSemester - 1; i++)
    {
        cout << "Enter Semester " << i + 1 << " GPA : ";
        cin >> semesterGPAs[i];
        cout << "Number of Credits in Sem " << i + 1 << " : ";
        cin >> semesterCredits[i];
    }
    return 0;
}

double calculateCGPA(double *semesterGPAs, double *semesterCredits, int currentSemester)
{
    double totalCGPA = 0.0;
    double numerator, denominator = 0;
    for (int i = 0; i < currentSemester; i++)
    {
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

float GPAuntilSemesterToGet9CGPA(double *semesterGPAs, double *semesterCredits, int currentSemester, double CGPAuntilNow, int numberOfSemesters, int credits = 24)
{
    double totalCGPA = 0.0;
    double numerator, denominator = 0;
    bool flag = true;
    while (true)
    {
        for (int i = 0; i < currentSemester; i++)
        {
            numerator += semesterGPAs[i] * semesterCredits[i];
            denominator += semesterCredits[i];
        }
        double requiredGPA = ((9 * (denominator + (credits * numberOfSemesters)) - numerator) / (numberOfSemesters)-credits);
        if (requiredGPA > 10)
        {
            if (8 - currentSemester <= numberOfSemesters)
            {
                cout << "You can't get 9CGPA, good luck with placements";
            }
            else
            {
                cout << "It is not possible to get 9 CGPA within " << numberOfSemesters << " Semesters" << endl;
                cout << "Try increasing the number of semesters" << endl;
                numberOfSemesters++;
            }
        }
        else
        {
            cout << "Required GPA for " << numberOfSemesters << " is : " << requiredGPA << endl;
            flag = false;
            return requiredGPA;
        }
    }
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
    while (true)
    {
        cout << "Which semester are you in right now? ";
        cin >> currentSemester;
        if (cin.fail() || currentSemester < 1 || currentSemester > 8)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a semester number between 1 and 8." << endl;
        }
        else
        {
            break;
        }
    }
    storeSemesterGPAs(semesterGPAs, semesterCredits, currentSemester);
    printArray(semesterGPAs, SEMESTERS);
    printArray(semesterCredits, SEMESTERS);
    double CGPA = calculateCGPA(semesterGPAs, semesterCredits, currentSemester);
    cout << "Your CGPA till now = " << CGPA << endl;

    int numberOfSemestersUntil9 = 0;
    int futureSemestersCredits[SEMESTERS - currentSemester];
    cout << "Enter number of semesters until when you want to get 9CGPA : ";
    cin >> numberOfSemestersUntil9;
    cout << "Do you know the credits of the semesters ?";

    GPAuntilSemesterToGet9CGPA(semesterGPAs, semesterCredits, currentSemester, CGPA, numberOfSemestersUntil9);
    string Courses[NUMBER_OF_COURSES] = {"Database Systems", "Operating Systems", "Compiler Design", "Computer Networks", "Artificial Intelligence", "Amazon Web Services", "Advanced Competitive Coding"};
    float Credits[NUMBER_OF_COURSES] = {4, 4, 4, 4, 3, 3, 1.5};
    float credsForthisSemester = calculateSemesterCredits(Credits, NUMBER_OF_COURSES);
    cout << "Total Credits for this Semester : " << credsForthisSemester << endl;
}