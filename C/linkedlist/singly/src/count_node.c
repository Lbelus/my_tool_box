#include <node_header.h>

int node_count(node_t *head)
{
    int count = 0;
    node_t *tmp = head;
    while (tmp != NULL )
    {
        tmp = tmp->next;
        count++;
    }
    return count;
}

int r_node_count(node_t *head, int count)
{    
    if (head == NULL)
    {
        return count;
    }
    count += 1;
    return r_node_count(head->next, count); 
}