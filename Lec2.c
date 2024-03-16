#include <stdio.h>
#include "utility.h"

#define SZ 10

/*
int Insert (int A[], int N, int k, int ele) {
    int J = N;
    N++;
    while (J >= k) {
        A[J+1] = A[J];
        J--;
    }
    A[k] = ele;
    return N;
}

int Delete (int A[], int N, int k) {
    int J = k;
    
    while (J < N) {
        A[J] = A[J + 1];
        J = J + 1;
    }
    N = N -1;
    return N;
}


int main () {
    int Arr[SZ], N = 7, k = 2;
    AssignRandomValues (Arr, N);
    PrintIntValues (Arr, N);
    
    N = Insert (Arr, N, 3, 67);
    PrintIntValues (Arr, N);
    
    N = Insert (Arr, N, 0, 7);
    PrintIntValues (Arr, N);

    
    N = Delete (Arr, N, k);
    PrintIntValues (Arr, N);
    
    k = 3;
    N = Delete (Arr, N, k);
    PrintIntValues (Arr, N);
    
    return 0;
}
*/


int Search (int A[], int N, int data) {
    int i = 0;
    while (i < N) {
        if (A[i] == data)
            return i;
        i++;
    }
    return -1;
}


int main () {
    int Arr[SZ] = {45, 67, 34, 23, 98, 4};
    int N = 6;
    int value = 34;
    if (Search (Arr, N, value) >= 0) printf ("Item found\n");
    else printf ("Item not found\n");
    return 0;
}
