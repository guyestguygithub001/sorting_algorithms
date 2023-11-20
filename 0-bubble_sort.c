#include "sort.h"
#include <stdbool.h>
/**
 * swap_ints - Swap two ints in a given array,
 * @a: first int. to be swapped
 * @b: second int. to be swapped
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort array of numnbers in ascending order,
 * @array: array of numbers to sort,
 * @size: size of array,
 *
 * Description: Prints array after each swap,
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
