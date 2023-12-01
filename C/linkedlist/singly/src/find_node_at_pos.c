#include <node_header.h>

node_t *find_node_at_pos(node_t *head, int pos)
{
    node_t *tmp = head;
    int index = 0;
    while(index < pos)
    {
        tmp = tmp->next;
        index += 1;
    }    
    return tmp->next;
}

node_t *r_find_node_at_pos(node_t *head, int pos, int index)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (index == pos)
    {
        return head;
    }
    index += 1;
    return r_find_node_at_pos(head->next, pos, index);
}