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

struct Node* InsertFirst (struct Node* head) {
    struct Node* temp = CreateNode ();
    if (head == NULL) head = temp;
    else {
        temp->next = head;
        head = temp;
    }
    return head;
}

struct Node* InsertAny (struct Node* head) {
    struct Node* temp = CreateNode ();
    
    struct Node *curr = head;
    struct Node *prev = NULL;
    
    if (head == NULL) {
        head = temp;
    }
    else {
        int val;
        printf ("Before the val: ");
        scanf ("%d", &val);
        
        if (curr->value == val) {
            temp->next = curr;
            head = temp;
        }
        else {
            while (curr->value != val) {
                prev = curr;
                curr = curr->next;
                if (curr == NULL) break;
            }
            
            if (curr != NULL && prev != NULL) {
                temp->next = curr;
                prev->next = temp;
            }
            else printf ("Value is not found\n");
        }
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

struct Node* DeleteLast (struct Node* head) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    
    if (curr == NULL) return head;
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

struct Node* DeleteAny (struct Node* head) {   
    struct Node *curr = head;
    struct Node *prev = NULL;
    
    if (head == NULL) return head;
    else {
        int val;
        printf ("Value to erase: ");
        scanf ("%d", &val);
        
        if (curr->value == val) {
            head = head->next;
            free (curr);
            return head;
        }
        else {
            while (curr->value != val) {
                prev = curr;
                curr = curr->next;
                if (curr == NULL) break;
            }
            if (curr != NULL && prev != NULL) {
                prev->next = curr->next;
                free (curr);
            }
            else printf ("Value not found\n");
        }
        
    } 
    
    return head;
}


int main () {
    /// Insert
    struct Node *head = NULL;
    
    int selection;
    
    do {
        printf ("1: Insert 2: Delete 3: Print 4: Exit 5: InsertFirst 6: DeleteLast 7: InsertAny 8: DeleteAny : ");
        scanf ("%d", &selection);
        switch (selection) {
            case 1: head = Insert(head);
                    break;
            case 2: head = DeleteFirst (head);
                    break;
            case 3: PrintLL (head);
                    break;
            case 4: exit(1);
                    break;
            case 5: head = InsertFirst (head);
                    break;
            case 6: head = DeleteLast (head);
                    break;
            case 7: head = InsertAny (head);
                    break;
            case 8: head = DeleteAny (head);
                    break;
            default: printf ("Wrong Selection\n");
                    break;
        }
    } while (selection >= 1 && selection <= 8);
    
    
    return 0;
}
