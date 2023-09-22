#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float gpa;
    struct Student *next;
};

struct Student* addStudent(struct Student *head, char *name, int age, float gpa) {
    struct Student *newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Pointer is null\n");
        exit(1);
    }

    strncpy(newStudent->name, name, sizeof(newStudent->name));
    newStudent->age = age;
    newStudent->gpa = gpa;
    newStudent->next = head;
    return newStudent;
}

void printStudentList(struct Student *head) {
    struct Student *current = head;
    while (current != NULL) {
        printf("Name: %s, Age: %d, GPA: %.2f\n", current->name, current->age, current->gpa);
        current = current->next;
    }
}

void freeStudentList(struct Student *head) {
    struct Student *current = head;
    while (current != NULL) {
        struct Student *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Student *studentList = NULL;

    studentList = addStudent(studentList, "Kravchenko", 20, 92);
    studentList = addStudent(studentList, "kolesnikov", 20, 94);
    studentList = addStudent(studentList, "Velychko", 20, 98);

    printf("List of students:\n");
    printStudentList(studentList);

    freeStudentList(studentList);

    return 0;
}
