#include "sort.h"
/**
 * bubble_sort - sorting an array using bubble sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int tempo;

	if (size < 2 || !array)
		return;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			if (array[b] < array[b - 1])
			{
				tempo = array[b];
				array[b] = array[b - 1];
				array[b - 1] = tempo;
				print_array(array, size);
			}
		}
	}
}
