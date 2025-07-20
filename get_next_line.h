#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);
char    *get_next_line(int fd);
int	    ft_strlen(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	count(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char *clean_stash(char *stash);
char *read_and_stash(int fd, char *stash);
char* extract_line(char *stash);
int  find_len(char *stash);

#endif