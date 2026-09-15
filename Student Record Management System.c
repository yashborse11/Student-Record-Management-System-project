#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};

void addStudent(FILE *fp) {
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    fwrite(&s, sizeof(struct Student), 1, fp);
    printf("Student added successfully!\n");
}

void displayStudents(FILE *fp) {
    struct Student s;
    rewind(fp);
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        printf("ID: %d, Name: %s, Age: %d\n", s.id, s.name, s.age);
    }
}

int main() {
    FILE *fp = fopen("students.dat", "ab+");
    int choice;
    do {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addStudent(fp); break;
            case 2: displayStudents(fp); break;
        }
    } while(choice != 3);
    fclose(fp);
    return 0;
}
