#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, tmp, max;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		max = i;
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				max = j;
			}
		}
		if (min != array[i])
		{
			tmp = array[i];
			array[i] = min;
			array[max] = tmp;
			print_array(array, size);
		}
	}
}
