#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#include "../strings_library/strings_library.h"
#include "../util/util.h"
# include <string.h>

# define MAX(a, b) a > b ? a : b
# define MIN(a, b) a < b ? a : b
# define ABS(a)	(a < 0) ? -a : a
# define PURPLE 		"\033[35m"
# define CYAN			"\033[36m"
# define RED			"\033[31m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define EOC			"\033[0m"
# define GREEN			"\033[32m"
# define FL_SHP			0x1
# define FL_SPACE		0x2
# define FL_PLUS		0x4
# define FL_MINUS		0x8
# define FL_ZERO		0x10
# define FL_WILDCARD	0x20
# define FL_UPLETTER	0x40
# define FL_SHORT		0x80
# define FL_SHORT2		0x100
# define FL_LONG		0x200
# define FL_LONG2		0x400
# define FL_INTMAX		0x800
# define FL_SIZE_T		0x1000
# define FL_MIN_LEN		0x2000
# define FL_DF_PREC		0x4000
# define FL_PTR			0x8000
# define BUF_SIZE 		256
# define SPACE			' '
# define HEX			16
# define DEC			10
# define OCT			8

typedef struct		s_e
{
	short			n;
	short			fl;
	char			*f;
	va_list			ap;
	int				iter;
	int				printf_len;
	int				a_len;
	int				precision;
	int				padding;
	int				buffer_index;
	char			buff[BUF_SIZE];
	unsigned		c;
	int				printed;
}					t_env;
t_env				g_e;

int		ft_printf_str_chr_iter(char *s, int c, int i);
int		ft_printf_strchr_iter_all(char *s, int c, int i);
size_t	ft_printf_wcharlen(unsigned wc);
size_t	ft_printf_wstrlen(unsigned *s);
int		ft_printf(const char *format, ...);
void	ft_printf_no_spec(void);
void	ft_printf_color(void);
void	ft_printf_putnbr(void);
void	ft_printf_itoa_base(uintmax_t n, int b);
void	ft_printf_putnb_base(int base);
void	ft_printf_format_parser(void);
void	ft_printf_put_pointer(void);
void	ft_printf_putstr_helper(void);
void	ft_printf_putchar(unsigned c);
void	ft_printf_putwstr(void);
void	ft_printf_writer(void *elem, size_t size);
void	ft_printf_width(int n);

#endif