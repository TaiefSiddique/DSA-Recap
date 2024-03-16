#include <stdio.h>
#include "utility.h"

/*
#define SZ 10

void InsertionSort (int A[], int N) {
    for (int i = 1; i < N; i++) {
        int key = A[i];
        int j = i - 1;
        
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
*/

#define SZ 8

void CountSort (int A[], int N) {
    int max = A[0];
    for (int i = 1; i < N; i++) 
        if (max < A[i]) max = A[i];
    printf ("max: %d\n", max);
        
    int Count[max + 1];
    for (int i = 0; i <= max; i++) Count[i] = 0;
    PrintIntValues (Count, max + 1);
    
    for (int i = 0; i < N; i++) Count[A[i]] += 1;
    PrintIntValues (Count, max + 1);
    
    for (int i = 1; i <= max; i++) Count[i] += Count [i - 1];
    PrintIntValues (Count, max + 1);
    
    int Output [N];
    for (int i = N - 1; i >= 0; i--) {
        Output[Count[A[i]] - 1] = A[i];
        Count[A[i]] -= 1;
    } 
    PrintIntValues (Output, N);
    
    for (int i = 0; i < N; i++) A[i] = Output[i];
}

int main () {
    int A[SZ] = {3, 6, 4, 1, 3, 4, 1, 4};
    PrintIntValues (A, SZ);
    CountSort (A, SZ);
    PrintIntValues (A, SZ);
    
    //InsertionSort (A, SZ);
    //PrintIntValues (A, SZ);
    return 0;
}
