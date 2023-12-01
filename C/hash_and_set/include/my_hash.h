#ifndef __MY_HASH_HEADER_
#define __MY_HASH_HEADER_

#include <stdbool.h>

#define TABLE_SIZE 1000

#ifndef __MY_HASH__
#define __MY_HASH__
struct hash
{
    bool data[TABLE_SIZE];
};
typedef struct hash hash_t;
#endif

int     create_hash (void* token);
int     create_hash_64_bit_addr(void* ptr);

int     my_pow(int val, int exp);
void    clear_hash(hash_t* hash_table);

#endif