#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <limits.h>

typedef struct MinHeap {
    int *hArr;
    int capacity;
    int heapSize;
} MinHeap;

// --- FUNGSI DASAR DARI TUTORIAL 1.1 ---

MinHeap createHeap(int cap) {
    MinHeap newHeap;
    newHeap.heapSize = 0;
    newHeap.capacity = cap;
    newHeap.hArr = (int*) malloc(sizeof(int) * cap);
    for (int i = 0; i < cap; i++) newHeap.hArr[i] = 0;
    return newHeap;
}

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return (2 * i + 1); }
int right(int i) { return (2 * i + 2); }

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MinHeapify(MinHeap *mHeap, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < mHeap->heapSize && mHeap->hArr[l] < mHeap->hArr[i]) 
        smallest = l;
    if (r < mHeap->heapSize && mHeap->hArr[r] < mHeap->hArr[smallest]) 
        smallest = r;

    if (smallest != i) {
        swap(&mHeap->hArr[i], &mHeap->hArr[smallest]);
        MinHeapify(mHeap, smallest);
    }
}

void insertKey(MinHeap *mHeap, int k) {
    if (mHeap->heapSize == mHeap->capacity) {
        printf("\nOverflow: Could not insertKey\n");
        return;
    }
    mHeap->heapSize++;
    int i = mHeap->heapSize - 1;
    mHeap->hArr[i] = k;

    while (i != 0 && mHeap->hArr[parent(i)] > mHeap->hArr[i]) {
        swap(&mHeap->hArr[i], &mHeap->hArr[parent(i)]);
        i = parent(i);
    }
}

int getMin(MinHeap *mHeap) {
    return mHeap->hArr[0];
}

void printHeap(MinHeap mHeap) {
    printf("Current heap: ");
    for (int i = 0; i < mHeap.heapSize; i++) {
        printf("%d ", mHeap.hArr[i]);
    }
    printf("\n");
}

// --- TAMBAHAN FUNGSI UNTUK TUTORIAL 1.2 (DELETION) ---

int extractMin(MinHeap *mHeap) {
    if (mHeap->heapSize <= 0) return INT_MAX;
    if (mHeap->heapSize == 1) {
        mHeap->heapSize--;
        return mHeap->hArr[0];
    }

    // Simpan nilai root, ganti dengan elemen terakhir, lalu heapify down
    int root = mHeap->hArr[0];
    mHeap->hArr[0] = mHeap->hArr[mHeap->heapSize - 1];
    mHeap->heapSize--;
    MinHeapify(mHeap, 0);

    return root;
}

void decreaseKey(MinHeap *mHeap, int i, int newValue) {
    mHeap->hArr[i] = newValue;
    // Bubble up nilai yang baru saja diperkecil
    while (i != 0 && mHeap->hArr[parent(i)] > mHeap->hArr[i]) {
        swap(&mHeap->hArr[i], &mHeap->hArr[parent(i)]);
        i = parent(i);
    }
}

void deleteKey(MinHeap *mHeap, int i) {
    printf("Current Heap Size %d\n", mHeap->heapSize);
    printf("Deleting index %d from heap\n", i);
    // Ubah nilai di index i menjadi sangat kecil, lalu tarik ke root, baru diextract
    decreaseKey(mHeap, i, INT_MIN);
    extractMin(mHeap);
}

// --- MAIN FUNCTION ---

int main() {
    MinHeap mHeap = createHeap(11);

    insertKey(&mHeap, 3);
    insertKey(&mHeap, 2);
    // Contoh pemanggilan deleteKey sesuai alur di modul
    deleteKey(&mHeap, 1); 
    printHeap(mHeap);

    insertKey(&mHeap, 15);
    insertKey(&mHeap, 5);
    insertKey(&mHeap, 4);
    insertKey(&mHeap, 45);
    printHeap(mHeap);

    printf("Min Value in Heap: %d \n", getMin(&mHeap));

    extractMin(&mHeap);
    printHeap(mHeap);

    deleteKey(&mHeap, 1);
    printHeap(mHeap);

    return 0;
}