// #ifndef UTILITY_H
// #define UTILITY_H

// #include <stdlib.h>
// #include <time.h>

// void AssignRandomValues (int A[], int s) {
//     time_t t;
//     srand (t);
//     for (int i = 0; i < s; i++)
//         A[i] = rand() % 100;
// }

// void PrintIntValues (int A[], int s) {
//     for (int i = 0; i < s; i++)
//         printf ("%d ", A[i]);
//     printf ("\n");
// }

// void Swap (int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// #endif //UTLITY_H
#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <time.h>

void AssignRandomValues(int A[], int s)
{
    time_t t;
    srand(t);
    for (int i = 0; i < s; i++)
        A[i] = rand() % 100;
}

void PrintIntValues(int A[], int s)
{
    for (int i = 0; i < s; i++)
        printf("%d ", A[i]);

    printf("\n");
}

#endif // UTLITY_H