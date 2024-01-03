#include <main_header.h>

void init_getopt(my_getopt_t* getopt_ptr, const char* valid_args)
{
    getopt_ptr->exit_status = false;
    int len = _my_strlen(valid_args);
    getopt_ptr->bool_arr = (bool*)malloc(sizeof(bool) * len);
    fill_bool_array(getopt_ptr->bool_arr, _my_strlen(valid_args));
    getopt_ptr->nbr_str = 0;
}