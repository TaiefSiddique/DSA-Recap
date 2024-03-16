#include <stdio.h>
#include "utility.h"

#define SZ 10

/*
void BubbleSort (int Arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i -  1; j++) {
            if (Arr[j] > Arr[j+1]) {
                int temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}
*/

/*
void SelectionSort1 (int Arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (Arr[i] > Arr[j]) 
                Swap (&Arr[i], &Arr[j]);
        }
    }
}
*/

void SelectionSort2 (int Arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (Arr[j] < Arr[min_idx]) min_idx = j;
        }
        if (min_idx != i) Swap (&Arr[i], &Arr[min_idx]);
    }
}


int main () {
    int Arr[SZ];
    AssignRandomValues (Arr, SZ);
    PrintIntValues (Arr, SZ);
    //BubbleSort (Arr, SZ);
    SelectionSort2 (Arr, SZ);
    PrintIntValues (Arr, SZ);
    return 0;
}

