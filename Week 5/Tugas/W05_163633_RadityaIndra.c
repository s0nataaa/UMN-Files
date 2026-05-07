#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song{
    char artist[100];
    char album[100];
    char title[100];
    int year;
    struct Song *prev;
    struct Song *next;
} Song;

Song *head = NULL;
Song *tail = NULL;

Song* createSong(char artist[], char album[], char title[], int year);
void pushTail(char artist[], char album[], char title[], int year);
void readFile();
void printList();
void saveFile();
void addSong();
void deleteTail();
void freeMemory();

int main() {
    int choice;
    do {
        printf("\nPLAYLIST MENU\n");
        printf("1. Tampilkan Data\n");
        printf("2. Tambah Data\n");
        printf("3. Hapus Data\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            freeMemory();
            head = tail = NULL;
            readFile();
            printList();
            break;
        case 2:
            addSong();
            break;
        case 3:
            if(head == NULL){
                readFile();
            }
            deleteTail();
            break;
        case 4:
            freeMemory();
            printf("Program selesai\n");
            break;
        }
    } while (choice != 4);
    
    return 0;
}

Song* createSong(char artist[], char album[], char title[], int year){
    Song *newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->artist, artist);
    strcpy(newSong->album, album);
    strcpy(newSong->title, title);
    newSong->year = year;
    newSong->next = NULL;
    newSong->prev = NULL;
    return newSong;
}

void pushTail(char artist[], char album[], char title[], int year){
    Song *newSong = createSong(artist, album, title, year);
    if(head == NULL){
        head = tail = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
}

void readFile() {
    FILE *fp = fopen("playlist.txt", "r");
    if(fp == NULL){
        printf("File tidak ditemukan\n");
        return;
    }

    char line[512];
    while(fgets(line, sizeof(line), fp) != NULL){
        line[strcspn(line, "\n")] = '\0';
        if(strlen(line) == 0) continue;

        char artist[100], album[100], title[100];
        int year;

        char *token;
        token = strtok(line, "*");
        if(!token) continue;
        strncpy(artist, token, 99); artist[99] = '\0';

        token = strtok(NULL, "*");
        if(!token) continue;
        strncpy(album, token, 99); album[99] = '\0';

        token = strtok(NULL, "*");
        if(!token) continue;
        strncpy(title, token, 99); title[99] = '\0';

        token = strtok(NULL, "*");
        if(!token) continue;
        year = atoi(token);

        pushTail(artist, album, title, year);
    }
    fclose(fp);
}

void printList() {
    if(head == NULL){
        printf("Playlist kosong\n");
        return;
    }
    Song *curr = head;
    int i = 1;
    while(curr != NULL){
        printf("%d. %s - %s (%s - %d)\n",
            i,
            curr->artist,
            curr->title,
            curr->album,
            curr->year);
        curr = curr->next;
        i++;
    }
}

void saveFile() {
    FILE *fp = fopen("playlist.txt", "w");
    if(fp == NULL){
        printf("Gagal menyimpan file\n");
        return;
    }
    Song *curr = head;
    while(curr != NULL){
        fprintf(fp, "%s*%s*%s*%d\n",
            curr->artist,
            curr->album,
            curr->title,
            curr->year);
        curr = curr->next;
    }
    fclose(fp);
}

void addSong() {
    char artist[100], album[100], title[100];
    int year;

    if(head == NULL){
        readFile();
    }

    printf("Artist : ");
    scanf(" %[^\n]", artist);
    printf("Album : ");
    scanf(" %[^\n]", album);
    printf("Title : ");
    scanf(" %[^\n]", title);
    printf("Year : ");
    scanf("%d", &year);

    pushTail(artist, album, title, year);
    saveFile();
    printf("Lagu %s berhasil ditambahkan\n", title);
}

void deleteTail() {
    if(tail == NULL){
        printf("Playlist kosong\n");
        return;
    }
    Song *trash = tail;
    printf("Lagu %s berhasil dihapus dari list.\n", trash->title);
    if(head == tail){
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(trash);
    saveFile();
}

void freeMemory() {
    Song *curr = head;
    while(curr != NULL){
        Song *temp = curr;
        curr = curr->next;
        free(temp);
    }
    head = tail = NULL;
}