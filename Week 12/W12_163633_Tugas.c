#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_desc(int arr[], int beg, int mid, int end) {
    int i = beg, j = mid + 1, index = 0;
    int *temp = (int *)malloc((end - beg + 1) * sizeof(int));

    while (i <= mid && j <= end) {
        if (arr[i] > arr[j])  
            temp[index++] = arr[i++];
        else
            temp[index++] = arr[j++];
    }
    while (j <= end) temp[index++] = arr[j++];
    while (i <= mid) temp[index++] = arr[i++];

    for (int k = 0; k < index; k++)
        arr[beg + k] = temp[k];

    free(temp);
}

void merge_sort_desc(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        merge_sort_desc(arr, beg, mid);
        merge_sort_desc(arr, mid + 1, end);
        merge_desc(arr, beg, mid, end);
    }
}

int partition_desc(int arr[], int beg, int end) {
    int left = beg, right = end, loc = beg, flag = 0;

    while (flag == 0) {
        while (arr[loc] >= arr[right] && loc != right)
            right--;
        if (loc == right) {
            flag = 1;
        } else if (arr[loc] < arr[right]) {
            int tmp = arr[loc]; arr[loc] = arr[right]; arr[right] = tmp;
            loc = right;
        }

        if (flag == 0) {
            while (arr[loc] <= arr[left] && loc != left)
                left++;
            if (loc == left) {
                flag = 1;
            } else if (arr[loc] > arr[left]) {
                int tmp = arr[loc]; arr[loc] = arr[left]; arr[left] = tmp;
                loc = left;
            }
        }
    }
    return loc;
}

void quick_sort_desc(int arr[], int beg, int end) {
    if (beg < end) {
        int loc = partition_desc(arr, beg, end);
        quick_sort_desc(arr, beg, loc - 1);
        quick_sort_desc(arr, loc + 1, end);
    }
}

void shell_sort_desc(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] < temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void heapify_min(int arr[], int n, int i) {
    int smallest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int tmp = arr[i]; arr[i] = arr[smallest]; arr[smallest] = tmp;
        heapify_min(arr, n, smallest);
    }
}

void heap_sort_desc(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_min(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int tmp = arr[0]; arr[0] = arr[i]; arr[i] = tmp;
        heapify_min(arr, i, 0);
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
}

void copy_array(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

int main() {
    int n;
    printf("Banyak bilangan: ");
    scanf("%d", &n);

    int *original = (int *)malloc(n * sizeof(int));
    int *arr      = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Input bilangan ke-%d: ", i+1);
        scanf("%d", &original[i]);
    }

    // Merge Sort
    copy_array(original, arr, n);
    merge_sort_desc(arr, 0, n - 1);
    printf("\nMerge Sort (Descending)  : ");
    print_array(arr, n);

    // Quick Sort
    copy_array(original, arr, n);
    quick_sort_desc(arr, 0, n - 1);
    printf("Quick Sort (Descending)  : ");
    print_array(arr, n);

    // Shell Sort
    copy_array(original, arr, n);
    shell_sort_desc(arr, n);
    printf("Shell Sort (Descending)  : ");
    print_array(arr, n);

    // Heap Sort
    copy_array(original, arr, n);
    heap_sort_desc(arr, n);
    printf("Heap Sort (Descending)   : ");
    print_array(arr, n);

    free(original);
    free(arr);
    return 0;
}