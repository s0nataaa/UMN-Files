#include <stdio.h>

void perkalian(int matrix1[3][3], int matrix2[3][3]);
void penjumlahan(int matrix1[3][3], int matrix2[3][3]);
void transpose(int matrix1[3][3], int matrix2[3][3]);

int main() {
    
    printf("Masukkan Matrix Pertama(3 x 3)\n");
    int matrix1[3][3];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("Masukkan Matrix Kedua 3 x 3)\n");
    int matrix2[3][3];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    while(1) {
        int numb;
        printf("\n1. Perkalian Dua Buah Matrix\n2. Penjumlahan Dua Buah Matrix\n3. Transpose Dua Buah Matrix\n4. Keluar\nPilihan: ");
        scanf("%d", &numb);

        if (numb == 1) {
            perkalian(matrix1, matrix2);
        } else if (numb == 2) {
            penjumlahan(matrix1, matrix2);
        } else if (numb == 3) {
            transpose(matrix1, matrix2);
        } else if (numb == 4) {
            break;
        } else {
            printf("Invalid Input\n");
        }
    }
    return 0;
}

void perkalian(int matrix1[3][3], int matrix2[3][3]) {
    int result[3][3];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void penjumlahan(int matrix1[3][3], int matrix2[3][3]) {
    int result[3][3];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void transpose(int matrix1[3][3], int matrix2[3][3]) {
    int result1[3][3], result2[3][3];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result1[i][j] = matrix1[j][i];
        }
    }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            result2[i][j] = matrix2[j][i];
        }
    }

    printf("Matrix Pertama\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", result1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix Kedua\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", result2[i][j]);
        }
        printf("\n");
    }
}