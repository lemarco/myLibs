#ifndef MEMLIB_H
# define MEMLIB_H
# include <stdlib.h>

void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_memdel(void **ap);
void	*ft_memmove(void *s1, const void *s2, size_t len);
void	*ft_memset(void *b, int c, size_t len);

#endif