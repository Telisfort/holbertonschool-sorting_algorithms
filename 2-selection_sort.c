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
 * selection_sort - Trie un tableau d'entiers par ordre croissant
 *                  en utilisant l'algorithme de tri par sélection.
 * @array: Un tableau d'entiers.
 * @size: La taille du tableau.
 * Description : Imprime le tableau après chaque échange.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
