#include <stdio.h>
#include <stdlib.h>

// Structure to represent a priority queue node
struct PriorityQueueNode
{
    int data;
    int priority;
};

// Structure to represent a priority queue
struct PriorityQueue
{
    struct PriorityQueueNode *array;
    int capacity;
    int size;
};

// Function to create a new priority queue
struct PriorityQueue *createPriorityQueue(int capacity)
{
    struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->array = (struct PriorityQueueNode *)malloc(pq->capacity * sizeof(struct PriorityQueueNode));
    return pq;
}

// Function to swap two priority queue nodes
void swap(struct PriorityQueueNode *a, struct PriorityQueueNode *b)
{
    struct PriorityQueueNode temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the priority queue
void minHeapify(struct PriorityQueue *pq, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->array[left].priority < pq->array[smallest].priority)
        smallest = left;

    if (right < pq->size && pq->array[right].priority < pq->array[smallest].priority)
        smallest = right;

    if (smallest != index)
    {
        swap(&pq->array[index], &pq->array[smallest]);
        minHeapify(pq, smallest);
    }
}

// Function to insert a new element into the priority queue
void enqueue(struct PriorityQueue *pq, int data, int priority)
{
    if (pq->size == pq->capacity)
    {
        printf("Priority queue is full\n");
        return;
    }

    // Insert the new node at the end of the heap
    int i = pq->size++;
    pq->array[i].data = data;
    pq->array[i].priority = priority;

    // Fix the min-heap property
    while (i != 0 && pq->array[(i - 1) / 2].priority > pq->array[i].priority)
    {
        swap(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the element with the highest priority from the priority queue
struct PriorityQueueNode dequeue(struct PriorityQueue *pq)
{
    if (pq->size <= 0)
    {
        printf("Priority queue is empty\n");
        struct PriorityQueueNode emptyNode;
        emptyNode.data = -1;     // Assuming -1 represents an empty node
        emptyNode.priority = -1; // Assuming -1 represents an empty node
        return emptyNode;
    }

    if (pq->size == 1)
    {
        pq->size--;
        return pq->array[0];
    }

    // Store the minimum value, and remove it from heap
    struct PriorityQueueNode root = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);

    return root;
}

// Function to get the element with the highest priority without removing it from the priority queue
struct PriorityQueueNode peek(struct PriorityQueue *pq)
{
    if (pq->size <= 0)
    {
        printf("Priority queue is empty\n");
        struct PriorityQueueNode emptyNode;
        emptyNode.data = -1;     // Assuming -1 represents an empty node
        emptyNode.priority = -1; // Assuming -1 represents an empty node
        return emptyNode;
    }
    return pq->array[0];
}

int main()
{
    struct PriorityQueue *pq = createPriorityQueue(5);

    enqueue(pq, 10, 2);
    enqueue(pq, 20, 1);
    enqueue(pq, 30, 3);
    enqueue(pq, 40, 0);

    printf("Element with highest priority: %d\n", peek(pq).data);

    printf("Dequeuing elements with priority:\n");
    while (pq->size > 0)
    {
        struct PriorityQueueNode node = dequeue(pq);
        printf("Data: %d, Priority: %d\n", node.data, node.priority);
    }

    return 0;
}
