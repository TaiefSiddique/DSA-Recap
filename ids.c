#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILDREN 3 // Maximum number of children any node can have

typedef struct Node
{
    int id;
    struct Node *children[MAX_CHILDREN];
} Node;

Node *createNode(int id)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->id = id;
    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void addChild(Node *parent, Node *child, int index)
{
    if (index >= 0 && index < MAX_CHILDREN)
    {
        parent->children[index] = child;
    }
    else
    {
        fprintf(stderr, "Invalid child index\n");
    }
}

int depthLimitedSearch(Node *node, int goal, int limit)
{
    if (node == NULL)
        return 0;
    if (node->id == goal)
    {
        printf("Goal %d found\n", node->id);
        return 1;
    }
    if (limit <= 0)
        return 0;

    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        if (node->children[i] != NULL)
        {
            if (depthLimitedSearch(node->children[i], goal, limit - 1))
            {
                return 1;
            }
        }
    }
    return 0;
}

int iterativeDeepeningSearch(Node *root, int goal)
{
    int depth = 0;
    while (1)
    {
        printf("Trying depth %d\n", depth);
        if (depthLimitedSearch(root, goal, depth))
        {
            printf("Goal found at depth %d\n", depth);
            return 1;
        }
        depth++;
    }
    return 0;
}

int main()
{
    // Create a simple tree for demonstration: 1 -> {2, 3, 4} -> {5, 6, 7}...
    Node *root = createNode(1);
    Node *child1 = createNode(2);
    Node *child2 = createNode(3);
    Node *child3 = createNode(4);
    addChild(root, child1, 0);
    addChild(root, child2, 1);
    addChild(root, child3, 2);

    Node *grandChild1 = createNode(5);
    addChild(child1, grandChild1, 0);

    int goal = 5;
    if (!iterativeDeepeningSearch(root, goal))
    {
        printf("Goal %d not found\n", goal);
    }

    // Free memory (simple deallocation for demonstration; in real application, use a postorder traversal or similar)
    free(root);
    free(child1);
    free(child2);
    free(child3);
    free(grandChild1);

    return 0;
}
