#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

// Structure to represent a node in the grid
typedef struct Node
{
    int row, col;        // Coordinates of the node
    int f, g, h;         // f = g + h
    struct Node *parent; // Parent node to reconstruct the path
    bool obstacle;       // Flag to indicate if the node is an obstacle
} Node;

// Function to calculate Manhattan distance heuristic
int calculateH(int row, int col, int goalRow, int goalCol)
{
    return abs(goalRow - row) + abs(goalCol - col);
}

// Function to check if a cell is valid (inside grid boundaries)
bool isValid(int row, int col)
{
    return (row >= 0) && (row < ROWS) &&
           (col >= 0) && (col < COLS);
}

// Function to check if a cell is blocked (contains an obstacle)
bool isBlocked(int grid[ROWS][COLS], int row, int col)
{
    return grid[row][col] == 1; // Assuming 1 represents an obstacle
}

// Function to check if a cell is the goal cell
bool isGoal(int row, int col, int goalRow, int goalCol)
{
    return row == goalRow && col == goalCol;
}

// Function to perform A* search
void aStarSearch(int grid[ROWS][COLS], int startRow, int startCol, int goalRow, int goalCol)
{
    // Arrays for tracking visited nodes and their properties
    Node *openList[ROWS * COLS]; // Open list of nodes to explore
    bool closedList[ROWS][COLS]; // Closed list of explored nodes

    // Initialize the open and closed lists
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            closedList[i][j] = false;
        }
    }

    // Create start node and add it to the open list
    Node *startNode = (Node *)malloc(sizeof(Node));
    startNode->row = startRow;
    startNode->col = startCol;
    startNode->f = 0;
    startNode->g = 0;
    startNode->h = 0;
    startNode->parent = NULL;
    openList[0] = startNode;

    // While there are nodes to explore in the open list
    while (openList[0] != NULL)
    {
        // Find the node with the lowest f value in the open list
        Node *currentNode = openList[0];
        int currentIndex = 0;
        for (int i = 1; openList[i] != NULL; i++)
        {
            if (openList[i]->f < currentNode->f)
            {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        // Remove the current node from the open list
        openList[currentIndex] = openList[0];
        openList[0] = currentNode->parent;

        // Mark the current node as visited
        closedList[currentNode->row][currentNode->col] = true;

        // If the current node is the goal, reconstruct the path and return
        if (isGoal(currentNode->row, currentNode->col, goalRow, goalCol))
        {
            printf("Path found!\n");
            while (currentNode != NULL)
            {
                printf("(%d,%d)\n", currentNode->row, currentNode->col);
                currentNode = currentNode->parent;
            }
            return;
        }

        // Generate successor nodes
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if ((i != 0 || j != 0) && isValid(currentNode->row + i, currentNode->col + j))
                {
                    int successorRow = currentNode->row + i;
                    int successorCol = currentNode->col + j;

                    // Check if the successor node is valid and not blocked
                    if (!isBlocked(grid, successorRow, successorCol) && !closedList[successorRow][successorCol])
                    {
                        // Calculate the successor node's g, h, and f values
                        int g = currentNode->g + 1;
                        int h = calculateH(successorRow, successorCol, goalRow, goalCol);
                        int f = g + h;

                        // Check if the successor is already in the open list
                        bool inOpenList = false;
                        for (int k = 0; openList[k] != NULL; k++)
                        {
                            if (openList[k]->row == successorRow && openList[k]->col == successorCol)
                            {
                                inOpenList = true;
                                break;
                            }
                        }

                        // If the successor is not in the open list or has a lower f value, add it to the open list
                        if (!inOpenList || f < openList[currentIndex]->f)
                        {
                            Node *successorNode = (Node *)malloc(sizeof(Node));
                            successorNode->row = successorRow;
                            successorNode->col = successorCol;
                            successorNode->f = f;
                            successorNode->g = g;
                            successorNode->h = h;
                            successorNode->parent = currentNode;
                            openList[currentIndex] = successorNode;
                        }
                    }
                }
            }
        }
    }

    // If no path is found
    printf("No path found!\n");
}

int main()
{
    int grid[ROWS][COLS] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    int startRow = 0, startCol = 0;
    int goalRow = 4, goalCol = 4;

    aStarSearch(grid, startRow, startCol, goalRow, goalCol);

    return 0;
}
