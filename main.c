#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("deneme.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Dosya acilamadi");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}