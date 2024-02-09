#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static int i = 0;


typedef struct Student {
    char name[100];
    int id;
    int level;
    int grade;
}student;

void display(student t1[100]) {
    for (int a = 0; a <= i; a++) {
        printf("the list of student :\n\n");
        printf("\nname: %s\n id: %d\n level: %d\n grade: %d\n", t1[a].name, t1[a].id, t1[a].level, t1[a].grade);
    }

}

void add(student t1[100]) {
    int nb;
    float a;

    system("cls");
    printf("\n\t\t **** Add A New Student ****\n\n");

    printf("how many student do you want to add? :");
    scanf("%d", &nb);
    printf("enter the informations of the new  students :   \n");
    for (i = 0; i <= nb; i++) {
        do {
            printf("the id: ");
            scanf("%d", &t1[i].id);
        } while (t1[i].id == i);
        printf("full name : ");
        scanf(" %[^\n]s", &t1[i].name);
        do {
            printf("study level[1-6]: ");
            scanf("%d", &t1[i].level);
        } while (t1[i].level > 6);
        do {
            printf("grade[0-20]: ");
            scanf("%d", &t1[i].grade);
        } while (t1[i].grade > 20);

        printf(" ****** the next student *******\n \n  ");

    }
    system("cls");
    printf("*********************************************\n");
    printf(" the students are successfully registered\n");
    printf("*********************************************\n\n\n");

}



void Remove(student t1[100]) {

    int z;
    printf("\n\t\t **** remove a student ****\n\n");
    printf("-------->  Please enter the ID of the student to be deleted: ");
    int pos; int h;
    int x;
    scanf("%d", &z);
    for (pos = 0; pos < i; pos++) {
        if (t1[pos].id == z) {
            h = pos;
            break;
        };
    }
    for (x = h; x < i; x++)
    {
        t1[x] = t1[x + 1];
    }
    i--;
    system("cls");
    printf("*********************************************\n");
    printf("deleted successfully \n");
    printf("*********************************************\n\n\n");
}

void update(student t1[100]) {
    int a;
    printf("enter the id of the student you want to update: ");
    scanf("%d", &a);

    int pos;
    for (pos = 0; pos < i; pos++) {
        printf("Please enter\n\n");
        printf("full name: ");
        scanf("%s", &t1[i].name);
        printf("study level: ");
        scanf("%d", &t1[i].level);
        printf("grade: ");
        scanf("%d", &t1[i].grade);
    }
    system("cls");
    printf("*********************************************\n");
    printf(" the list is successfully updated\n");
    printf("*********************************************\n\n\n");



}

void search_id(student t1[100]) {
    int id, j;
    printf("enter the id of the student you're looking for: ");
    scanf("%d", &id);

    for (j = 0; j < i; j++) {
        if (t1[j].id == id) { printf("\nname: %s\n id: %d\n level: %d\n grade: %d\n", t1[j].name, t1[j].id, t1[j].level, t1[j].grade); }
        else printf("id not in use");

    }
}
void search_level(student t1[100]) {
    int level, k;
    printf("enter the level of the student you're looking for: ");
    scanf("%d", &level);
    for (k = 0; k < i; k++) {
        if (t1[k].level == level) { printf("\n name: %s\n level: %d\n id: %d\n grade: %d\n", t1[k].name, t1[k].id, t1[k].grade); }
        else printf("level not in use");
    }

}



void average(student t1[100]) {
    int level;
    printf("Enter the level :");
    scanf("%d", &level);
    int j; int nb = 0; int sum = 0;
    for (j = 0; j < i; j++) {
        if (t1[j].level == level) { sum += t1[j].grade; nb++; }
    }
    float x = sum / nb;
    printf("the average of the level %d is %f", level, x);


}

int main() {
    student t1[100];
    int choix;
    int nb;
    printf("\t\t*********************************************\n");
    printf("\t\t \tSTUDENT MANAGEMENT SYSTEM\n");
    printf("\t\t*********************************************\n\n\n");
    do {
        printf("\t\t\tMAIN MENU\n");
        printf("\t\t=======================\n");
        printf("\t\t[0] Exit the Program.\n");
        printf("\t\t[1] Add A New student(s).\n");
        printf("\t\t[2] Remove a student.\n");
        printf("\t\t[3] Update a student.\n");
        printf("\t\t[4] Display the list of students.\n");
        printf("\t\t[5] Find a student by ID.\n");
        printf("\t\t[6] Find students by level.\n");
        printf("\t\t[7] Find students by average.\n");
        printf("\t\t[8] Calculate the general average by level.\n");
        printf("\t\t[9] Sort students.\n");

        printf("\t\t=======================\n");
        printf("\t\tEnter The Choice: ");
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
        case 0: printf("Goodbye"); return 0;
        case 1:add(t1);
            i++;
            break;
        case 2:

            printf(" ********* this is the list of the student ********");
            display(t1);
            printf("\n");
            Remove(t1);
            break;
        case 3:printf(" ********* this is the list of the student ********");
            display(t1);
            printf("\n");
            printf("\n\t\t **** update Student ****\n\n");
            update(t1);
            break;
        case 4:display(t1);
            break;
        case 5:
            printf("\n\t\t **** search by the ID ****\n\n");
            search_id(t1);
            break;
        case 6:
            printf("\n\t\t **** search by the level ****\n\n");
            search_level(t1);
            break;
        case 7:
            printf("\n\t\t **** average ****\n\n");
            average(t1);
            break;
        case 8:
            break;
        }
    } while (choix < 10);

    return 0;
}
