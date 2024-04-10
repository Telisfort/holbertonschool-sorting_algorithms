#include "sort.h"

/**
 * swap_ints - Échange deux entiers dans un tableau.
 * @a: Le premier entier à échanger.
 * @b: Le deuxième entier à échanger.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Trie un tableau d'entiers par ordre croissant.
 * @array: Un tableau d'entiers à trier.
 * @size: La taille du tableau.
 *
 * Description : Imprime le tableau après chaque échange.
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

