#ifndef __NCURSE_IO_HEADERFILE_
#define __NCURSE_IO_HEADERFILE_


// #define MAX_INPUT_LENGTH 1024
#include <main_header.h>

typedef struct s_my_getopt my_getopt_t;


void    finish();
void    init_ncurse();

void    update_cursor(char* buffer, int cursor_pos);
bool    is_key_arrow(int ch, int* cursor_pos, int index);
void    erase_buff(char* buffer, int cursor_pos, int curr);
void    update_buff(char* buffer, int cursor_pos, int curr);
char*   read_input();

void    execute_capture_output(my_getopt_t* getopt_ptr);


#endif