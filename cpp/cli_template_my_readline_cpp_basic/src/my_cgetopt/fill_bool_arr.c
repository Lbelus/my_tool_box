#include <main_CLI_header.h>

void fill_bool_array(bool* bool_arr, int len)
{
    int index = 0;
    while (index < len)
    {
        bool_arr[index] = false;
        index += 1;
    }
}