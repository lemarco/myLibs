/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:23:36 by ihoienko          #+#    #+#             */
/*   Updated: 2018/01/19 10:23:36 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_itoa_base_fill(uintmax_t tmp, int b, char s[BUF_SIZE])
{
	int		len;

	if (tmp && !(g_e.fl & FL_PTR) && (g_e.fl & FL_ZERO)
		&& (g_e.fl & FL_SHP) &&
	b == HEX && !(g_e.fl & FL_LONG2) && g_e.printed > 3)
		g_e.printed -= 2;
	len = g_e.printed;
	g_e.c = 'a' - DEC - ((g_e.fl & FL_UPLETTER) >> 1);
	while (len--)
	{
		s[len] = tmp % b + ((tmp % b < DEC) ? '0' : g_e.c);
		tmp /= b;
	}
	(g_e.fl & FL_DF_PREC && g_e.fl & FL_ZERO) ? s[0] = SPACE : 0;
}

static void	ft_printf_itoa(intmax_t n, int len)
{
	char		s[21];
	uintmax_t	tmp;

	tmp = ABS(n);
	while (tmp)
	{
		tmp /= 10;
		++len;
	}
	if ((n < 0 || g_e.fl & FL_PLUS || g_e.fl & FL_SPACE) && g_e.fl & FL_ZERO)
		--g_e.precision;
	g_e.printed = MAX(len, g_e.precision);
	if (n < 0 || g_e.fl & FL_PLUS || g_e.fl & FL_SPACE)
		++g_e.printed;
	g_e.padding = (g_e.printed > g_e.a_len) ? 0 : g_e.a_len - g_e.printed;
	ft_printf_width(0);
	tmp = ABS(n);
	ft_printf_itoa_base_fill(tmp, DEC, s);
	(g_e.fl & FL_SPACE) ? s[0] = SPACE : 0;
	(n < 0) ? s[0] = '-' : 0;
	(g_e.fl & FL_PLUS && n >= 0) ? s[0] = '+' : 0;
	ft_printf_writer(s, g_e.printed);
	ft_printf_width(1);
}

void		ft_printf_putnbr(void)
{
	intmax_t	n;

	if (g_e.fl & FL_LONG || g_e.fl & FL_LONG2)
		n = (g_e.fl & FL_LONG2) ? ((intmax_t)va_arg(g_e.ap, long long)) :
			((intmax_t)va_arg(g_e.ap, long));
	else if (g_e.fl & FL_SHORT || g_e.fl & FL_SHORT2)
		n = (g_e.fl & FL_SHORT2) ? (intmax_t)((char)va_arg(g_e.ap, int)) :
			(intmax_t)((short)va_arg(g_e.ap, int));
	else if (g_e.fl & FL_INTMAX)
		n = (va_arg(g_e.ap, intmax_t));
	else if (g_e.fl & FL_SIZE_T)
		n = ((intmax_t)va_arg(g_e.ap, ssize_t));
	else
		n = ((intmax_t)va_arg(g_e.ap, int));
	(g_e.fl & FL_ZERO) ? g_e.precision = g_e.a_len : 0;
	ft_printf_itoa(n, 0);
}

void		ft_printf_itoa_base(uintmax_t n, int b)
{
	uintmax_t	tmp;
	char		s[21];
	int			ext;

	g_e.printed = 0;
	tmp = n;
	while (tmp && ++g_e.printed)
		tmp /= b;
	(g_e.fl & FL_ZERO) ? g_e.precision = g_e.a_len : 0;
	ext = (g_e.printed >= g_e.precision) ? 0 : 1;
	g_e.printed = MAX(g_e.precision, g_e.printed);
	((g_e.fl & FL_SHP) && b == OCT && !ext) ? --g_e.a_len : 0;
	((g_e.fl & FL_SHP) && b == OCT && !n && (g_e.fl & FL_DF_PREC)) ?
	++g_e.printed : 0;
	((g_e.fl & FL_SHP) && b == HEX && !(g_e.fl & FL_ZERO)) ? g_e.a_len -= 2 : 0;
	g_e.padding = MAX(0, (g_e.a_len - g_e.printed));
	ft_printf_width(0);
	if ((n || (g_e.fl & FL_PTR))
		&& (g_e.fl & FL_SHP) && ((b == OCT && !ext) || (b == HEX)))
		ft_printf_writer("0", 1);
	if ((n || (g_e.fl & FL_PTR)) && (g_e.fl & FL_SHP) && b == HEX)
		ft_printf_writer((g_e.fl & FL_UPLETTER) ? "X" : "x", 1);
	ft_printf_itoa_base_fill(n, b, s);
	ft_printf_writer(s, g_e.printed);
	ft_printf_width(1);
}

void		ft_printf_putnb_base(int base)
{
	uintmax_t	n;

	if (g_e.fl & FL_LONG || g_e.fl & FL_LONG2)
		n = (g_e.fl & FL_LONG2) ?
	((intmax_t)va_arg(g_e.ap, unsigned long long)) :
	((intmax_t)va_arg(g_e.ap, unsigned long));
	else if (g_e.fl & FL_SHORT || g_e.fl & FL_SHORT2)
		n = (g_e.fl & FL_SHORT2) ?
	(uintmax_t)((unsigned char)va_arg(g_e.ap, int))
	: (uintmax_t)((unsigned short)va_arg(g_e.ap, int));
	else if (g_e.fl & FL_INTMAX)
		n = (va_arg(g_e.ap, uintmax_t));
	else if (g_e.fl & FL_SIZE_T)
		n = ((uintmax_t)va_arg(g_e.ap, size_t));
	else
		n = (uintmax_t)va_arg(g_e.ap, unsigned int);
	ft_printf_itoa_base(n, base);
}
