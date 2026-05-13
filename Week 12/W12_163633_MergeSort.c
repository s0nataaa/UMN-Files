#include <stdio.h>
#include <stdlib.h>

void merge(int *bil, int l, int m, int r);

void mergeSort(int *bil, int l, int r){
    if (l < r) {
        int m = (l + r) / 2; [cite: 187, 188]
        
        mergeSort(bil, l, m); [cite: 189]
        mergeSort(bil, m + 1, r); [cite: 190]
        
        merge(bil, l, m, r); [cite: 191]
    }
}

void merge(int *bil, int l, int m, int r){
    int i, j, k;
    
    int n1 = m - l + 1; [cite: 231]
    int n2 = r - m; [cite: 233]
    
    int L[n1]; [cite: 234]
    int R[n2]; [cite: 235]
    
    for(i = 0; i < n1; i++)
        L[i] = bil[l + i]; [cite: 237, 238]
        
    for(j = 0; j < n2; j++)
        R[j] = bil[m + 1 + j]; [cite: 240, 241]
        
    i = 0; 
    j = 0; 
    k = l; /
    
    while(i < n1 && j < n2){ [cite: 247, 248]
        if(L[i] <= R[j]){ [cite: 249]
            bil[k] = L[i]; [cite: 250]
            i++; [cite: 251]
        } else {
            bil[k] = R[j]; [cite: 253]
            j++; [cite: 254]
        }
        k++;
    }
    
    while(i < n1){ [cite: 260]
        bil[k] = L[i]; [cite: 261]
        i++;
        k++;
    }
    
    while(j < n2){ [cite: 269]
        bil[k] = R[j]; [cite: 271]
        j++;
        k++;
    }
}

int main(){
    int *bil, i, n;
    
    printf("Banyak bilangan: "); [cite: 209]
    scanf("%d", &n);
    
    bil = (int*) malloc(sizeof(int) * n); [cite: 210]
    
    for(i = 0; i < n; i++) {
        printf("Input bilangan ke-%d: ", i + 1); [cite: 212]
        scanf("%d", &bil[i]);
    }
    
    mergeSort(bil, 0, n - 1); [cite: 213]
    
    printf("Hasil merge sort:\n"); [cite: 214]
    for(i = 0; i < n; i++){
        printf("%d ", bil[i]); [cite: 216, 218]
    }
    printf("\n");
    
    free(bil); [cite: 223]
    return 0; [cite: 224]
}