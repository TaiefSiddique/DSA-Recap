#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct MinHeap
{
    int *array;
    int capacity;
    int size;
};

struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (int *)malloc(minHeap->capacity * sizeof(int));
    return minHeap;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(struct MinHeap *minHeap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest])
        smallest = left;

    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&minHeap->array[index], &minHeap->array[smallest]);
        heapify(minHeap, smallest);
    }
}

void insert(struct MinHeap *minHeap, int value)
{
    if (minHeap->size == minHeap->capacity)
    {
        printf("Heap is full. Cannot insert any more elements.\n");
        return;
    }

    int index = minHeap->size++;
    minHeap->array[index] = value;

    while (index != 0 && minHeap->array[index] < minHeap->array[(index - 1) / 2])
    {
        swap(&minHeap->array[index], &minHeap->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int extractMin(struct MinHeap *minHeap)
{
    if (minHeap->size <= 0)
        return -1; // Signifies heap is empty

    if (minHeap->size == 1)
    {
        minHeap->size--;
        return minHeap->array[0];
    }

    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    heapify(minHeap, 0);

    return root;
}

void printMinHeap(struct MinHeap *minHeap)
{
    printf("Heap: ");
    for (int i = 0; i < minHeap->size; i++)
    {
        printf("%d ", minHeap->array[i]);
    }
    printf("\n");
}

int main()
{
    struct MinHeap *minHeap = createMinHeap(MAX_HEAP_SIZE);

    insert(minHeap, 3);
    insert(minHeap, 2);
    insert(minHeap, 1);
    insert(minHeap, 15);
    insert(minHeap, 5);
    insert(minHeap, 4);
    insert(minHeap, 45);

    printf("Extracted min: %d\n", extractMin(minHeap));
    printMinHeap(minHeap);

    return 0;
}
