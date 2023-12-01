#include <node_header.h>

int get_min(node_t* head)
{
    int min = head->value;
    while (head != NULL)
    {
        if (min > head->value) 
        {
            min = head->value;
        }
        head = head->next;
    }
    return min;
}