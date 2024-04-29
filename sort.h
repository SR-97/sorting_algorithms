#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Struct for doubly linked list */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Provided print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Bubble Sort function */
void bubble_sort(int *array, size_t size);

/* Insertion Sort function */
void insertion_sort_list(listint_t **list);

/* Selection Sort function */
void selection_sort(int *array, size_t size);

/* Quick Sort function */
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
