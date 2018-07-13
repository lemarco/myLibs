#ifndef STRINGS_LIBRARY_H
#define STRINGS_LIBRARY_H
#include <stdlib.h>
#include "../memlib/memlib.h"

char			*ft_strtrim(char const *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strstr(const char *s1, const char *s2);
char		**ft_strsplit(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strnew(size_t size);
int	ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strncpy(char *s1, const char *s2, size_t len);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strmap(char const *s, char (*f)(char));
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *s1, const char *s2, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_striter(char *s, void (*f)(char *));
int	ft_strequ(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_strdel(char **as);
char	*ft_strcpy(char *s1, const char *s2);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_strclr(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strcat(char *s1, const char *s2);

#endif