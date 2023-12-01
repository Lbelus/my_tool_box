#include <node_header.h>

void recur_concatenate_llist(node_t* node_a, node_t* node_b)
{
    if(node_a->next == NULL)
    {
        node_a->next = node_b;
    }
    else
    {
        recur_concatenate_llist(node_a->next, node_b);
    }
}

void concatenate_llist(node_t* node_a, node_t* node_b)
{
    while(node_a != NULL)
    {
        node_a = node_a->next;
        if (node_a->next == NULL)
        {
            node_a->next = node_b;
            break;
        }
    }
}