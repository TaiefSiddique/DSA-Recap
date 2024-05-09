#include <stdio.h>
#include <malloc.h>

// Node structure for the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Deque structure
typedef struct Deque
{
    Node *front;
    Node *rear;
    int size;
} Deque;

// Function to create a new deque
Deque *createDeque()
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->front = deque->rear = NULL;
    deque->size = 0;
    return deque;
}

// Check if the deque is empty
int isEmpty(Deque *deque)
{
    return deque->size == 0;
}

// Insert an element at the front of the deque
void insertFront(Deque *deque, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = deque->front;
    deque->front = newNode;

    // If deque was empty, update rear as well
    if (deque->rear == NULL)
    {
        deque->rear = newNode;
    }
    deque->size++;
}

// Insert an element at the rear of the deque
void insertRear(Deque *deque, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // If deque was empty, update front as well
    if (deque->rear == NULL)
    {
        deque->front = newNode;
    }
    else
    {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
    deque->size++;
}

// Delete an element from the front of the deque
int deleteFront(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty\n");
        return -1;
    }

    Node *temp = deque->front;
    int data = temp->data;
    deque->front = deque->front->next;

    // If deque becomes empty, update rear as well
    if (deque->front == NULL)
    {
        deque->rear = NULL;
    }
    free(temp);
    deque->size--;
    return data;
}

// Delete an element from the rear of the deque
int deleteRear(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty\n");
        return -1;
    }

    Node *temp = deque->rear;
    int data = temp->data;

    // If deque has only one element
    if (deque->front == deque->rear)
    {
        deque->front = deque->rear = NULL;
    }
    else
    {
        // Find the node before the rear
        Node *current = deque->front;
        while (current->next != deque->rear)
        {
            current = current->next;
        }
        current->next = NULL;
        deque->rear = current;
    }
    free(temp);
    deque->size--;
    return data;
}

// Get the front element of the deque
int getFront(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->front->data;
}

// Get the rear element of the deque
int getRear(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty\n");
        return -1;
    }
    return deque->rear->data;
}

// Print the contents of the deque
void printDeque(Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty\n");
        return;
    }

    Node *temp = deque->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Deque *deque = createDeque();

    insertFront(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);

    printf("Deque elements: ");
    printDeque(deque);

    printf("Deleted element from front: %d\n", deleteFront(deque));
}