#include <stdio.h>
#include <stdlib.h>

/* Computes the sum of the first n elements in the array. */
int sum(int n, int* arr)
{
    int i, total = 0;
    for (i = 0; i < n; i++)
        total += arr[i];
    return total;
}

/* Fills the given array with the values
 * 1^2, 2^2, 3^2, ..., n^2. */
void fillSquares(int n, int* arr)
{
    int i;
    for (i = 0; i < n; i++)   // ✅ fixed indexing
        arr[i] = (i + 1) * (i + 1);
}

/* Main */
int main(int argc, char* argv[])
{
    int n, total;
    int* arr;

    if (argc < 2) {
        printf("usage: ./squares n\n");
        return 1;
    }

    n = atoi(argv[1]);
    if (n <= 0) {
        printf("n must be positive.\n");
        return 1;
    }

    arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("malloc failed");
        return 1;
    }

    fillSquares(n, arr);
    total = sum(n, arr);
    printf("total: %d\n", total);

    free(arr);
    return 0;
}
