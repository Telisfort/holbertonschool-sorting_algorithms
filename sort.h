#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Macros pour la direction de comparaison pour le tri bitonique */
#define HAUT 0
#define BAS 1

/* Énumération des valeurs booléennes */
typedef enum bool
{
    faux = 0,
    vrai
} bool;


/**
 * struct listint_s - Noeud d'une liste doublement chaînée
 *
 * @n: Entier stocké dans le nœud
 * @prev: Pointeur vers l'élément précédent de la liste
 * @next: Pointeur vers l'élément suivant de la liste
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Fonction d'aide pour l'échange d'entiers */
void swap_ints(int *a, int *b);

/* Fonctions d'impression */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Prototypes des fonctions de tri */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

#endif

