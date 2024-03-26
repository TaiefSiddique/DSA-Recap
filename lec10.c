#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node {
    int value;
    struct Node *next;
    struct Node *prv;
};

struct Node* CreateNode () {
    struct Node *current = (struct Node*) malloc (sizeof (struct Node));
    printf ("Put a value: ");
    scanf ("%d", &(current->value));
    current->next = NULL;
    current->prv = NULL;
    return current;
}

struct Node* Insert () {
    struct Node* temp = CreateNode ();
    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        temp->prv = tail;
        tail = temp;
    }
    return head;
}

struct Node* InsertFirst () {
    struct Node* temp = CreateNode ();
    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        head->prv = temp;
        temp->next = head;
        head = temp;
    }
    return head;
} 

void PrintForward () {
    struct Node *temp = head;
    while (temp != NULL) {
        printf ("%d ", temp->value);
        temp = temp->next;
    }
    printf ("\n");
}

void PrintBackward () {
    struct Node *temp = tail;
    while (temp != NULL) {
        printf ("%d ", temp->value);
        temp = temp->prv;
    }
    printf ("\n");
}

struct Node* DeleteFirst () {
    head = head->next;
    head->prv = NULL;
    return head;
}

struct Node* DeleteLast () {
    if (tail == NULL) return head;
    else if (head == tail) {
        free (head);
        head = NULL;
        tail = NULL;
    }
    else {
        (tail->prv)->next = NULL;
        struct Node* p = tail;
        tail = tail->prv;
        free (p);
    }
    return head;
}

int main () {
    
    int selection;
    
    do {
        printf ("1: Insert 2: Delete 3: PrintForward 4: PrintBackward 5: Exit 6: InsertFirst 7: DeleteLast : ");
        scanf ("%d", &selection);
        switch (selection) {
            case 1: head = Insert();
                    break;
            case 2: head = DeleteFirst ();
                    break;
            case 3: PrintForward ();
                    break;
            case 4: PrintBackward ();
                    break;
            case 5: exit(1);
                    break;
            case 6: InsertFirst ();
                    break;
            case 7: DeleteLast ();
                    break;
            default: printf ("Wrong Selection\n");
                    break;
        }
    } while (selection >= 1 && selection <= 7);
    
    
    return 0;
}
