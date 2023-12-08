#include <main_header.h>


int find_ch(char* str, char ch)
{
    int index = 0;
    while (str[index] != ch && str[index] != '\0')
    {
            index += 1;
    }
    return index;
}

char** my_strtok(char* str, int start_pos, char ch)
{
    char* tmp = str;
    char** tokens = malloc(sizeof(char*) * MAX_INPUT_TOKENS);
    char* start = str;
    char* end;
    int index = start_pos;
    int pos = 0;
    while ((end = my_strchr(start, ch)) != NULL)
    {
        pos = find_ch(start, ch);
        start[pos] = '\0';
        tokens[index] = start;
        index += 1;
        start = end + 1;
    }
    tokens[index] = start;
    return tokens;
}