#include <stdio.h>
#include "utility.h"

#define SZ 10

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

int main () {
    int Arr[SZ], N = 7;
    
    AssignRandomValues (Arr, N);
    PrintIntValues (Arr, N);
    
    N = Insert (Arr, N, 3, 67);
    PrintIntValues (Arr, N);
    
    N = Insert (Arr, N, 0, 7);
    PrintIntValues (Arr, N);
    
    return 0;
}
