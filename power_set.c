#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print(int *subset, int size)
{
    int i = 0;
    while (i < size)
    {
        if (i > 0 && i < size - 1)
            printf(" ");
        printf("%d", subset[i]);
        i++;
    }
    printf("\n");
}

void solve(int *set, int set_size, int index, int target, int sum, int *subset, int size_subset)
{
    
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;
    int target = atoi(argv[1]);
    int set_size = argc - 2;

    int *set = calloc(set_size, sizeof(int));
    if (!set)
        return 1;
    int *subset = calloc(set_size, sizeof(int));
    if (!subset)
    {
        free(set);
        return 1;
    }
    int i = 0;
    while (i < set_size)
    {
        set[i] = atoi(argv[i + 2]);
        i++;
    }
    solve(set, set_size, 0, target, 0, subset, 0);

    free(set);
    free(subset);
    return 0;
}