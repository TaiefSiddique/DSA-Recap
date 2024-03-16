#include <stdio.h>
#include "utility.h"

/*
#define SZ 10

int BinarySearch (int Arr[], int N, int Item) {
    int l = 0, r = N -1;
    
    while (l <= r) {
        int mid = (l + r) / 2;
        if (Item == Arr[mid]) return mid;
        else if (Item < Arr[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main () {
    int Arr[SZ] = {5, 9, 17, 23, 25, 45, 59, 63, 71, 89};
    PrintIntValues (Arr, SZ);
    
    int index = BinarySearch (Arr, SZ, 41);
    if (index >= 0) printf ("Index is %d\n", index);
    else printf ("Item does not exist\n");
    
    return 0;
}
*/

void MatrixMultiplication (int A[][3], int B[][3], int C[][3], int r1, int r2, int c1, int c2) {
    if (c1 != r2) return;
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;
            for (int k = 0; k < r1; k++) {
                sum = sum + A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        } 
    }
    
}

int main () {
    int A[3][3] = {1, 5, 6,
                   2, 2, 5,
                   1, 7, 5};
    int B[3][3] = {1, 2, 3,
                   0, 1, 5,
                   1, 0, 2};
    int C[3][3];
    
    MatrixMultiplication (A, B, C, 3, 3, 3, 3);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
            printf ("%d ", C[i][j]);
        printf ("\n");
    }
        
    
    return 0;
}



