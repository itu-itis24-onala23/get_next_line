#include "get_next_line.h"

int	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	while (*s1)
	{
		i++;
		s1++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	if(!s1)
		return (ft_strdup(s2));
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (0);
	while (*(s1 + i) != '\0')
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j) != '\0')
	{
		*(str + i) = *(s2 + j);
		j++;
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

 size_t	count(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = (size_t)start;
	while (*(s + i) != '\0')
	{
		i++;
		j++;
	}
	if (len > j)
		return (j);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	new_len;
	char	*p;

	if ((int)start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	new_len = count(s, start, len);
	i = 0;
	p = (char *)malloc(new_len + 1);
	if (p == NULL)
		return (0);
	while (i < new_len)
	{
		*(p + i) = *(s + start);
		start++;
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(p + i) = *(s + i);
		i++;
	}
	p[i] = '\0';
	return (p);
}