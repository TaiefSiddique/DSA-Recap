#include <stdio.h>
#include <string.h>

// Function to find length of LCS
int lcs_length(char *X, char *Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    else if (X[m - 1] == Y[n - 1])
        return 1 + lcs_length(X, Y, m - 1, n - 1);
    else
        return max(lcs_length(X, Y, m, n - 1), lcs_length(X, Y, m - 1, n));
}

// Utility function to find maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs_length(X, Y, m, n));

    return 0;
}
