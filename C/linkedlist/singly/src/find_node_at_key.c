#include <node_header.h>

node_t *find_node_at_key(node_t *head, int value)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value)
        { 
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}


node_t *r_find_node_at_key(node_t *head, int value)
{

    if (head == NULL)
    {
        return NULL;
    }
    if (head->value == value)
    {
        return head;
    }
    return r_find_node_at_key(head->next, value);
}
