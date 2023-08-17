#include "Functions.h"

int main()
{
    char id[8];
    int choice;

    struct student *head;
    struct student *s1;
    struct student *s2;
    struct student *s3;
    s1 = malloc(sizeof(struct student));
    s2 = malloc(sizeof(struct student));
    s3 = malloc(sizeof(struct student));

    s1->gpa = 4.0;
    s1->academicYear = 2023;
    strcpy(s1->Name, "Mohamed Salah");
    strcpy(s1->id, "123\0");
    // s1->id = 123;
    s1->gender = 'M';

    s2->gpa = 6.0;
    s2->academicYear = 2023;
    strcpy(s2->Name, "Ahmed Mohamed");
    strcpy(s2->id, "321\0");
    // s2->id = 321;
    s2->gender = 'M';

    s3->gpa = 3.0;
    s3->academicYear = 2023;
    strcpy(s3->Name, "Ahmed Mohsen");
    strcpy(s3->id, "456\0");
    // s2->id = 321;
    s3->gender = 'M';

    s1->next = s2;
    s2->next = s3;
    s3->next = NULL;
    head = s1;

    bool finish = false;
    while (!finish)
    {
        printf("\n/***************************************************************************************/\n\n                                     Student Mangement System                                     \n/***************************************************************************************/\n\n\nChoose the desired operation: \n\n1- Add a new student\n2- Remove a student\n3- Retrieve student's data\n4- Update student's data\n5-Print List of Students\n6-Exit Program\n");
        printf("\nChoice : ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            add_student(&head);
            break;
        case 2:
            delete_student(&head);
            break;
        case 3:
            search_student(&head);
            break;
        case 4:
            update_student(&head);
            break;
        case 5:
            print_students(&head);
            break;
        case 6:
            finish = true;
            break;
        default:
            printf("\n\nChoose the desired operation: \n\n1- Add a new student\n2- Remove a student\n3- Retrieve student's data\n4- Update student's data\n");
            break;
        }
    }
    system("cls");
    printf("\nSystem is closed");
    return 0;
}
