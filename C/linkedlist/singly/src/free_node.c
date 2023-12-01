#include "node_header.h"

void free_node(node_t *head)
{
    node_t *tmp = head; 
    while (head != NULL)
    {
        head = head->next;
        free(tmp);
        tmp = head; 
    }
}

void recur_free_node(node_t *head)
{
    if (head == NULL)
    {
        return;
    }
    node_t *tmp = head;
    head = head->next;
    free(tmp);
    recur_free_node(head);
}