#include <stdio.h>
#include <time.h>

int main() {
    
    char name[50];
    int age;

   
    clock_t start, end;
    double cpu_time_used;

    
    start = clock();

   
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

   
    long long sum = 0;
    for (long long i = 0; i < 100000000; i++) {
        sum += i % 10;  
    }

    // Display results
    printf("\n--- User Info ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Processed sum: %lld\n", sum);

    // End timer
    end = clock();

    // Calculate and display execution time in seconds
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %.4f seconds\n", cpu_time_used);

    return 0;
}
