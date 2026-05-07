#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void copyArray(int *src, int *dst, int n){
    int i;
    for(i=0; i<n; i++) dst[i] = src[i];
}

void printArray(int *arr, int n){
    int i;
    for(i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

//BUBBLE SORT
void bubbleSort(int *bil, int n){
    int i, j;
    for(i=1; i<n; i++){
        for(j=n-1; j>=1; j--){
            if(bil[j] > bil[j-1]){
                swap(&bil[j], &bil[j-1]);
            }
        }
    }
}

//SELECTION SORT
void selectionSort(int *bil, int n){
    int i, j, temp;
    for(i=0; i<n; i++){
        temp = i;
        for(j=i+1; j<n; j++){
            if(bil[j] > bil[temp]){
                temp = j;
            }
        }
        if(temp != i){
            swap(&bil[temp], &bil[i]);
        }
    }
}

//INSERTION SORT
void insertionSort(int *bil, int n){
    int i, j, temp;
    for(i=0; i<n; i++){
        temp = bil[i];
        for(j=i-1; j>=0 && bil[j] < temp; j--){
            bil[j+1] = bil[j];
        }
        bil[j+1] = temp;
    }
}

typedef struct LinkedList{
    int value;
    struct LinkedList *next;
} LinkedList;

void insertNode(int val, LinkedList **head) {
    LinkedList *newNode = (LinkedList*) malloc(sizeof(LinkedList));
    newNode->value = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        LinkedList *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void radixSort(int *data, int n) {
    int i, j;
    int maks = data[0];

    for(i=1; i<n; i++){
        if(data[i] > maks) maks = data[i];
    }

    int totalIterasi = 0;
    int tempMaks = maks;
    while(tempMaks > 0){
        tempMaks /= 10;
        totalIterasi++;
    }

    LinkedList *bucket[10];
    for(i=0; i<10; i++) bucket[i] = NULL;

    int pembagi = 1;
    for(i=0; i<totalIterasi; i++){
        for(j=0; j<n; j++){
            int digit = (data[j] / pembagi) % 10;
            insertNode(data[j], &bucket[digit]);
        }
        pembagi *= 10;

        int idx = 0;
        for(j=9; j>=0; j--){
            LinkedList *temp = bucket[j];
            while(temp != NULL){
                data[idx] = temp->value;
                idx++;
                temp = temp->next;
            }
        }

        for(j=0; j<10; j++){
            LinkedList *trash, *temp = bucket[j];
            while(temp != NULL){
                trash = temp;
                temp = temp->next;
                free(trash);
            }
            bucket[j] = NULL;
        }
    }
}

int main(){
    int i, n;

    printf("Banyak bilangan: "); scanf("%d", &n);

    int *original = malloc(sizeof(int) * n);
    int *arr      = malloc(sizeof(int) * n);

    for(i=0; i<n; i++){
        printf("Input bilangan ke-%d: ", i+1); scanf("%d", &original[i]);
    }

    printf("\nInput  : "); printArray(original, n);
    printf("\n");

    copyArray(original, arr, n);
    bubbleSort(arr, n);
    printf("Bubble Sort    (descending): "); printArray(arr, n);

    copyArray(original, arr, n);
    selectionSort(arr, n);
    printf("Selection Sort (descending): "); printArray(arr, n);

    copyArray(original, arr, n);
    insertionSort(arr, n);
    printf("Insertion Sort (descending): "); printArray(arr, n);

    copyArray(original, arr, n);
    radixSort(arr, n);
    printf("Radix Sort     (descending): "); printArray(arr, n);

    free(original);
    free(arr);
    return 0;
}