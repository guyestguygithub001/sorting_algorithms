#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t x, idx;
	int y, swp, f = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		y = i;
		f = 0;
		for (idx = i + 1; idx < size; idx++)
		{
			if (array[y] > array[idx])
			{
				y = idx;
				f += 1;
			}
		}
		swp = array[i];
		array[i] = array[y];
		array[y] = swp;
		if (f != 0)
			print_array(array, size);
	}
}
