#include <stdio.h>

#define MAX 100

int marks[MAX];
int n;

// Function to input marks
void inputMarks()
{
    printf("Enter number of students: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
}

// Function to display marks
void displayMarks()
{
    printf("\nStudent Marks:\n");
    for(int i = 0; i < n; i++)
    {
        printf("Student %d : %d\n", i + 1, marks[i]);
    }
}

// Function to calculate highest, lowest, total and average
void calculateResult()
{
    int highest = marks[0];
    int lowest = marks[0];
    int total = 0;
    float average;

    for(int i = 0; i < n; i++)
    {
        total += marks[i];

        if(marks[i] > highest)
            highest = marks[i];

        if(marks[i] < lowest)
            lowest = marks[i];
    }

    average = (float)total / n;

    printf("\nHighest Marks = %d", highest);
    printf("\nLowest Marks = %d", lowest);
    printf("\nTotal Marks = %d", total);
    printf("\nAverage = %.2f\n", average);
}

// Function to search marks
void searchMarks()
{
    int key, found = 0;

    printf("Enter marks to search: ");
    scanf("%d", &key);

    for(int i = 0; i < n; i++)
    {
        if(marks[i] == key)
        {
            printf("Marks found at Student %d\n", i + 1);
            found = 1;
        }
    }

    if(found == 0)
        printf("Marks not found.\n");
}

// Function to sort marks
void sortMarks()
{
    int temp;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(marks[i] > marks[j])
            {
                temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }

    printf("Marks sorted successfully.\n");
}

int main()
{
    int choice;

    inputMarks();

    do
    {
        printf("\n----- Student Marks Analyzer -----\n");
        printf("1. Display Marks\n");
        printf("2. Calculate Highest, Lowest, Total & Average\n");
        printf("3. Search Marks\n");
        printf("4. Sort Marks (Ascending)\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayMarks();
                break;

            case 2:
                calculateResult();
                break;

            case 3:
                searchMarks();
                break;

            case 4:
                sortMarks();
                displayMarks();
                break;

            case 5:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}