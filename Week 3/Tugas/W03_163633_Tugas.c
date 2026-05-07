#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char nim[20];
    char name[100];
    char major[100];
} Student;

typedef struct {
    char nim[20];
    float tugas;
    float uts;
    float uas;
    float finalScore;
    char grade[4];
} Grade;

void loadstudents(Student students[], int *n);
void loadgrades(Grade grades[], int *m);
void showall(Student students[], Grade grades[], int n, int m);
void addstudent(Student students[], Grade grades[], int *n, int *m);
float calculatefinal(float tugas, float uts, float uas);
void determinegrade(float finalScore, char grade[]);

int main() {
    Student students[MAX];
    Grade grades[MAX];
    int n = 0, m = 0;
    int choice;

    loadstudents(students, &n);
    loadgrades(grades, &m);

    while (1) {
        printf("\n=== STUDENT DATABASE ===\n");
        printf("1. Show All Data\n");
        printf("2. Add Student\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            showall(students, grades, n, m);
        } else if (choice == 2) {
            addstudent(students, grades, &n, &m);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void loadstudents(Student students[], int *n) {
    FILE *fp = fopen("dataMahasiswa.txt", "r");
    if (fp == NULL) return;

    while (fscanf(fp, "%[^#]#%[^#]#%[^\n]\n", students[*n].nim, students[*n].name, students[*n].major) == 3) {
        (*n)++;
    }

    fclose(fp);
}

void loadgrades(Grade grades[], int *m) {
    FILE *fp = fopen("nilaiMahasiswa.txt", "r");
    if (fp == NULL) return;

    while (fscanf(fp, "%[^#]#%f#%f#%f#%f#%[^\n]\n", grades[*m].nim, &grades[*m].tugas, &grades[*m].uts, &grades[*m].uas, &grades[*m].finalScore, grades[*m].grade) == 6) {
        (*m)++;
    }

    fclose(fp);
}

void showall(Student students[], Grade grades[], int n, int m) {
    printf("\n=====================================================================================\n");
    printf("| %-12s | %-25s | %-15s | %-6s |\n", "NIM", "Name", "Major", "Grade");
    printf("=====================================================================================\n");

    for (int i = 0; i < n; i++) {
        char gradeDisplay[4] = "-";

        for (int j = 0; j < m; j++) {
            if (strcmp(students[i].nim, grades[j].nim) == 0) {
                strcpy(gradeDisplay, grades[j].grade);
                break;
            }
        }

        printf("| %-12s | %-25s | %-15s | %-6s |\n", students[i].nim, students[i].name, students[i].major, gradeDisplay);
    }

    printf("=====================================================================================\n");
}

void addstudent(Student students[], Grade grades[], int *n, int *m) {

    if (*n >= MAX) {
        printf("Database full!\n");
        return;
    }

    printf("\nInsert Student Data\n");

    printf("NIM    : ");
    scanf(" %[^\n]", students[*n].nim);

    printf("Name   : ");
    scanf(" %[^\n]", students[*n].name);

    printf("Major  : ");
    scanf(" %[^\n]", students[*n].major);

    printf("Tugas  : ");
    scanf("%f", &grades[*m].tugas);

    printf("UTS    : ");
    scanf("%f", &grades[*m].uts);

    printf("UAS    : ");
    scanf("%f", &grades[*m].uas);

    strcpy(grades[*m].nim, students[*n].nim);

    grades[*m].finalScore = calculatefinal(
        grades[*m].tugas,
        grades[*m].uts,
        grades[*m].uas
    );

    determinegrade(grades[*m].finalScore, grades[*m].grade);

    FILE *fp1 = fopen("dataMahasiswa.txt", "a");
    fprintf(fp1, "%s#%s#%s\n",
            students[*n].nim,
            students[*n].name,
            students[*n].major);
    fclose(fp1);

    FILE *fp2 = fopen("nilaiMahasiswa.txt", "a");
    fprintf(fp2, "%s#%.0f#%.0f#%.0f#%.1f#%s\n",
            grades[*m].nim,
            grades[*m].tugas,
            grades[*m].uts,
            grades[*m].uas,
            grades[*m].finalScore,
            grades[*m].grade);
    fclose(fp2);

    printf("Student added successfully!\n");

    (*n)++;
    (*m)++;
}

float calculatefinal(float tugas, float uts, float uas) {
    return (0.3 * tugas) + (0.3 * uts) + (0.4 * uas);
}

void determinegrade(float finalScore, char grade[]) {
    if (finalScore >= 95)
        strcpy(grade, "A+");
    else if (finalScore >= 85)
        strcpy(grade, "A");
    else if (finalScore >= 80)
        strcpy(grade, "A-");
    else if (finalScore >= 75)
        strcpy(grade, "B+");
    else if (finalScore >= 70)
        strcpy(grade, "B");
    else if (finalScore >= 65)
        strcpy(grade, "C");
    else if (finalScore >= 60)
        strcpy(grade, "C-");
    else if (finalScore >= 55)
        strcpy(grade, "D");
    else
        strcpy(grade, "E");
}