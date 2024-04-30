#include "sort.h"

/**
 * bubble_sort_list - sorts a doubly linked list of integers in ascending order using Bubble sort
 * @list: pointer to pointer to the head of the list
 */
void bubble_sort_list(listint_t **list)
{
    listint_t *current, *prev;
    int swapped;

    if (!list || !(*list) || !((*list)->next))
        return;

    do
    {
        swapped = 0;
        current = *list;
        while (current->next != NULL)
        {
            if (current->n > current->next->n)
            {
                if (current->prev != NULL)
                    current->prev->next = current->next;
                else
                    *list = current->next;
                current->next->prev = current->prev;
                prev = current->next;
                current->next = prev->next;
                prev->next = current;
                current->prev = prev;
                if (current->next != NULL)
                    current->next->prev = current;
                swapped = 1;
                print_list(*list);
            }
            else
            {
                current = current->next;
            }
        }
    } while (swapped);
}
