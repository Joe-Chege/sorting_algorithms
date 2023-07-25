#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {15, 43, 48, 71, 16, 52, 96, 73, 96, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    // Print the initial array
    print_array(array, n);
    printf("\n");

    // Sort the array using bubble sort
    bubble_sort(array, n);
    printf("\n");

    // Print the sorted array
    print_array(array, n);

    return 0;
}
