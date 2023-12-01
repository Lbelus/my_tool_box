#include <main_header.h>


size_t set_page_len(void* ptr)
{
    page_t* page = (page_t*)ptr;
    size_t page_len = page->bitnode->nb_page * handler->size_page;
    return page_len - 1; 
}


intree_t* create_node(void* ptr)
{
    intree_t* tmp = fetch_node();
    
    if (!tmp)
    {
      return NULL;
    }
    size_t page_len = set_page_len(ptr);
    tmp->address = ptr;
    tmp->max = (intptr_t)ptr + page_len;
    tmp->left = NULL; 
    tmp->right = NULL;
    return tmp;
}

intree_t* insert(intree_t* root, void* ptr)
{
    if (root == NULL)
    {
      return create_node(ptr);
    }

    uintptr_t low = (uintptr_t)root->address;

    if ((uintptr_t)ptr < low )
    {
        root->left = insert(root->left, ptr);
    } 
    else
    {
        root->right = insert(root->right, ptr);
    }
    size_t page_len = set_page_len(ptr);
    if (root->max < (uintptr_t)ptr + page_len)
    {
        root->max = (uintptr_t)ptr + page_len;
    }
  return root;
}

intree_t* find_page_start(intree_t* root, void* ptr)
{
    if (root == NULL)
    { 
      return NULL;
    }
    size_t page_len = set_page_len(root->address);
    if ((uintptr_t)root->address <= (uintptr_t)ptr 
      && (uintptr_t)ptr <= (uintptr_t)root->address + page_len)
    {
      return root;
    } 
    if (root->left != NULL && root->left->max >= (uintptr_t)ptr)
    {
        return find_page_start(root->left, ptr);
    }
    return find_page_start(root->right, ptr);
}


intree_t* fetch_node()
{
    intree_t* new_node = NULL;
    new_node = allocate_node();
    if (new_node == NULL)
    {
        void * ptr = my_mmap(handler->size_page);
        int size = handler->size_page / sizeof(intree_t) - 1;
        init_memory_segment(ptr, size);
        new_node = allocate_node();
    }
    return new_node;
}
