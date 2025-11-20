#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"
#define MAX_NAME 100
#define MAX_GENDER 10
#define MAX_GRADE 20
#define MAX_COURSE 100
#define MAX_CONTACT 50

typedef struct {
    int id;
    char name[MAX_NAME];
    int age;
    char gender[MAX_GENDER];
    char grade[MAX_GRADE];
    char course[MAX_COURSE];
    char contact[MAX_CONTACT];
} Student;

// Function declarations
void addStudent();
void listStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
int idExists(int id);

void saveStudent(Student s);
Student* loadAll(int *count);
void writeAll(Student *arr, int count);

// ------------------ MAIN ------------------
int main() {
    int choice;
    do {
        printf("\n=========== STUDENT MANAGEMENT SYSTEM ===========\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: listStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

// ------------------ ADD STUDENT ------------------
void addStudent() {
    Student s;

    printf("\n--- Add Student ---\n");
    printf("Enter ID: ");
    scanf("%d", &s.id);
    getchar();

    if (idExists(s.id)) {
        printf("ID already exists!\n");
        return;
    }

    printf("Enter name: ");
    fgets(s.name, MAX_NAME, stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter age: ");
    scanf("%d", &s.age);
    getchar();

    printf("Enter gender: ");
    fgets(s.gender, MAX_GENDER, stdin);
    s.gender[strcspn(s.gender, "\n")] = 0;

    printf("Enter grade: ");
    fgets(s.grade, MAX_GRADE, stdin);
    s.grade[strcspn(s.grade, "\n")] = 0;

    printf("Enter course: ");
    fgets(s.course, MAX_COURSE, stdin);
    s.course[strcspn(s.course, "\n")] = 0;

    printf("Enter contact: ");
    fgets(s.contact, MAX_CONTACT, stdin);
    s.contact[strcspn(s.contact, "\n")] = 0;

    saveStudent(s);
    printf("Student added!\n");
}

// ------------------ SAVE STUDENT ------------------
void saveStudent(Student s) {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
}

// ------------------ CHECK ID ------------------
int idExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// ------------------ LIST STUDENTS ------------------
void listStudents() {
    int count;
    Student *arr = loadAll(&count);

    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n%-5s %-20s %-5s %-10s %-10s %-15s %-25s\n",
           "ID", "Name", "Age", "Gender", "Grade", "Course", "Contact");
    printf("-----------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-5d %-10s %-10s %-15s %-25s\n",
               arr[i].id, arr[i].name, arr[i].age,
               arr[i].gender, arr[i].grade,
               arr[i].course, arr[i].contact);
    }

    free(arr);
}

// ------------------ SEARCH ------------------
void searchStudent() {
    printf("\nEnter ID to search: ");
    int id;
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records.\n");
        return;
    }

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("\nStudent Found!\n");
            printf("Name: %s\nAge: %d\nGender: %s\nGrade: %s\nCourse: %s\nContact: %s\n",
                   s.name, s.age, s.gender, s.grade, s.course, s.contact);
            fclose(fp);
            return;
        }
    }

    printf("Student not found.\n");
    fclose(fp);
}

// ------------------ UPDATE ------------------
void updateStudent() {
    int count;
    Student *arr = loadAll(&count);

    printf("\nEnter ID to update: ");
    int id;
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (arr[i].id == id) {
            printf("New contact: ");
            fgets(arr[i].contact, MAX_CONTACT, stdin);
            arr[i].contact[strcspn(arr[i].contact, "\n")] = 0;

            printf("New grade: ");
            fgets(arr[i].grade, MAX_GRADE, stdin);
            arr[i].grade[strcspn(arr[i].grade, "\n")] = 0;

            printf("New course: ");
            fgets(arr[i].course, MAX_COURSE, stdin);
            arr[i].course[strcspn(arr[i].course, "\n")] = 0;

            writeAll(arr, count);
            printf("Updated successfully!\n");
            free(arr);
            return;
        }
    }

    printf("ID not found.\n");
    free(arr);
}

// ------------------ DELETE ------------------
void deleteStudent() {
    int count;
    Student *arr = loadAll(&count);

    printf("\nEnter ID to delete: ");
    int id;
    scanf("%d", &id);
    getchar();

    int index = -1;
    for (int i = 0; i < count; i++)
        if (arr[i].id == id) index = i;

    if (index == -1) {
        printf("ID not found.\n");
        free(arr);
        return;
    }

    printf("Deleting %s... Confirm (y/n): ", arr[index].name);
    char c = getchar();
    if (c == 'y' || c == 'Y') {
        for (int j = index; j < count - 1; j++)
            arr[j] = arr[j + 1];
        count--;
        writeAll(arr, count);
        printf("Deleted.\n");
    } else {
        printf("Cancelled.\n");
    }

    free(arr);
}

// ------------------ LOAD ALL ------------------
Student* loadAll(int *count) {
    *count = 0;
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return NULL;

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    *count = size / sizeof(Student);
    Student *arr = malloc(size);

    fread(arr, sizeof(Student), *count, fp);
    fclose(fp);
    return arr;
}

// ------------------ WRITE ALL ------------------
void writeAll(Student *arr, int count) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        printf("File write error!\n");
        return;
    }
    fwrite(arr, sizeof(Student), count, fp);
    fclose(fp);
}
