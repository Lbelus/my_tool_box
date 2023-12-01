#include "node_header.h"
#include <stdio.h>

node_t *sort_ascending(node_t *head)
{
    node_t *tmp = 0;
    node_t *new_head = 0;
    while (head != NULL)
    {
        tmp = create_new_node(node_get_max(head));
        insert_at_head(&new_head, tmp);
        delete_node_on_key(&head, tmp->value);
    }
    return new_head;
}