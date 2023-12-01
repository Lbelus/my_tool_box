#include <node_header.h>

void insert_after_node(node_t *node_to_insert, node_t *newnode)
{
    newnode->next = node_to_insert->next;
    node_to_insert->next = newnode;
}