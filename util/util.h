#ifndef UTIL_H
#define UTIL_H
#include "../strings_library/strings_library.h"
#include "unistd.h"
#include "../output/output.h"

# define ENDL '\n'
# define ENDO '\0'
# define BUFF_SIZE 50
typedef struct		s_gnl
{
	int				fd;
	struct s_gnl	*next;
	char			*content;
}					t_gnl;
int			ft_atoi(const char *str);
void	ft_error(const char *error);
int	ft_isalnum(int c);
int			ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
char		*ft_itoa(int n);
int	ft_tolower(int c);
int	ft_toupper(int c);
int				get_next_line(const int fd, char **line);


#endif