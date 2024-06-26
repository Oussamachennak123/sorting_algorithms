#include "sort.h"
/**
 * swap_nbrs - Swap two numbers in an array
 * @x:   first number to swap
 * @y:   second number to swap
 */
void swap_nbrs(int *x, int *y)
{
	int tempo;

	tempo = *x;
	*x = *y;
	*y = tempo;
}

/**
 * shell_sort - Sort an array of numbers in ascending order
 * @array: An array of numbers
 * @size:   size of   array
 *
 * Description: Uses   Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gappo, x, y;

	if (array == NULL || size < 2)
		return;

	for (gappo = 1; gappo < (size / 3);)
		gappo = gappo * 3 + 1;

	for (; gappo >= 1; gappo/= 3)
	{
		for (x = gappo; x < size; x++)
		{
			y = x;
			while (y >= gappo && array[y - gappo] > array[y])
			{
				swap_nbrs(array + y, array + (y - gappo));
				y -= gappo;
			}
		}
		print_array(array, size);
	}
}
