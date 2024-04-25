#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOL_LEN 100

// Define a struct for the Lisp atom
typedef struct
{
    enum
    {
        ATOM_INT,
        ATOM_SYM
    } type;
    union
    {
        int intval;
        char symval[MAX_SYMBOL_LEN];
    };
} Atom;

// Define a struct for the Lisp expression
typedef struct ListNode
{
    Atom atom;
    struct ListNode *next;
} ListNode;

// Function to create an integer atom
Atom make_int(int value)
{
    Atom atom;
    atom.type = ATOM_INT;
    atom.intval = value;
    return atom;
}

// Function to create a symbol atom
Atom make_sym(const char *symbol)
{
    Atom atom;
    atom.type = ATOM_SYM;
    strncpy(atom.symval, symbol, MAX_SYMBOL_LEN - 1);
    atom.symval[MAX_SYMBOL_LEN - 1] = '\0'; // Ensure null-termination
    return atom;
}

// Function to create a new list node
ListNode *cons(Atom atom, ListNode *next)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (node == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }
    node->atom = atom;
    node->next = next;
    return node;
}

// Function to print an atom
void print_atom(Atom atom)
{
    switch (atom.type)
    {
    case ATOM_INT:
        printf("%d", atom.intval);
        break;
    case ATOM_SYM:
        printf("%s", atom.symval);
        break;
    default:
        fprintf(stderr, "Unknown atom type\n");
        exit(EXIT_FAILURE);
    }
}

// Function to print a Lisp expression
void print_list(ListNode *list)
{
    printf("(");
    while (list != NULL)
    {
        print_atom(list->atom);
        if (list->next != NULL)
            printf(" ");
        list = list->next;
    }
    printf(")\n");
}

// Function to free a Lisp expression
void free_list(ListNode *list)
{
    while (list != NULL)
    {
        ListNode *temp = list;
        list = list->next;
        free(temp);
    }
}

int main()
{
    // Example usage
    ListNode *list = cons(make_sym("print"), cons(make_int(42), NULL));
    print_list(list);
    free_list(list);
    return 0;
}
