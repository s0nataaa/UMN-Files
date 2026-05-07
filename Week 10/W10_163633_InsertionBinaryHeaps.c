#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <limits.h> // Diperlukan untuk INT_MIN dan INT_MAX

typedef struct MinHeap {
    int *hArr;
    int capacity;
    int heapSize;
} MinHeap;

// Function untuk membuat heap baru
MinHeap createHeap(int cap) {
    MinHeap newHeap;
    newHeap.heapSize = 0;
    newHeap.capacity = cap;
    newHeap.hArr = (int*) malloc(sizeof(int) * cap);
    
    for (int i = 0; i < cap; i++) {
        newHeap.hArr[i] = 0;
    }
    
    return newHeap;
}

// Function untuk mencari index parent
int parent(int i) { 
    return (i - 1) / 2; 
}

// Function untuk mencari index anak kiri
int left(int i) { 
    return (2 * i + 1); 
}

// Function untuk mencari index anak kanan
int right(int i) { 
    return (2 * i + 2); 
}

// Function untuk menukar 2 buah angka
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Menyeimbangkan kembali heap dari atas ke bawah
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

// Function untuk memasukkan angka baru ke heap
void insertKey(MinHeap *mHeap, int k) {
    printf("Inserting %d to heap\n", k);
    printf("Current Heap Size = %d\n", mHeap->heapSize);

    if (mHeap->heapSize == mHeap->capacity) {
        printf("\nOverflow: Could not insertKey\n");
        return;
    }

    // Pertama-tama, masukkan angka ke dalam index terakhir
    mHeap->heapSize++;
    int i = mHeap->heapSize - 1;
    mHeap->hArr[i] = k;

    // Memperbaiki properti min heap (bawa ke atas jika lebih kecil dari parent)
    while (i != 0 && mHeap->hArr[parent(i)] > mHeap->hArr[i]) {
        swap(&mHeap->hArr[i], &mHeap->hArr[parent(i)]);
        i = parent(i);
    }
}

// Mengambil nilai terkecil (root)
int getMin(MinHeap *mHeap) {
    return mHeap->hArr[0];
}

// Mencetak seluruh isi heap
void printHeap(MinHeap mHeap) {
    printf("Current heap: ");
    for (int i = 0; i < mHeap.heapSize; i++) {
        printf("%d ", mHeap.hArr[i]);
    }
    printf("\n");
}

int main() {
    MinHeap mHeap;

    // Membuat heap dengan kapasitas 11
    mHeap = createHeap(11);

    printHeap(mHeap);
    insertKey(&mHeap, 3);
    printHeap(mHeap);
    insertKey(&mHeap, 2);
    printHeap(mHeap);
    
    // Sesuai alur di main modul
    insertKey(&mHeap, 15);
    printHeap(mHeap);
    insertKey(&mHeap, 5);
    printHeap(mHeap);
    insertKey(&mHeap, 4);
    printHeap(mHeap);
    insertKey(&mHeap, 45);
    printHeap(mHeap);

    printf("Min Value in Heap: %d \n", getMin(&mHeap));

    return 0;
}