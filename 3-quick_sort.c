#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Ordonne un sous-ensemble d'un tableau d'entiers selon
 *                    le schéma de partitionnement de Lomuto (le dernier élément comme pivot).
 * @array: Le tableau d'entiers.
 * @size: La taille du tableau.
 * @left: L'index de départ du sous-ensemble à ordonner.
 * @right: L'index de fin du sous-ensemble à ordonner.
 *
 * Retourne : L'index de partition final.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot, above, below;

    pivot = array + right;
    for (above = below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                swap_ints(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swap_ints(array + above, pivot);
        print_array(array, size);
    }

    return (above);
}

/**
 * lomuto_sort - Implémente l'algorithme de tri rapide par récursion.
 * @array: Un tableau d'entiers à trier.
 * @size: La taille du tableau.
 * @left: L'index de départ de la partition du tableau à ordonner.
 * @right: L'index de fin de la partition du tableau à ordonner.
 *
 * Description : Utilise le schéma de partitionnement de Lomuto.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int part;

    if (right - left > 0)
    {
        part = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, part - 1);
        lomuto_sort(array, size, part + 1, right);
    }
}

/**
 * quick_sort - Trie un tableau d'entiers par ordre croissant
 *              en utilisant l'algorithme de tri rapide.
 * @array: Un tableau d'entiers.
 * @size: La taille du tableau.
 *
 * Description : Utilise le schéma de partitionnement de Lomuto. Imprime
 *               le tableau après chaque échange de deux éléments.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}

