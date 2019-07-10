#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    struct list *next;
    char *data;
    int length;
} List;

List *l_init(char *);
List *l_add(List *, char *);