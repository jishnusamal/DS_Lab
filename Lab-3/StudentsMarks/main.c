#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int roll_no;
    float marks;
} Student;

void readStudents(Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%s", (s + i)->name);
        printf("Enter roll number: ");
        scanf("%d", &(s + i)->roll_no);
        printf("Enter marks: ");
        scanf("%f", &(s + i)->marks);
    }
}

void displayStudents(Student *s, int n) {
    printf("\n--- All Students ---\n");
    printf("%-20s %-15s %-10s\n", "Name", "Roll Number", "Marks");
    printf("----------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-15d %-10.2f\n", (s + i)->name, (s + i)->roll_no, (s + i)->marks);
    }
}

void highestMarks(Student *s, int n) {
    Student *highest = s;

    for (int i = 1; i < n; i++) {
        if ((s + i)->marks > highest->marks) {
            highest = s + i;
        }
    }

    printf("\n--- Student with Highest Marks ---\n");
    printf("Name: %s\n", highest->name);
    printf("Roll Number: %d\n", highest->roll_no);
    printf("Marks: %.2f\n", highest->marks);
}

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n];
    readStudents(students, n);
    displayStudents(students, n);
    highestMarks(students, n);

    return 0;
}
