#include <stdio.h>   // Library untuk fungsi input-output (printf, fopen, fscanf, dll)

// Membuat tipe data baru bernama Employee
typedef struct {
    char name[50];        // Menyimpan nama karyawan
    char position[20];    // Menyimpan jabatan karyawan
    int dateJoined;       // Menyimpan tahun/tanggal masuk kerja
    int workDuration;     // Lama bekerja (misalnya dalam tahun)
    int salary;           // Gaji karyawan
} Employee;

int main() {

    int i = 0;  // Variabel counter untuk indexing array

    // Membuat array untuk menyimpan maksimal 3 karyawan
    Employee employees[3];

    // Membuka file "data.txt" dalam mode read (r)
    FILE *fp = fopen("data.txt", "r");

    // Mengecek apakah file berhasil dibuka atau tidak
    if (fp == NULL) {
        printf("Error: File data.txt tidak ditemukan!\n");
        return 1;  // Keluar dari program jika file tidak ada
    }

    /*
        Membaca data dari file selama:
        - format sesuai
        - jumlah data yang berhasil dibaca = 5
        - index belum lebih dari 3
    */
    while (i < 3 && fscanf(fp, "%[^#]#%[^#]#%d#%d#%d\n",
            employees[i].name,
            employees[i].position,
            &employees[i].dateJoined,
            &employees[i].workDuration,
            &employees[i].salary) == 5) {

        i++;  // Pindah ke index berikutnya setelah berhasil membaca 1 data
    }

    fclose(fp);  // Tutup file setelah selesai membaca


    // ================= MENAMPILKAN DATA =================
    printf("===== DATA KARYAWAN =====\n\n");

    for (int j = 0; j < i; j++) {  // Loop sebanyak data yang berhasil dibaca

        printf("Employee #%d\n", j + 1);
        printf("Name          : %s\n", employees[j].name);
        printf("Position      : %s\n", employees[j].position);
        printf("Date Joined   : %d\n", employees[j].dateJoined);
        printf("Work Duration : %d years\n", employees[j].workDuration);
        printf("Salary        : Rp. %d\n\n", employees[j].salary);
    }


    // ================= MENULIS KE FILE OUTPUT =================
    FILE *fout = fopen("output.txt", "w");  // Membuka file output dalam mode write

    // Mengecek apakah file output berhasil dibuat
    if (fout == NULL) {
        printf("Error: Tidak bisa membuat output.txt\n");
        return 1;
    }

    // Menulis ulang data ke file dengan format yang sama seperti input
    for (int j = 0; j < i; j++) {
        fprintf(fout, "%s#%s#%d#%d#%d\n",
                employees[j].name,
                employees[j].position,
                employees[j].dateJoined,
                employees[j].workDuration,
                employees[j].salary);
    }

    fclose(fout);  // Tutup file output agar data tersimpan dengan benar

    printf("Data berhasil ditulis ke output.txt\n");

    return 0;  // Program selesai dengan sukses
}
