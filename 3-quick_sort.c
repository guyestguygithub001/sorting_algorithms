#include "sort.h"
/**
 * swap - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @x: left element
 * @y: right element
 * @size: size of array
 */
void swap(int *array, int x, int y, int size)
{
	int a;

	if (array[x] == array[y])
		return;
	a = array[x];
	array[x] = array[y];
	array[y] = a;
	print_array(array, size);
}
/**
 * lumto_partition - sort array partition
 * @array: elements to be sorted
 * @begin: left side
 * @stop: right side
 * @size: size of array
 * Return: pivot sorted
 */
int lumto_partition(int *array, int begin, int stop, int size)
{
	int pivot = array[stop];
	int split_idx = begin;
	int v;

	for (v = begin; v < stop; v++)
		if (array[v] < pivot)
			swap(array, split_idx++, v, size);
	swap(array, split_idx, stop, size);
	return (split_idx);
}
/**
 * recursive - quick_sort core
 * @array: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 */
void recursive(int *array, int start, int end, int size)
{
	if (start < end)
	{
		int pivot_pos = lumto_partition(array, start, end, size);

		recursive(array, start, pivot_pos - 1, size);
		recursive(array, pivot_pos + 1, end, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	recursive(array, 0, size - 1, size);
}
