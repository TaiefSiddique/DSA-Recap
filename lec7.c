#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node* CreateNode () {
    struct Node *current = (struct Node*) malloc (sizeof (struct Node));
    printf ("Put a value: ");
    scanf ("%d", &(current->value));
    current->next = NULL;
    return current;
}

struct Node* Insert (struct Node* head) {
    struct Node* temp = CreateNode ();
    if (head == NULL) head = temp;
    else {
        struct Node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

void PrintLL (struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf ("%d ", temp->value);
        temp = temp->next;
    }
    printf ("\n");
}

struct Node* DeleteFirst (struct Node* head) {
    head = head->next;
    return head;
}


int main () {
    /// Insert
    struct Node *head = NULL;
    
    int selection;
    
    do {
        printf ("1: Insert 2: Delete 3: Print 4: Exit : ");
        scanf ("%d", &selection);
        switch (selection) {
            case 1: head = Insert(head);
                    break;
            /*
            case 2: head = Delete (head);
                    break;
            */
            case 3: PrintLL (head);
                    break;
            case 4: exit(1);
            default: printf ("Wrong Selection\n");
                    break;
        }
    } while (selection <= 4);
    
    
    return 0;
}
