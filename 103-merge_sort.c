#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int *temp_array, int left, int mid, int right)
{
    int i, j, k;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, mid - left + 1);
    printf("[right]: ");
    print_array(array + mid + 1, right - mid);

    for (i = left; i <= mid; i++)
        temp_array[i] = array[i];
    for (j = mid + 1; j <= right; j++)
        temp_array[j] = array[j];

    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)
    {
        if (temp_array[i] <= temp_array[j])
        {
            array[k] = temp_array[i];
            i++;
        }
        else
        {
            array[k] = temp_array[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        array[k] = temp_array[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        array[k] = temp_array[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    print_array(array + left, right - left + 1);
}

void merge_sort_helper(int *array, int *temp_array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort_helper(array, temp_array, left, mid);
        merge_sort_helper(array, temp_array, mid + 1, right);

        merge(array, temp_array, left, mid, right);
    }
}

void merge_sort(int *array, size_t size)
{
    int *temp_array;

    if (!array || size < 2)
        return;

    temp_array = malloc(sizeof(int) * size);
    if (temp_array == NULL)
        return;

    merge_sort_helper(array, temp_array, 0, size - 1);

    free(temp_array);
}
