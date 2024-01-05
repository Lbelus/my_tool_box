#include <main_header.h>

int main()
{
    (void) signal(SIGINT, finish);
    int             cmd_count   = 0;
    char*           str         = NULL;
    char**          tokens      = NULL;
    my_getopt_t*    getopt_ptr  = NULL;
    bool            exit_nc     = false; 
    init_ncurse();
    while (!exit_nc && (str = read_input()) != NULL)
    {
        getopt_ptr = malloc(sizeof(my_getopt_t));
        init_getopt(getopt_ptr, VALID_ARG);
        cmd_count = count_cmd(str, true);
        tokens = my_strtok(str , 1, __SPACE_CHAR__);
        flag_parser(cmd_count, tokens, VALID_ARG, getopt_ptr);
        execute_capture_output(getopt_ptr);
        if (getopt_ptr->exit_status == true)
        {
            sleep(1);
            exit_nc = true;
        }
        free_opt(getopt_ptr);
        free(tokens);
        free(str);
    }
    endwin();
    return EXIT_SUCCESS;
}