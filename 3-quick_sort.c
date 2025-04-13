#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array using the Lomuto partition scheme
 * @array: The array to partition
 * @left: The starting index of the partition
 * @right: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot;
	int high;
	int low;

	pivot = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}
	if (array[high] > *pivot)
	{
		swap(array + high, pivot);
		print_array(array, size);
	}
	return (high);
}

/**
 * quick_sort_recursive - Recursively sorts the array using Quick sort
 * @array: The array to sort
 * @left: The starting index of the partition
 * @right: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		quick_sort_recursive(array, size, left, part - 1);
		quick_sort_recursive(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
