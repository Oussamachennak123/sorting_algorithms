#include "sort.h"

/**
 * selection_sort - sorting an array using selection sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int smallesto, tempo;
	size_t a, j;

	if (!array || size < 2)
		return;

	a = 0;
	while (a < size - 1)
	{
		smallesto = a;
		j = a + 1;
		while (j < size)
		{
			if (array[j] < array[smallesto])
				smallesto = j;
			j++;
		}
		if (smallesto != (int)a)
		{
			tempo = array[a];
			array[a] = array[smallesto];
			array[smallesto] = tempo;
			print_array(array, size);
		}
		a++;
	}
}
