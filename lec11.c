/*
#include <stdio.h>
#include "utility.h"

#define SIZE 50

void Push (int A[], int *top, int sz, int item) {
    if (*top == SIZE) {
        printf ("Overflow\n");
        return;
    }
    else {
        A[*top] = item;
        *top += 1;
    }
}

int Pop (int A[], int *top) {
    if (*top == 0) {
        printf ("Underflow\n");
    }
    else {
        *top -= 1;
        return A[*top];
    }
}


int main () {
    int A[SIZE], top = 0;
    Push (A, &top, SIZE, 67);
    Push (A, &top, SIZE, 45);
    Push (A, &top, SIZE, 23);
    PrintIntValues (A, top);
    Pop (A, &top);
    PrintIntValues (A, top);
    Pop (A, &top);
    PrintIntValues (A, top);
    return 0;
}
*/
