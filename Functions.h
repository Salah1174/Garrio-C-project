#include "Student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
void IsSapce(char s[]) // Function to check Name string contains only First and Last names
{
    int count = 0;
    bool space = false;
    while (!space) // Loop until  Given name is two names only
    {

        for (int i = 1; i < strlen(s); i++)
        {
            if (isspace(s[0]))
            {
                count++;
            }
            if (isspace(s[i - 1]))
            {
                count++;
            }
        }
        if (count == 1)
        {
            space = true;
        }
        else
        {
            count = 0;
            printf("\nEnter First and Last name only :");
            gets(s);
        }
    }
}
void IsDigit(char s[]) // Function to check ID string contains digits only
{
    bool digit = false;
    bool found = false;
    while (!digit) // Loop until  Given ID is digits
    {
        for (int i = 1; i < strlen(s); i++)
        {
            if (isdigit(s[i - 1]))
            {
                found = false;
            }
            else
            {
                found = true;
            }
        }
        if (found)
        {
            printf("\nEnter ID(0~9) : ");
            fgets(s, sizeof(s), stdin);
        }
        else
        {
            digit = true;
        }
    }
}
int compare(char s1[], char s2[]) // Compare two Strings
{
    int flag = 0, i = 0;
    while ((s1[i] != '\0' && s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0)
        return 0;
    else
        return 1;
}
void add_student(struct student **head) // Add student
{
    struct student *newnode = (struct student *)malloc(sizeof(struct student));
    struct student *temp = *head;
    int spaceCounter;

    printf("Enter first name : ");
    fgets(newnode->Name, sizeof(newnode->Name), stdin);
    fflush(stdin);
    IsSapce(newnode->Name);

    printf("\nEnter ID : ");
    fgets(newnode->id, sizeof(newnode->id), stdin);
    IsDigit(newnode->id);
    bool added = false;
    while (!added) // Loop until  Given ID is new
    {
        bool found = false;
        temp = *head;
        while (temp != NULL) // Looping on linked list
        {
            if (!compare(newnode->id, temp->id)) // Check if ID is already assigned to a Student
            {
                printf("\nID already exists");
                found = true;
            }
            temp = temp->next; // Moving to next item in linked list
        }

        if (found)
        {
            printf("\nEnter ID : ");
            fgets(newnode->id, sizeof(newnode->id), stdin);
        }
        else
        {
            added = true;
        }
        temp = *head;
    }
    fflush(stdin);
    printf("\nEnter Gender : ");
    newnode->gender = getchar();
    bool charBool = false;
    while (!charBool)
    {
        if (newnode->gender == 'M' || newnode->gender == 'F' || newnode->gender == 'm' || newnode->gender == 'f') // Check Gender Input
        {
            charBool = true;
        }
        else
        {
            printf("\nEnter Gender(M/F): ");
            newnode->gender = getchar();
        }
    }

    printf("\nEnter Academic Year : ");
    scanf("%d", &newnode->academicYear);
    bool year = false;
    while (!year)
    {
        if (newnode->academicYear >= 1 && newnode->academicYear <= 2024) // Check Year
        {
            year = true;
        }
        else
        {
            printf("\nEnter Academic Year(1~2024) : ");
            scanf("%d", &newnode->academicYear);
        }
    }

    printf("\nEnter GPA : ");
    scanf("%f", &newnode->gpa);
    bool gpaBool = false;
    while (!gpaBool)
    {
        if (newnode->gpa >= 0.0 && newnode->gpa <= 4.0) // Check GPA
        {
            gpaBool = true;
        }
        else
        {
            printf("\nEnter GPA (0.0~4.0) : ");
            scanf("%f", &newnode->gpa);
        }
    }

    newnode->next = (*head);
    (*head) = newnode; // Student is added at the beginning of linked list
}
void print_students_sorted(struct student **head) // Print all students' data
{
    struct student *current = *head, *index = NULL; // Assign to head of linked list
    char tempName[100];
    char tempid[8];
    char tempgender;
    int tempacademicYear;
    float tempgpa;
    if (head == NULL)
    {
        return; // Linked list is empty
    }
    else
    {
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
            {
                if (current->gpa < index->gpa)
                {
                    tempgpa = current->gpa; // GPA swap
                    current->gpa = index->gpa;
                    index->gpa = tempgpa;

                    tempacademicYear = current->academicYear; // Academic year swap
                    current->academicYear = index->academicYear;
                    index->academicYear = tempacademicYear;

                    tempgender = current->gender; // Gender swap
                    current->gender = index->gender;
                    index->gender = tempgender;

                    // tempName = current->Name;
                    strcpy(tempName, current->Name); // Name swap
                    // current->Name = index->Name;
                    strcpy(current->Name, index->Name);
                    // index->Name = tempName;
                    strcpy(index->Name, tempName);

                    // tempid = current->id;
                    strcpy(tempid, current->id); // ID swap
                    // current->id = index->id;
                    strcpy(current->id, index->id);
                    // index->id = tempid;
                    strcpy(index->id, tempid);
                }
                index = index->next;
            }
            current = current->next;
        }
    }
    current = *head;

    for (int i = 0; i < 3; i++)
    {
        printf("\nStudent in %d place: ", i + 1);
        printf(" \nFirst name  %s ", current->Name);
        printf(" \nID  %s ", current->id);
        printf(" \nGender  %c ", current->gender);
        printf(" \nAcademic Year  %d ", current->academicYear);
        printf(" \nGPA  %.2f \n", current->gpa);
        current = current->next;
    }
    while (current != NULL)
    {
        printf(" \nFirst name  %s ", current->Name);
        printf(" \nID  %s ", current->id);
        printf(" \nGender  %c ", current->gender);
        printf(" \nAcademic Year  %d ", current->academicYear);
        printf(" \nGPA  %.2f \n", current->gpa);
        current = current->next;
    }
}
// void print_students_all(struct student **head)
// {
//     struct student *current = *head;
//     while (current != NULL) // Looping on linked list
//     {
//         printf(" \nFirst name  %s ", current->Name);
//         printf(" \nID  %s ", current->id);
//         printf(" \nGender  %c ", current->gender);
//         printf(" \nAcademic Year  %d ", current->academicYear);
//         printf(" \nGPA  %.2f \n", current->gpa);
//         current = current->next;
//     }
// }
void search_student(struct student **head) // Search for student
{
    char id[8];
    char name[100];
    struct student *current = *head;
    bool found = false;
    int choice;
    printf("\n1-Search by name\n2-Search by ID");
    printf("\nChoice : ");
    scanf("%d", &choice);
    fflush(stdin);
    switch (choice)
    {
    case 1:
        printf("\nEnter Name : ");
        fgets(name, sizeof(name), stdin);
        IsSapce(name);
        while (current != NULL)
        {
            if (!compare(current->Name, name))
            {
                printf("\nID is %s", current->id);
                printf("\ngpa is %.2f", current->gpa);
                printf("\ngender is %c", current->gender);
                printf("\nYear is %d", current->academicYear);
                found = true;
            }

            current = current->next;
        }
        if (!found)
        {
            printf("Student not found");
        }
        break;
    case 2:
        printf("\nEnter ID : ");
        fgets(id, sizeof(id), stdin);
        IsDigit(id);
        while (current != NULL)
        {
            if (!compare(current->id, id))
            {
                printf("\nName is %s", current->Name);
                printf("\ngpa is %.2f", current->gpa);
                printf("\ngender is %c", current->gender);
                printf("\nYear is %d", current->academicYear);
                found = true;
                break;
            }

            current = current->next;
        }
        if (!found)
        {
            printf("Student not found");
        }
        break;
    }
}
void delete_student(struct student **head) // Delete student from linked list
{
    char id[8];
    struct student *temp = *head;
    struct student *prev = NULL;
    printf("\nEnter ID : ");
    fgets(id, sizeof(id), stdin);
    IsDigit(id);
    fflush(stdin);
    // Check if the element to be deleted is first element
    if (temp != NULL && !compare(temp->id, id))
    {
        *head = temp->next;
        free(temp);
        return;
    }
    // Find the key to be deleted
    while (temp != NULL && compare(temp->id, id))
    {
        prev = temp;
        temp = temp->next;
    }
    // Check if student to be deleted is not found
    if (temp == NULL)
        printf("\nStudent not found");
    prev->next = temp->next;
    free(temp);
}
void update_student(struct student **head) // Edit student's data
{
    char id[8];
    int choice;
    struct student *current = *head;
    bool found = false;
    // Loop on Student list
    printf("\nEnter ID : ");
    fgets(id, sizeof(id), stdin);
    IsDigit(id);
    fflush(stdin);
    while (current != NULL)
    { // If ID is found
        if (!compare(current->id, id))
        {
            printf("\n1-Academic Year\n2-GPA\nChoice : ");
            scanf("%d", &choice);
            fflush(stdin);
            switch (choice)
            {
            case 1:
                printf("\nEnter Academic Year : ");
                scanf("%d", &current->academicYear);
                bool year = false;
                // Loop until  Given Year is true
                while (!year)
                {
                    if (current->academicYear >= 1 && current->academicYear <= 2024)
                    {
                        year = true;
                    }
                    else
                    {
                        printf("\nEnter Academic Year(1~2024) : ");
                        scanf("%d", &current->academicYear);
                    }
                }
                break;
            case 2:
                printf("\nEnter GPA  : ");
                scanf("%f", &current->gpa);
                bool gpaBool = false;
                // Loop until  Given GPA is true
                while (!gpaBool)
                {
                    if (current->gpa >= 0.0 && current->gpa <= 4.0)
                    {
                        gpaBool = true;
                    }
                    else
                    {
                        printf("\nEnter GPA (0.0~4.0) : ");
                        scanf("%f", &current->gpa);
                    }
                }
                break;
            default:
                printf("Choose 1 or 2 only");
                return;
                break;
            }
            found = true;
            break;
        }
        // Move to next Student in list
        current = current->next;
    }
    // If student not found
    if (!found)
    {
        printf("\nStudent not found");
    }
}