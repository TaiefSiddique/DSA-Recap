#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 99999
#define MAX_NODES 100

// Structure to represent a node in the graph
typedef struct Node
{
    int index;
    int heuristic; // Heuristic value
} Node;

// Structure to represent an edge in the graph
typedef struct Edge
{
    int src, dest, weight;
} Edge;

// Structure to represent the graph
typedef struct Graph
{
    int V, E;
    Edge *edges;
} Graph;

// Function to create a new graph
Graph *createGraph(int V, int E)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge *)malloc(E * sizeof(Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest, int weight)
{
    graph->edges[graph->E].src = src;
    graph->edges[graph->E].dest = dest;
    graph->edges[graph->E].weight = weight;
    graph->E++;
}

// Function to perform greedy best-first search
void greedyBestFirstSearch(Graph *graph, int start, int goal)
{
    bool visited[MAX_NODES] = {false}; // Mark all nodes as not visited
    Node queue[MAX_NODES];             // Priority queue to store nodes based on heuristic value
    int front = -1, rear = -1;         // Front and rear pointers for the queue

    // Enqueue the start node
    visited[start] = true;
    rear++;
    queue[rear] = (Node){start, 0}; // Heuristic value for start node is assumed to be 0

    while (front != rear)
    {
        // Dequeue a node from the priority queue
        front++;
        Node currentNode = queue[front];
        printf("Visiting node %d\n", currentNode.index);

        // If the goal node is found, terminate the search
        if (currentNode.index == goal)
        {
            printf("Goal node %d found!\n", goal);
            return;
        }

        // Explore adjacent nodes
        for (int i = 0; i < graph->E; i++)
        {
            Edge edge = graph->edges[i];
            if (edge.src == currentNode.index && !visited[edge.dest])
            {
                visited[edge.dest] = true;
                rear++;
                queue[rear] = (Node){edge.dest, edge.weight}; // Heuristic value for greedy best-first search
            }
        }

        // Sort the queue based on heuristic value (simple insertion sort for demonstration)
        for (int i = front + 1; i <= rear; i++)
        {
            int j = i - 1;
            Node temp = queue[i];
            while (j >= 0 && queue[j].heuristic > temp.heuristic)
            {
                queue[j + 1] = queue[j];
                j--;
            }
            queue[j + 1] = temp;
        }
    }

    printf("Goal node %d not reachable from node %d\n", goal, start);
}

int main()
{
    int V = 5; // Number of nodes
    int E = 7; // Number of edges

    // Create a graph
    Graph *graph = createGraph(V, E);

    // Add edges
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 4, 4);
    addEdge(graph, 3, 4, 8);

    int startNode = 0;
    int goalNode = 4;

    printf("Starting Greedy Best-First Search from node %d to node %d\n", startNode, goalNode);
    greedyBestFirstSearch(graph, startNode, goalNode);

    return 0;
}
