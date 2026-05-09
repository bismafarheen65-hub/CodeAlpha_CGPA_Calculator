#include<iostream>
using namespace std;
void interface()
{
    cout << "----------------CGPA Calculator System------------" << endl;
    cout << "\nWelcome Student! " << endl;
    cout << "Track your academic performance easily " << endl;

}
string getGrade(float gpa)
{
    if (gpa >= 4.0)
        return "A";

    else if (gpa >= 3.5)
        return "B+";

    else if (gpa >= 3.0)
        return "B";

    else if (gpa >= 2.5)
        return "C";

    else if (gpa >= 2.0)
        return "D";

    else
        return "F";
}
// Function to take input
void inputData(int& n, float gpa[], float credit[])
{
    cout << "\nEnter number of subjects: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "----------------------------------" << endl;
        cout << "Subject " << i + 1 << endl;
        cout << "Enter GPA: ";
        cin >> gpa[i];

        while (gpa[i] < 0 || gpa[i] > 4)
        {
            cout << "Invalid GPA! Enter again: ";
            cin >> gpa[i];
        }
        cout << "Grade = " << getGrade(gpa[i]) << endl;
        cout << "Enter Credit Hours: ";
        cin >> credit[i];
    }
}

// Function to calculate CGPA
float calculateSGPA(int n, float gpa[], float credit[])
{
    float totalPoints = 0;
    float totalCredits = 0;
    for (int i = 0; i < n; i++)
    {
        totalPoints += gpa[i] * credit[i];
        totalCredits += credit[i];
    }
    cout << "\nTotal Credit Hours = " << totalCredits << endl;
    if (totalCredits == 0)
        return 0;
    return totalPoints / totalCredits;
}
// Function to calculate CGPA
float calculateCGPA(float previousCGPA, float currentSGPA)
{
    return (previousCGPA + currentSGPA) / 2;
}

// Function to display result
void displayResult(float cgpa, float sgpa)
{
    cout << "\n==================================================" << endl;
    if (cgpa == 0)
    {
        cout << "Invalid input! Credit hours cannot be zero." << endl;
    }
    else
    {
        cout << "Your Semester GPA (SGPA) is: " << sgpa << endl;
        cout << "Your Final CGPA is: " << cgpa << endl;
        // Performance Message
        if (cgpa >= 3.5)
            cout << "Excellent Performance! " << endl;
        else
            if (cgpa >= 3.0)
                cout << "Very Good Performance! " << endl;
            else
                if (cgpa >= 2.5)
                    cout << "Good Performance " << endl;
                else
                    cout << "Need Improvement " << endl;
    }
    cout << "==================================================" << endl;
    cout << "       Thank you for using our system " << endl;
}



int main() {

    char choice;

    do
    {
        interface();

        int semester;
        cout << "Enter Current Semester: ";
        cin >> semester;

        int n;
        float gpa[50], credit[50];
        inputData(n, gpa, credit);
        float sgpa = calculateSGPA(n, gpa, credit);

        float cgpa;

        // If first semester
        if (semester == 1)
        {
            cgpa = sgpa;
        }
        else
        {
            float previousCGPA;

            cout << "\nEnter Previous CGPA: ";
            cin >> previousCGPA;

            // Calculate Overall CGPA
            cgpa = calculateCGPA(previousCGPA, sgpa);
        }
        displayResult(cgpa, sgpa);

        cout << "\nDo you want to calculate again? (Y/N): ";
        cin >> choice;

        if (choice == 'N' || choice == 'n')
        {
            cout << "\nProgram ended successfully!" << endl;
        }
    } while (choice == 'Y' || choice == 'y');

    return 0;
}