#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

#include "trove.h"

/*Builds new trovefile/index from the given filelist
This will replace any existing trovefile with the same name (??)
*/
#define MAX_NAME 256
#define TABLE_SIZE 3
struct line
    {
        int value;
        int key;
    };

void display_table(struct line ar[], int size) {
    printf("value\tkey\n");
    
    for (int i = 0; i < size; i++)
    {
        printf("%d\t%d\n",ar[i].value,ar[i].key);
    }
    
}

int build_trovefile()
{
    int size = TABLE_SIZE;
    int tmp;
    

    struct line hash_table[size];
    printf("enter three integers: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&tmp);
        hash_table[tmp % size].value = tmp;
        hash_table[tmp % size].key = tmp % size;
    }
    printf("\n");

    display_table(hash_table,size);
    
    // printf("%s\n", word);
    return 0;
}

