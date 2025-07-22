#include "get_next_line.h"

int find_len(char *stash)
{
    int i;
    i = 0;
    if (stash == NULL)
        return (0);
    while(*(stash + i) != '\0')
    {
        if(*(stash + i) == '\n')
            return(i + 1);
        i++;
    }
    return(0);
}
char* extract_line(char *stash)
{
    char *line;
    if(stash == NULL || stash[0] == '\0')
        return(NULL);
    line = ft_substr(stash, 0, find_len(stash));
    return(line);
}
char *read_and_stash(int fd, char *stash)
{
    char *buffer;
    char *temp;
    buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
    if(!buffer)
        return (NULL);
    int readByte = 1;
    while( readByte > 0 && !find_len(stash))
    {
        printf("donguye girildi...\n");
        readByte = read(fd, buffer, BUFFER_SIZE);
        printf("okunan byte sayisi %d\n",readByte);
        if (readByte == 0)
            break;
        if (readByte < 0)
        {
            free(buffer);
            return (NULL);
        }
        buffer[readByte] = '\0';
        printf(" okunan buffer degeri %s\n",buffer);
        temp = stash;
        stash = ft_strjoin(stash, buffer);
        printf("joinlenmis stash degeri %s\n",stash);
        free(temp);
    }
    free(buffer);
    return(stash);
}

char *clean_stash(char *stash)
{
    char *line;
    int len;
    len = find_len(stash);

    if(!stash)
        return(NULL);
    if(len == 0)
    {
        free(stash);
        return(NULL);
    }
    line = ft_substr(stash, len, ft_strlen(stash) - len);
    free(stash);
    return(line);
}


char *get_next_line(int fd)
{
    static char *stash;
    char *line;
    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);

    stash = read_and_stash(fd, stash);
    printf("çikan stash degeri %s\n",stash);
    if(!stash)
        return(NULL);
    line = extract_line(stash);
    stash = clean_stash(stash);
    return(line);
}
