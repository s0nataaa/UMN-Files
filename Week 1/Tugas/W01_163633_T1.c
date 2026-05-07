#include <stdio.h>
#include <ctype.h>

void capital(char *kata);
void lower(char *kata);
void switchcase(char *kata);

int main() {

    int numb;
    char kata[100];

    while(1) {
        printf("1. Uppercase\n2. Lowercase\n3. Switching\n4. Keluar\nPilihan : ");
        scanf("%d", &numb);
        getchar();

        if (numb == 1) {
            printf("\nMasukkan kata: ");
            fgets(kata, sizeof(kata), stdin);
            capital(kata);
            printf("\nOutput:\n%s\n", kata);
        } else if (numb == 2){
            printf("\nMasukkan kata: ");
            fgets(kata, sizeof(kata), stdin);
            lower(kata);
            printf("\nOutput:\n%s\n", kata);
        } else if (numb == 3) {
            printf("\nMasukkan kata: ");
            fgets(kata, sizeof(kata), stdin);
            switchcase(kata);
            printf("\nOutput:\n%s\n", kata);

        } else if (numb == 4) {
            printf("Thanks for using\n");
            break;
        } else {
            printf("Invalid Command\n");
        }
    }
    
    return 0;
}

void capital(char *kata) {
    for (int i = 0; kata[i] != '\0'; i++){
        kata[i] = toupper(kata[i]);
    }
}

void lower(char *kata) {
    for (int i = 0; kata[i] != '\0'; i++){
        kata[i] = tolower(kata[i]);
    }
}

void switchcase(char *kata) {
    for (int i = 0; kata[i] != '\0'; i++) {
        if (islower(kata[i])) {
            kata[i] = toupper(kata[i]);
        } else if (isupper(kata[i])) {
            kata[i] = tolower(kata[i]);
        }
    }
}
