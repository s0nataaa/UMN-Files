#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data {
    char id[20];
    char source [20];
    char destination [20];
    int priority;
    int request_time;
} Data;

typedef struct {
    Data data[100];
    int size;
} Heap;

void swap(Data *a, Data *b);
int hArr(Data a, Data b);
void maxheapify(Heap *h, int i);
void minheapify(Heap *h, int i);
void insert(char id[], char source[], char desti[], int prio, int req_time, Heap *h);
void process();
void change_prio();
void printheap(Heap *h);

int main() {
    char command[50];
    Heap h;
    h.size = 0;
    char id[20], source[20], desti[20];
    int prio, req_time;

    printf("========== Routing Service ==========\n");
    printf("Commands:\n");
    printf("- REQUEST <id> <Source> <Destination> <Priority> <Request Time>\n");
    printf("- PROCESS <Number of Request>\n");
    printf("- CHANGE_PRIORITY <id> <New Priority>\n");
    printf("- EXIT\n\n");

    while(1) {
        scanf("%s", command);
        
        if (strcmp(command, "REQUEST")== 0) {
            scanf("%s %s %s %d %d", id, source, desti, &prio, &req_time);
            insert(id, source, desti, prio, req_time, &h);
        } else if (strcmp(command, "PROCESS")==0) {
            printf("BELOM JADI LMAOOAOAOAO SUSAH BANGET");
        } else if (strcmp(command, "CHANGE_PRIORITY")==0) {
            printf("BELOM JADI LMAOOAOAOAO SUSAH BANGET");
        } else if (strcmp(command, "EXIT")==0) {
            break;
        }
    }
}
void swap(Data *a, Data *b) {
    Data temp = *a;
    *a = *b;
    *b = temp;
}

void printheap(Heap *h){
    printf("Current Heap State (IDs): ");
    printf("[");
    for(int i = 0; i < h->size; i++){
        printf("%s", h->data[i].id);
        if(i != h->size - 1){
            printf(",");
        }
    }
    printf("]\n");
    printf("--------------------------\n");
}

int hArr(Data a, Data b){
    if(a.priority == b.priority)
        return a.request_time < b.request_time;
    return a.priority > b.priority;
}

void maxheapify(Heap *h, int i){
    if(i == 0) return;
    int parent = (i - 1)/2;

    if(hArr(h->data[i], h->data[parent])){
        swap(&h->data[i], &h->data[parent]);
        maxheapify(h, parent);
    }
}

void insert(char id[], char source[], char desti[], int prio, int req_time, Heap *h) {
    int max = 100;
    
    if(h->size >= max){
        printf("Heap MAX\n");
        return;
    }
    
    strcpy(h->data[h->size].id, id);
    strcpy(h->data[h->size].source, source);
    strcpy(h->data[h->size].destination, desti);
    h->data[h->size].priority = prio;
    h->data[h->size].request_time = req_time;
    
    maxheapify(h, h->size);
    h->size++;

    printf("[OK] Request %s\n added.", id);

    printheap(h);
}











