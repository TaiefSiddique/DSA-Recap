#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    int val2;
    struct Node *next;
};

struct Node* CreateNode () {
    struct Node *current = (struct Node*) malloc (sizeof (struct Node));
    printf ("Put a value: ");
    scanf ("%d %d", &(current->value), &(current->val2));
    current->next = NULL;
    return current;
}

int main () {
    struct Node *temp = CreateNode ();
    printf ("%d %d\n", temp->value, temp->val2);
    return 0;
}





/*
struct X {
    int a;
    int *p;
};

int main () {
    struct X *x1 = (struct X*) malloc (sizeof (struct X));
    x1->a = 45;
    x1->p = (int*) malloc (sizeof (int));
    *(x1->p) = 34;
    printf ("%d %d\n", x1->a, *(x1->p));
    return 0;
}
*/
