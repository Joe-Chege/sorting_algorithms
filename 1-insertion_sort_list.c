#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr, *back, *tail;
    curr = (*list)->next;
    tail = curr;

    while (curr)
    {
        if (curr->n < curr->prev->n)
        {
            back = curr->prev;
            while (back && back->n > curr->n)
            {
                back->next = curr->next;
                if (curr->next)
                    curr->next->prev = back;

                if (back->prev)
                    back->prev->next = curr;
                else
                    *list = curr;

                curr->prev = back->prev;
                back->prev = curr;
                curr->next = back;

                back = curr->prev;
            }
            print_list(*list);
        }
        else
        {
            curr = curr->next;
        }

        if (curr && curr->n > tail->n)
            tail = curr;
    }
}
