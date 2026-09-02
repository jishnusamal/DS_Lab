#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int rollNo;
    char grade;
} Student;

void readStudents(Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter roll no: ");
        scanf("%d", &s[i].rollNo);
        printf("Enter grade: ");
        scanf(" %c", &s[i].grade);
    }
}

void displayStudents(Student s[], int n) {
    printf("\n--- Student Information ---\n");
    printf("%-20s %-10s %-5s\n", "Name", "Roll No", "Grade");
    printf("------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10d %-5c\n", s[i].name, s[i].rollNo, s[i].grade);
    }
}

void sortStudents(Student s[], int n) {
    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j].rollNo > key.rollNo) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

int main() {
    Student students[100];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    readStudents(students, n);
    displayStudents(students, n);

    sortStudents(students, n);
    printf("\n--- After Sorting by Roll Number ---\n");
    displayStudents(students, n);

    return 0;
}
