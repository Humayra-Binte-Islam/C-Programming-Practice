#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sizes[] = {1000, 2000, 3000, 4000, 5000};

    srand(time(NULL));

    for (int k = 0; k < 5; k++)
    {
        int n = sizes[k];

        int *adj = (int *)calloc(n * n, sizeof(int));
        int *degree = (int *)calloc(n, sizeof(int));

        /* Random Undirected Graph */
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x = rand() % 2;
                adj[i * n + j] = x;
                adj[j * n + i] = x;
            }
        }

        clock_t start = clock();

        /* Degree Calculation */
        long long degreeSum = 0;

        for (int i = 0; i < n; i++)
        {
            degree[i] = 0;

            for (int j = 0; j < n; j++)
            {
                degree[i] += adj[i * n + j];
            }

            degreeSum += degree[i];
        }

        /* Edge Count */
        long long edges = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (adj[i * n + j] == 1)
                    edges++;
            }
        }

        clock_t end = clock();

        double time_ms = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

        printf("\n===== n = %d =====\n", n);
        printf("Number of Edges = %lld\n", edges);
        printf("Sum of Degrees = %lld\n", degreeSum);
        printf("2E = %lld\n", 2 * edges);

        if (degreeSum == 2 * edges)
            printf("Handshaking Logic = TRUE\n");
        else
            printf("Handshaking Logic = FALSE\n");

        printf("Computational Time = %.3f ms\n", time_ms);

        free(adj);
        free(degree);
    }

    return 0;
}
