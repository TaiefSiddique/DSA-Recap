#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define INFINITY INT_MAX

// Structure to represent a graph node
struct Node
{
    int vertex;
    int cost;
    struct Node *next;
};

// Structure to represent a priority queue node
struct PriorityQueueNode
{
    int vertex;
    int cost;
};

// Structure to represent a priority queue
struct PriorityQueue
{
    int size;
    int capacity;
    struct PriorityQueueNode *array;
};

// Function to create a new graph node
struct Node *createNode(int vertex, int cost)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->cost = cost;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new priority queue node
struct PriorityQueueNode *createPriorityQueueNode(int vertex, int cost)
{
    struct PriorityQueueNode *newNode = (struct PriorityQueueNode *)malloc(sizeof(struct PriorityQueueNode));
    newNode->vertex = vertex;
    newNode->cost = cost;
    return newNode;
}

// Function to create a priority queue
struct PriorityQueue *createPriorityQueue(int capacity)
{
    struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->array = (struct PriorityQueueNode *)malloc(capacity * sizeof(struct PriorityQueueNode));
    return pq;
}

// Function to swap two priority queue nodes
void swapPriorityQueueNodes(struct PriorityQueueNode *a, struct PriorityQueueNode *b)
{
    struct PriorityQueueNode temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i
void minHeapify(struct PriorityQueue *pq, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->array[left].cost < pq->array[smallest].cost)
        smallest = left;

    if (right < pq->size && pq->array[right].cost < pq->array[smallest].cost)
        smallest = right;

    if (smallest != i)
    {
        swapPriorityQueueNodes(&pq->array[i], &pq->array[smallest]);
        minHeapify(pq, smallest);
    }
}

// Function to extract minimum node from priority queue
struct PriorityQueueNode *extractMin(struct PriorityQueue *pq)
{
    if (pq->size == 0)
        return NULL;

    struct PriorityQueueNode *minNode = pq->array;
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);

    return minNode;
}

// Function to decrease the cost of a vertex in priority queue
void decreaseKey(struct PriorityQueue *pq, int vertex, int cost)
{
    int i;
    for (i = 0; i < pq->size; i++)
    {
        if (pq->array[i].vertex == vertex)
        {
            pq->array[i].cost = cost;
            break;
        }
    }

    // Heapify the updated node
    while (i && pq->array[(i - 1) / 2].cost > pq->array[i].cost)
    {
        swapPriorityQueueNodes(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to check if a vertex is in priority queue
int isInPriorityQueue(struct PriorityQueue *pq, int vertex)
{
    for (int i = 0; i < pq->size; i++)
    {
        if (pq->array[i].vertex == vertex)
            return 1;
    }
    return 0;
}

// Function to implement Uniform Cost Search
void uniformCostSearch(struct Node **graph, int source, int target, int numNodes)
{
    // Create a priority queue
    struct PriorityQueue *pq = createPriorityQueue(MAX_NODES);

    // Array to keep track of visited nodes
    int *visited = (int *)calloc(numNodes, sizeof(int));

    // Array to keep track of the cost to reach each node
    int *cost = (int *)malloc(numNodes * sizeof(int));
    for (int i = 0; i < numNodes; i++)
        cost[i] = INFINITY;

    // Enqueue the source node
    cost[source] = 0;
    pq->array[pq->size++] = *createPriorityQueueNode(source, 0);

    // Uniform Cost Search
    while (pq->size != 0)
    {
        // Extract the minimum node from priority queue
        struct PriorityQueueNode *minNode = extractMin(pq);
        int u = minNode->vertex;
        free(minNode);

        // Mark the current node as visited
        visited[u] = 1;

        // Traverse adjacent nodes of the current node
        struct Node *temp = graph[u];
        while (temp != NULL)
        {
            int v = temp->vertex;
            int costUV = temp->cost;

            // Update cost[v] if it is not visited and cost[u] + cost(u,v) is smaller than current value of cost[v]
            if (!visited[v] && cost[u] != INFINITY && cost[u] + costUV < cost[v])
            {
                cost[v] = cost[u] + costUV;
                // Add vertex v to the priority queue if not already present
                if (!isInPriorityQueue(pq, v))
                {
                    pq->array[pq->size++] = *createPriorityQueueNode(v, cost[v]);
                }
                else
                {
                    // Update the cost of vertex v in priority queue
                    decreaseKey(pq, v, cost[v]);
                }
            }
            temp = temp->next;
        }
    }

    // Print the shortest path cost from source to target
    printf("Shortest path cost from node %d to node %d is: %d\n", source, target, cost[target]);

    // Free allocated memory
    free(pq->array);
    free(pq);
    free(visited);
    free(cost);
}

// Function to add an edge to the graph
void addEdge(struct Node *graph[], int u, int v, int cost)
{
    // Add edge from u to v
    struct Node *newNode = createNode(v, cost);
    newNode->next = graph[u];
    graph[u] = newNode;

    // Add edge from v to u (for undirected graph)
    newNode = createNode(u, cost);
    newNode->next = graph[v];
    graph[v] = newNode;
}

int main()
{
    int numNodes = 6;
    struct Node *graph[MAX_NODES] = {NULL};

    // Add edges to the graph
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 1, 4, 4);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 5, 8);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 1);

    // Perform Uniform Cost Search
    uniformCostSearch(graph, 0, 5, numNodes);

    return 0;
}
