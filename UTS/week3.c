#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char judul[50];
    char penulis[50];
    char penerbit[50];
    int tahun;
    float rating;
} Novel;

void showAll(Novel data[100], int *n);
void addNovel(Novel data[100], int *n);
void seeStats();
void removeNewline(char *str){
    str[strcspn(str, "\n")] = 0;
}
int countData() {
    FILE *fp = fopen("novel.txt", "r");
    if (fp == NULL) return 0;

    int count = 0;
    char judul[100], penulis[100], penerbit[100];
    int tahun;
    float rating;

    while (fscanf(fp, " %[^|] | %[^|] | %[^|] | %d | %f\n",
        judul, penulis, penerbit, &tahun, &rating) != EOF)
        count++;

    fclose(fp);
    return count;
}

int main() {
    FILE *fp;
    Novel data[100];
    int option;
    int n = 0;

    
    do {
        int total = countData();
        printf("=================================\n");
        printf("      Novel Database(%d/100)\n", total);
        printf("=================================\n");
        printf("[1] Tampilkan Seluruh Novel\n");
        printf("[2] Tambah Novel\n");
        printf("[3] Lihat Statistik Database\n");
        printf("[4] Keluar\n");
        printf("Pilihan: "); scanf("%d", &option); getchar();

        switch(option) {
            case 1:
                showAll(data, &n);
                break;
            case 2:
                addNovel(data, &n);
                printf("Data telah ditambahkan\n");
                break;
            case 3:
                seeStats();
                break;
            case 4:
                printf("Thank you, good bye!\n");
                break;
            default:
                printf("Please enter from 1 - 4\n");
        }
    } while(option != 4);

    return 0;
}

void showAll(Novel data[100], int *n) {
    FILE *fp = fopen("novel.txt", "r");
    if (fp == NULL) {
        printf("Tidak ada data\n");
        return;
    }

    // Load semua data ke array
    int total = 0;
    while (total < 100 && fscanf(fp, " %[^|] | %[^|] | %[^|] | %d | %f\n",
        data[total].judul,
        data[total].penulis,
        data[total].penerbit,
        &data[total].tahun,
        &data[total].rating) != EOF)
    {
        total++;
    }
    fclose(fp);
    *n = total;

    if (total == 0) {
        printf("Tidak ada data\n");
        return;
    }

    int page = 0;
    int perPage = 10;
    int totalPages = (total + perPage - 1) / perPage;
    char nav;

    while (1) {
        int start = page * perPage;
        int end = start + perPage;
        if (end > total) end = total;

        printf("=================================\n");
        printf("   List Novel (Hal %d/%d)\n", page + 1, totalPages);
        printf("=================================\n");

        for (int i = start; i < end; i++) {
            printf("[%d]\n", i + 1);
            printf("Judul    : %s\n", data[i].judul);
            printf("Penulis  : %s\n", data[i].penulis);
            printf("Penerbit : %s\n", data[i].penerbit);
            printf("Tahun    : %d\n", data[i].tahun);
            printf("Rating   : %.1f\n", data[i].rating);
            printf("---------------------------------\n");
        }

        // Tampilkan opsi navigasi sesuai posisi halaman
        printf("\n");
        if (page > 0 && page < totalPages - 1)
            printf("[N] Next  [P] Prev  [Q] Kembali\n");
        else if (page == 0 && totalPages > 1)
            printf("[N] Next  [Q] Kembali\n");
        else if (page == totalPages - 1 && totalPages > 1)
            printf("[P] Prev  [Q] Kembali\n");
        else
            printf("[Q] Kembali\n");

        printf("Pilihan: "); scanf(" %c", &nav); getchar();
        nav = nav | 32; // lowercase

        if (nav == 'n' && page < totalPages - 1)
            page++;
        else if (nav == 'p' && page > 0)
            page--;
        else if (nav == 'q')
            break;
        else
            printf("Pilihan tidak valid\n");
    }
}

void addNovel(Novel data[100], int *n) {
    FILE *fp = fopen("novel.txt", "a");
    char buffer[50];

    if (fp == NULL) {
        printf("Tidak ada file\n");
    }

    printf("=================================\n");
    printf("          Tambah Novel\n");
    printf("=================================\n");

    printf("Judul: "); fgets(data[*n].judul, 50, stdin);
    removeNewline(data[*n].judul);
    printf("Penulis: "); fgets(data[*n].penulis, 50, stdin);
    removeNewline(data[*n].penulis);
    printf("Penerbit: "); fgets(data[*n].penerbit, 50, stdin);
    removeNewline(data[*n].penerbit);
    printf("Tahun Terbit: "); fgets(buffer, 50, stdin); data[*n].tahun = atoi(buffer);
    printf("Rating: "); fgets(buffer, 50, stdin); data[*n].rating = atof(buffer);

    fprintf(fp, "%s | %s | %s | %d | %.1f\n", 
        data[*n].judul, 
        data[*n].penulis, 
        data[*n].penerbit, 
        data[*n].tahun, 
        data[*n].rating);

    fclose(fp);

    (*n)++;
}

void seeStats() {
    FILE *fp = fopen("novel.txt", "r");
    if (fp == NULL) {
        printf("Tidak ada data\n");
        return;
    }

    int a = 0, b = 0, c = 0, d = 0;

    char judul[100], penulis[100], penerbit[100];
    int tahun;
    float rating;

    while (fscanf(fp, " %[^|] | %[^|] | %[^|] | %d | %f\n",
        judul, penulis, penerbit, &tahun, &rating) != EOF)
    {
        if (rating < 2.0)
            a++;
        else if (rating < 3.0)
            b++;
        else if (rating < 4.0)
            c++;
        else
            d++;
    }

    fclose(fp);

    printf("=================================\n");
    printf("          Statistik Database\n");
    printf("=================================\n");
    printf("Distribusi Rating\n");
    printf("1.0 - 1.99 = %d\n", a);
    printf("2.0 - 2.99 = %d\n", b);
    printf("3.0 - 3.99 = %d\n", c);
    printf("4.0 - 5.00 = %d\n", d);
}