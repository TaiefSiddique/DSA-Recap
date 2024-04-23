#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the cost function you want to minimize
double cost_function(double x)
{
    return x * x; // Example function: minimize y = x^2
}

// Simulated Annealing function
double simulated_annealing(double initial_temp, double final_temp, double cooling_rate, double initial_solution)
{
    double current_solution = initial_solution;
    double best_solution = current_solution;

    double temperature = initial_temp;

    // Main loop
    while (temperature > final_temp)
    {
        // Generate a random neighbor
        double new_solution = current_solution + ((double)rand() / RAND_MAX - 0.5) * temperature;

        // Calculate the change in cost
        double delta = cost_function(new_solution) - cost_function(current_solution);

        // If the new solution is better, accept it
        if (delta < 0)
        {
            current_solution = new_solution;
            if (cost_function(current_solution) < cost_function(best_solution))
            {
                best_solution = current_solution;
            }
        }
        // If the new solution is worse, accept it with a probability
        else
        {
            double probability = exp(-delta / temperature);
            if ((double)rand() / RAND_MAX < probability)
            {
                current_solution = new_solution;
            }
        }

        // Cool down the temperature
        temperature *= cooling_rate;
    }

    return best_solution;
}

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Parameters
    double initial_temp = 1000.0;
    double final_temp = 0.1;
    double cooling_rate = 0.95;
    double initial_solution = 10.0; // Initial guess

    // Run simulated annealing
    double result = simulated_annealing(initial_temp, final_temp, cooling_rate, initial_solution);

    // Output the result
    printf("Minimum found at x = %.2f, y = %.2f\n", result, cost_function(result));

    return 0;
}
