#ifndef __PARSER_HEADERFILE_
#define __PARSER_HEADERFILE_

#include <main_header.h>

#define __SPACE_CHAR__   ' '
#define MAX_INPUT_TOKENS 250
#define DELIMITER        '\n'
#define BLOCK_SIZE       512

char**  my_strtok(char* str, int start_pos, char ch);
int     find_ch(char* str, char ch);
int     count_cmd(char* str, bool is_cli);

#endif