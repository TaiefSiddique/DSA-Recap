#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *CreateNode()
{
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));
    printf("Put a value: ");
    scanf("%d", &(current->value));
    current->next = NULL;
    return current;
}

struct Node *Enqueue(struct Node *front)
{
    struct Node *temp = CreateNode();
    if (front == NULL)
    {
        front = temp;
    }
    else
    {
        struct Node *p = front;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return front;
}

struct Node *Dequeue(struct Node *front)
{
    if (front == NULL)
    {
        printf("Underflow\n");
        return front;
    }
    else
    {
        struct Node *temp = front;
        front = front->next;
        free(temp);
    }
    return front;
}

void PrintQueue(struct Node *front)
{
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *front = NULL;

    front = Enqueue(front);
    front = Enqueue(front);
    front = Enqueue(front);
    PrintQueue(front);
    front = Dequeue(front);
    PrintQueue(front);
    front = Dequeue(front);
    PrintQueue(front);

    return 0;
}
