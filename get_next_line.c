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
    printf("extract line in icine girdin mi \n");
    char *line;
    if(stash == NULL || stash[0] == '\0')
        return(NULL);
    if(!find_len(stash))
    {
        line = ft_substr(stash, find_len(stash), ft_strlen(stash) - find_len(stash));
        printf("len 0 olduğunda extract linedaki deger %s\n",line);
        return(line);
    }
    line = ft_substr(stash, 0, find_len(stash));
    printf("extract linedan cikan line %s\n",line);
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
    while( !find_len(stash))
    {
        printf("donguye girildi...\n");
        readByte = read(fd, buffer, BUFFER_SIZE);
        printf("okunan byte sayisi %d\n",readByte);
        if (readByte <= 0)
        {
            break;
        }
        buffer[readByte] = '\0';
        printf(" okunan buffer degeri %s\n",buffer);
        temp = stash;
        stash = ft_strjoin(stash, buffer);
        printf("joinlenmis stash degeri %s\n",stash);
        free(temp);
    }
    printf("while den ciktim\n");
    printf("whiledan ciktiktan sonraki stash degeri %s\n",stash);
    free(buffer);
    return(stash);
}

char *clean_stash(char *stash)
{
    char *line = NULL;
    int len;
    len = find_len(stash);

    if(!stash)
        return(NULL);
    /*if(len == 0)
    {
        line = stash;
        return(line);
    }*/
   if(len != 0)
   {
    printf("icinde new line var\n");
    line = ft_substr(stash, len, ft_strlen(stash) - len);
   }
    free(stash);
    printf("dondurulen line %s\n",line);
    return(line);
}


char *get_next_line(int fd)
{
    static char *stash;
    char *line;
    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    stash = read_and_stash(fd, stash);
    printf("cikan stash degeri %s\n",stash);
    if(!stash){
        printf("iff e girdi mi\n");
        return(NULL);
    }
    line = extract_line(stash);
    printf("extract linedan sonra stashin icinde ne var %s\n",stash);
    stash = clean_stash(stash);
    if(line == NULL)
        return(NULL);
    return(line);
}
