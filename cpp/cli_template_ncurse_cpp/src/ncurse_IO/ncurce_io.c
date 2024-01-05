#include <main_CLI_header.h>

// char* nc_buff;


void finish()
{
    endwin();
    exit(EXIT_SUCCESS);
}

// void* my_memset(void* ptr, char ch, int len)
// {
//     int index = 0;
//     char* ptr_a = (char*)ptr;
//     while (index < len)
//     {
//         ptr_a[index] = ch;
//         index += 1;
//     }
//     return ptr_a;
// }

void init_ncurse()
{
    (void) initscr();
    keypad(stdscr, TRUE);
    // raw();
    (void) cbreak();
    (void) noecho();
    // nc_buff = (char*)malloc(sizeof(char) * win_width);
    // my_memset(nc_buff, '\0', win_width);
    // return nc_buff;
}

void update_cursor(char* buffer, int cursor_pos)
{
    move(0, 0);
    clrtoeol();
    printw("%s", buffer);
    move(0, cursor_pos);
}


bool is_key_arrow(int ch, int* cursor_pos, int index)
{
    switch(ch)
    {
        case KEY_UP:
            return true;
        case KEY_DOWN:
            return true;
        case KEY_LEFT:
            if (*cursor_pos > 0)
            {
                *cursor_pos -= 1;
            }
            return true;
        case KEY_RIGHT:
            if (*cursor_pos < index)
            {
                *cursor_pos += 1;
            }
            return true;
        default: 
            return false;
    }
}


void erase_buff(char* buffer, int cursor_pos, int curr)
{
    int index = cursor_pos - 1;
    while (index < curr - 1)
    {
        index += 1;
        buffer[index] = buffer[index + 1];
    }
}

void update_buff(char* buffer, int cursor_pos, int curr)
{
    int index = curr;
    while (index > cursor_pos)
    {
        index -= 1;
        buffer[index] = buffer[index - 1];
    }
}

char* read_input()
{
    int win_width = 0;
    int ch = 0;
    // char buffer[MAX_INPUT_LENGTH];
    char* nc_buff = NULL;
    int index = 0;
    int cursor_pos = 0;
    win_width = getmaxx(stdscr);
    nc_buff = (char*)malloc(sizeof(char)* (500 - 1));
    _my_memset(nc_buff, '\0', win_width);
    while (true)
    {
        // if execption if resize occures
        // realloc
        // pursue

        ch = getch();
        if (ch == KEY_BACKSPACE || ch == 127)
        {
            erase_buff(nc_buff, cursor_pos, index);
            if (cursor_pos > 0)
            {
                index -= 1;
                cursor_pos -= 1;
                nc_buff[index] = '\0';
                update_cursor(nc_buff, cursor_pos);
            }
        }
        else if (is_key_arrow(ch, &cursor_pos, index))
        {
                move(0, cursor_pos);
        }
        else if (ch == '\n')
        {
            cursor_pos = 0;
            index = 0;
            move(0, 0);
            printf("\n");
            return nc_buff;
            // bzero(nc_buff, MAX_INPUT_LENGTH);
        }
        else if (ch == 4)
        {
            free(nc_buff);
            break; // Exit the loop on ctrl + d
        }
        else if (index < win_width - 1)
        {
            update_buff(nc_buff, cursor_pos, index);
            nc_buff[cursor_pos] = (char)ch;
            index += 1;
            cursor_pos += 1;
            update_cursor(nc_buff, cursor_pos);
        }
    }
    return NULL;
}


// void printCapturedOutput(my_getopt_t* getopt_ptr) {
//     int pipefd[2];
//     if (pipe(pipefd) == -1) {
//         perror("pipe");
//         return;
//     }

//     pid_t pid = fork();
//     if (pid == -1) {
//         perror("fork");
//         close(pipefd[0]);
//         close(pipefd[1]);
//         return;
//     }

//     if (pid == 0)
//     {
//         close(pipefd[0]);
//         dup2(pipefd[1], STDOUT_FILENO);
//         close(pipefd[1]);

//         execute_cmd(getopt_ptr);

//         exit(EXIT_SUCCESS);
//     }
//     else
//     {
//         close(pipefd[1]);
//         char buffer[256];

//         while (read(pipefd[0], buffer, sizeof(buffer)) > 0)
//         {
//             printw("%s", buffer);
//             memset(buffer, 0, sizeof(buffer));
//         }

//         close(pipefd[0]);
//         waitpid(pid, NULL, 0);
//         refresh();
//     }
// }

int get_file_size(char* filename)
{
    struct stat st;
    if (stat(filename, &st) == 0)
    {
        return (int)st.st_size; // limit file size to an int
    }
    else
    {
        return -1;
    }
}

char* read_to_buffer(char* filename)
{
    int     size    = get_file_size(filename);
    char*   buff    = (char*)malloc(sizeof(char)*(size + 1));
    int     fd      = open(filename, O_RDONLY);
    int     block   = 0;
    int     pos     = 0;
    while ((block = read(fd, &buff[pos], BLOCK_SIZE)))
    {
        pos += block;
    }
    buff[pos] = '\0';
    close(fd);
    return buff;
}


void execute_and_capture(my_getopt_t* getopt_ptr)
{
    fflush(stdout);
    int original_stdout = dup(STDOUT_FILENO);
    int fd = open("temp_output.txt", O_RDWR | O_CREAT, 0644);
    dup2(fd, STDOUT_FILENO);
    execute_cmd(getopt_ptr);
    fflush(stdout);
    dup2(original_stdout, STDOUT_FILENO);
    close(fd);
}

void output_capture()
{
    char* buffer = read_to_buffer("temp_output.txt");
    printw("%s", buffer);
    free(buffer);
    remove("temp_output.txt");
}

void execute_capture_output(my_getopt_t* getopt_ptr)
{
    execute_and_capture(getopt_ptr);
    output_capture();
    refresh(); // Refresh the ncurses screen
}