#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the problem space
#define NUM_VARIABLES 5
#define MIN_VALUE 0
#define MAX_VALUE 10

// Function to generate a random solution
void generateRandomSolution(int solution[])
{
    for (int i = 0; i < NUM_VARIABLES; i++)
    {
        solution[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

// Function to calculate the objective value of a solution
int objectiveFunction(int solution[])
{
    int sum = 0;
    for (int i = 0; i < NUM_VARIABLES; i++)
    {
        sum += solution[i];
    }
    return sum;
}

// Function to print a solution
void printSolution(int solution[])
{
    for (int i = 0; i < NUM_VARIABLES; i++)
    {
        printf("%d ", solution[i]);
    }
    printf("\n");
}

// Hill Climbing algorithm
void hillClimbing()
{
    int currentSolution[NUM_VARIABLES];
    int bestSolution[NUM_VARIABLES];
    int currentObjective, bestObjective;

    // Generate a random initial solution
    generateRandomSolution(currentSolution);
    bestObjective = objectiveFunction(currentSolution);
    for (int i = 0; i < NUM_VARIABLES; i++)
    {
        bestSolution[i] = currentSolution[i];
    }

    // Start climbing
    while (1)
    {
        int changed = 0;

        // Generate a neighbor solution by randomly changing one variable
        int neighbor[NUM_VARIABLES];
        for (int i = 0; i < NUM_VARIABLES; i++)
        {
            neighbor[i] = currentSolution[i];
        }
        int indexToChange = rand() % NUM_VARIABLES;
        neighbor[indexToChange] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;

        // Calculate the objective value of the neighbor solution
        int neighborObjective = objectiveFunction(neighbor);

        // If the neighbor is better, update the current solution
        if (neighborObjective > bestObjective)
        {
            bestObjective = neighborObjective;
            for (int i = 0; i < NUM_VARIABLES; i++)
            {
                currentSolution[i] = neighbor[i];
            }
            changed = 1;
        }

        // If no improvement, break
        if (!changed)
        {
            break;
        }
    }

    // Print the best solution found
    printf("Best Solution: ");
    printSolution(bestSolution);
    printf("Objective Value: %d\n", bestObjective);
}

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Run Hill Climbing algorithm
    hillClimbing();

    return 0;
}
