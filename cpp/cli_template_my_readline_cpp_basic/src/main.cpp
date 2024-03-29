// #include <zz00_my_main_lang.hpp>


// int main(int argc, char** argv)
// {

//     printf("Begin c++ test on GET and SET\n");
//     my_redis::RedisClient rc("tcp://myredis:6379");
//     std::cout << "SET operation - " << rc.set("Hiredis01", "Hiredis01_value") << std::endl;
//     std::cout << "GET operation - value: " << rc.get("Hiredis01") << std::endl;
//     printf("End of c++ test...\n\n\n");
//     // UsrIn::Lexer lx;
//     // UsrIn::handleStandardInput(lx);

//     return EXIT_SUCCESS;
// }

#include <main_header.hpp>

int main(int argc, char** argv)
{
    int             cmd_count   = 0;
    int             fd          = STDIN_FILENO;
    char*           str         = NULL;
    char**          tokens      = NULL;
    my_getopt_t*    getopt_ptr  = NULL;

    init_my_readline();
    while ((str = my_readline(fd)) != NULL)
    {
        getopt_ptr = (my_getopt_t*)malloc(sizeof(my_getopt_t));
        init_getopt(getopt_ptr, VALID_ARG);
        cmd_count = count_cmd(str, true);
        tokens = my_strtok(str , 1, __SPACE_CHAR__);
        flag_parser(cmd_count, tokens, VALID_ARG, getopt_ptr);
        execute_cmd(getopt_ptr);
        if (getopt_ptr->exit_status == true)
        {
            fd = -1;
        }
        free_opt(getopt_ptr);
        free(tokens);
        free(str);
    }
    return EXIT_SUCCESS;
}