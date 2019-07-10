#include "reader.h"

char *read_line(FILE *);
char *add_c(char *, char);

int main(int argc, char const *argv[])
{
    if (argc < 2)
        printf("Please pass file-path as argument\n");
    else
    {
        List *lines = read((char *)argv[1]);
        List *current_line = lines;
        for (int i = 0; i < lines->length; i++)
        {
            printf("%s\n", current_line->data);
            current_line = current_line->next;
        }
    }
    
}

List *read(char *file_name)
{
    FILE *file;
    List *lines;

    file = fopen(file_name, "r");
    lines = l_init(read_line(file));
    while(!feof(file))
    {
        l_add(lines, read_line(file));
    }
    return lines;
}

char *read_line(FILE *file)
{
    char *line = "";
    char character;
    while((character = fgetc(file)) && character != '\n' && !feof(file))
    {
        line = add_c(line, character);
    }
    return line;
}

char *add_c(char *dest, char new_c)
{
    char *new_string = (char *)calloc(sizeof(char), strlen(dest) + 1);
    memcpy(new_string, dest, strlen(dest));
    memset(new_string + strlen(dest), new_c, 1);
    return new_string;
}