#include <stdint.h>
#include <stdio.h>
#include<string.h>

#define M 997

/* Output is unsigned because we have buckets from 0 to M.  */
uint32_t hashFun(char *input, size_t len)
{
    uint32_t hash = 0;
    size_t i;

    for (i = 0; i < len; i++)
    {
        hash = ((hash * 256) + input [i] ) % M;
    }

    return hash % M;
}

int main (void)
{

    char string[500];
    uint32_t key;


    while (1)
    {
        scanf ("%s", string);
        key = hashFun (string, strlen(string));
        printf ("key = %u\n", key);
    }

    return 0;
}
