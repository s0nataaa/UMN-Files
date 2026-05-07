#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef enum {
    DIPINJAM,
    SELESAI
} Status;

typedef struct {
    char alat[50];
    char nama[50];
    int durasi;
    Status status;
} Logbook;

void showAll(Logbook data[], int count);
void addLoan(Logbook data[], int *count);
void saveFile(Logbook data[], int count);

int main() {
    FILE *fp;
    Logbook data[MAX];
    int count, choice;
    count = 0;

    fp = fopen("logbook.txt", "r");
    if(fp != NULL) {
        while(fscanf(fp, "%49[^|]|%49[^|]|%d|%d\n", data[count].alat, data[count].nama, &data[count].durasi, (int*)&data[count].status) == 4) {
            count++;
        }
    }
    fclose(fp);

    while(1) {
        printf("\nWelcome\n");
        printf("Peminjaman Alat Lab\n");
        printf("1. Show All Loans\n");
        printf("2. Add New Loans\n");
        printf("3. Save & Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar();
        
        if (choice == 1) {
            showAll(data, count);
        } else if (choice == 2) {
            addLoan(data, &count);
        } else if (choice == 3) {
            saveFile(data, count);
            printf("\nData berhasil disimpan\n");
            break;
        } else {
            printf("Invalid input\n");
        }
    }
    return 0;
}

void showAll(Logbook data[], int count) {
    printf("=========== DATA PEMINJAMAN ==========");
    for (int i = 0; i < count; i++) {
        printf("\nAlat : %s", data[i].alat);
        printf("Nama : %s", data[i].nama);
        printf("Durasi : %d", data[i].durasi);
    
        if (data[i].status == DIPINJAM) {
            printf("\nStatus : Dipinjam\n");
        } else {
            printf("\nStatus : Selesai\n");
        }
        printf("----------------------------\n");
    }
}

void addLoan(Logbook data[], int *count) {
    if (*count >= MAX) {
        printf("Data full\n");
        return;
    }

    printf("Nama alat: ");
    fgets(data[*count].alat, 50, stdin);

    printf("Nama peminjam: ");
    fgets(data[*count].nama, 50, stdin);
    
    printf("Durasi: ");
    scanf("%d", &data[*count].durasi);
    getchar();
    printf("\n");

    data[*count].status = DIPINJAM;

    (*count)++;

    printf("Data ditambahkan. Status:dipinjam\n");
}

void saveFile(Logbook data[], int count) {
    /* correct filename to match load/open path */
    FILE *fp = fopen("logbook.txt", "w");

    for(int i = 0; i < count; i++) {
        fprintf(fp, "%s|%s|%d|%d\n", data[i].alat, data[i].nama, data[i].durasi, data[i].status);
    }

    fclose(fp);
}

