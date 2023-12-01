#include <node_header.h>


void remove_duplicate_on_node(node_t* head)
{
    node_t *tmp = head;
    if (head == NULL)
    {
        return;
    }
    int int_tmp = head->value;
    while (tmp != NULL)
    {
        if (int_tmp == tmp->value)
        {
            delete_node_on_key(&head->next, head->value);
        }
        tmp = tmp->next;
    }
    remove_duplicate_on_node(head->next); 
}