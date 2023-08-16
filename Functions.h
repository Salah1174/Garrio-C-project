#include "Student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
int IsZero(char s[])
{
    int d;
    d ;
}
void IsDigit(char s[])
{

    bool digit = false;
    bool found = false;
    while (!digit)
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
int compare(char s1[], char s2[])
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
void add_student(struct student **head)
{
    struct student *newnode = (struct student *)malloc(sizeof(struct student));
    struct student *temp = *head;
    int spaceCounter;

    printf("Enter first name : ");
    fgets(newnode->Name, sizeof(newnode->Name), stdin);
    fflush(stdin);

    printf("\nEnter ID : ");
    fgets(newnode->id, sizeof(newnode->id), stdin);
    IsDigit(newnode->id);
    bool added = false;
    while (!added)
    {
        bool found = false;
        temp = *head;
        while (temp != NULL)
        {
            if (!compare(newnode->id, temp->id))
            {
                printf("\nID already exists");
                found = true;
            }
            temp = temp->next;
        }

        if (found)
        {
            printf("\nEnter ID : ");
            fgets(newnode->id, sizeof(newnode->id), stdin);
            // scanf("%d", &newnode->id);
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
        if (newnode->gender == 'M' || newnode->gender == 'F' || newnode->gender == 'm' || newnode->gender == 'f')
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
        if (newnode->academicYear >= 1 && newnode->academicYear <= 2024)
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
        if (newnode->gpa >= 0.0 && newnode->gpa <= 4.0)
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
    (*head) = newnode;
}
void print_students(struct student **head)
{
    struct student *current = *head;
    struct student *temp = NULL;
    struct student *index = NULL;
    // if (head == NULL)
    //     return;
    // if (head != NULL)
    // {
    //     while (current != NULL)
    //     {
    //         index = current->next;
    //         while (index != NULL)
    //         {
    //             if (current->gpa > index->gpa)
    //             {
    //                 temp->next = current->next;
    //                 current->next = index->next;
    //                 index->next = temp->next;
    //             }
    //             index = index->next;
    //         }
    //         current = current->next;
    //     }
    // }
    // current = *head;
    while (current != NULL)
    {
        printf(" \nFirst name  %s ", current->Name);
        printf(" \nID  %s ", current->id);
        printf(" \nGender  %c ", current->gender);
        printf(" \nAcademic Year  %d ", current->academicYear);
        printf(" \nGPA  %.2f ", current->gpa);
        current = current->next;
    }
}
void search_student(struct student **head)
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
        while (current != NULL)
        {
            if (!compare(current->Name, name))
            {
                printf("\nName is %s", current->Name);
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
void delete_student(struct student **head)
{
    char id[8];
    struct student *temp = *head;
    struct student *prev = NULL;
    // Check if the element to be deleted is first element
    printf("\nEnter ID : ");
    fgets(id, sizeof(id), stdin);
    IsDigit(id);
    fflush(stdin);
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
void update_student(struct student **head)
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