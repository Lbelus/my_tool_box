#ifndef __HEADERFILE_H_
#define __HEADERFILE_H_

#include <stdlib.h>

    #ifndef STRUCT_NODE
    #define STRUCT_NODE
    struct node {
        int value;
        struct node* next;
    };
    typedef struct node node_t;
    #endif

node_t  *create_new_node(int value);
void    delete_node_on_key(node_t **head, int key);
void    delete_node_on_index(node_t **head, int pos);

node_t  *find_node_at_pos(node_t *head, int pos);
node_t  *find_node_at_key(node_t *head, int value);
node_t  *r_find_node_at_key(node_t *head, int value);

int     get_max(node_t* head);
int     get_min(node_t* head);
void    insert_after_node(node_t *node_to_insert, node_t *newnode);
node_t  *insert_at_head(node_t **head, node_t *node_to_insert);
void    reverse_node_order(node_t **head);
void    test_print_list(node_t *head);
void    free_node(node_t *head);
void    recur_free_node(node_t *head);
node_t  *go_to_node(node_t *head, int pos);
void    remove_duplicate_on_node(node_t* head);
node_t  *split_node_on_pos(node_t *head, int len);
int     node_count(node_t *head);
int     r_node_count(node_t *head, int count);
void    concatenate_llist(node_t* node_a, node_t* node_b);
void    r_concatenate_llist(node_t* node_a, node_t* node_b);
node_t  *sort_ascending(node_t *head);
node_t* swap(node_t* head, int node_index1, int node_index2)
#endif