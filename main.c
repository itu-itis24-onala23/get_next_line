#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd = open("deneme.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Dosya açılamadı");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}