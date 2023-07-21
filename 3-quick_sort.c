#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * partition - Partitions an array using Lomuto partition scheme
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot after partitioning
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j;

    for (j = low; j <= high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    return (i);
}

/**
 * lomuto_qsort - Sorts an array using Lomuto partition and Quick sort
 * @array: Array to be sorted
 * @low: Starting index of the array
 * @high: Ending index of the array
 * @size: Size of the array
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
    int idx;

    if (low < high)
    {
        idx = partition(array, low, high, size);
        lomuto_qsort(array, low, idx - 1, size);
        lomuto_qsort(array, idx + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_qsort(array, 0, size - 1, size);
}
