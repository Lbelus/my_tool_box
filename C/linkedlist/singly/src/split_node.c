#include <node_header.h>

node_t *split_node_on_pos(node_t *head, int pos)
{  
    int index = 0;    
    if (head == NULL){return NULL;}
    while (index < pos)
    {
        head = head->next;
        index += 1;
    }
    node_t *tmp = head->next;
    head->next = NULL;
    return tmp;
}