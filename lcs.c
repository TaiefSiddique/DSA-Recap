#include <stdio.h>
#include <string.h>

// Function to find the length of LCS
int lcs_length(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    // Building the LCS matrix
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    return L[m][n];
}

// Function to print LCS
void print_lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i = m, j = n;
    int index = lcs_length(X, Y, m, n);

    char lcs[index + 1];
    lcs[index] = '\0';

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the LCS
    printf("LCS of %s and %s is %s\n", X, Y, lcs);
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs_length(X, Y, m, n));
    print_lcs(X, Y, m, n);

    return 0;
}
