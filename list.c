#include "list.h"

List *l_init(char *data)
{
    List *list = (List *)calloc(sizeof(List), 1);
    list->data = data;
    list->length = 1;
    return list;
}

List *l_add(List *containing_list, char *data)
{
    if (containing_list->next)
        return l_add(containing_list->next, data);
    List *list = (List *)calloc(sizeof(List), 1);
    list->data = data;
    list->length = 1;
    containing_list->next = list;
    (containing_list->length)++;
    return containing_list;
}