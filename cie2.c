#include <stdio.h>
#include <time.h>
#include <omp.h>  // OpenMP header

int main() {
    char name[50];
    int age;
    double start_time, end_time;
    long long sum = 0;

    // Get user input
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    // Start real-world time (wall clock)
    start_time = omp_get_wtime();

    // Parallel processing using OpenMP
    #pragma omp parallel for reduction(+:sum)
    for (long long i = 0; i < 100000000; i++) {
        sum += i % 10;
    }

    // End time
    end_time = omp_get_wtime();

    // Display results
    printf("\n--- User Info ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Processed sum: %lld\n", sum);
    printf("Execution time (parallel): %.4f seconds\n", end_time - start_time);

    return 0;
}
