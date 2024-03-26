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

struct Node* Push (struct Node* head) {
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

struct Node* Pop (struct Node* head) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    
    if (curr == NULL) {
        printf ("Underflow\n");
        return head;
    }
    else if (curr->next == NULL) {
        head = NULL;
        free (curr);
        return head;
    } 
    else {
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        free(curr);
    }
    return head;
}


void PrintStack (struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf ("%d ", temp->value);
        temp = temp->next;
    }
    printf ("\n");
}


int main () {
    /// Insert
    struct Node *head = NULL;
    
    head = Push (head);
    head = Push (head);
    head = Push (head);
    PrintStack (head);
    head = Pop (head);
    PrintStack (head);
    head = Pop (head);
    PrintStack (head);
    
    return 0;
}
