#include <stdio.h> [cite: 44]
#include <stdlib.h> [cite: 46]

void swap(int *a, int *b){ [cite: 49]
    int temp = *a; [cite: 51]
    *a = *b; [cite: 53]
    *b = temp; [cite: 55]
}

int partition(int *bil, int l, int r){ [cite: 87]
    int pivot = bil[r]; [cite: 88]
    
    int i = l - 1; [cite: 90]
    
    for(int j = l; j <= r - 1; j++){ [cite: 91]
        if (bil[j] <= pivot) { [cite: 93]
            i++; [cite: 96]
            swap(&bil[i], &bil[j]); [cite: 98]
        }
    }
    swap(&bil[i + 1], &bil[r]); [cite: 103]
    
    return (i + 1); [cite: 107]
}

void quickSort(int *bil, int l, int r){ [cite: 120]
    if(l < r){ [cite: 121]
        int pi = partition(bil, l, r); [cite: 123]
        
        quickSort(bil, l, pi - 1); [cite: 131]
        quickSort(bil, pi + 1, r); [cite: 133]
    }
}

int main(){ [cite: 139]
    int i, n, *bil; [cite: 141]
    
    printf("Banyak bilangan: "); [cite: 144]
    scanf("%d", &n); [cite: 145]
    
    bil = (int*) malloc(sizeof(int) * n); [cite: 148]
    
    for(i = 0; i < n; i++){ [cite: 151]
        printf("Input bilangan ke-%d: ", i + 1); [cite: 157]
        scanf("%d", &bil[i]); [cite: 157]
    }
    
    quickSort(bil, 0, n - 1); [cite: 158]
    
    printf("Hasil quick sort:\n"); [cite: 161]
    for(i = 0; i < n; i++){ [cite: 162]
        printf("%d ", bil[i]); [cite: 164]
    }
    printf("\n");
    
    free(bil); [cite: 166]
    
    return 0; [cite: 169]
}