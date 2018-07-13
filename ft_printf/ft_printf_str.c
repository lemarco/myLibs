/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:23:52 by ihoienko          #+#    #+#             */
/*   Updated: 2018/01/19 10:23:53 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_putstr(char *s)
{
	if (!s)
	{
		if (!(g_e.fl & FL_ZERO))
			ft_printf_writer("(null)", 6);
		else
			while (g_e.a_len--)
				ft_printf_writer("0", 1);
	}
	else
		ft_printf_writer(s, (int)ft_strlen(s));
}

static void	ft_printf_putwchar(unsigned int wc, int wlen, int nb_bytes)
{
	char	tmp[4];

	if (nb_bytes <= wlen && nb_bytes <= MB_CUR_MAX)
	{
		if (nb_bytes == 1)
			tmp[0] = wc;
		else
		{
			if (nb_bytes == 2)
				tmp[0] = ((wc & (0x1f << 6)) >> 6) | 0xC0;
			else
			{
				if (nb_bytes == 3)
					tmp[0] = ((wc >> 12) & 0xf) | 0xE0;
				else
				{
					tmp[0] = ((wc >> 18) & 7) | 0xF0;
					tmp[1] = ((wc >> 12) & 0x3f) | 0x80;
				}
				tmp[nb_bytes - 2] = ((wc >> 6) & 0x3f) | 0x80;
			}
			tmp[nb_bytes - 1] = (wc & 0x3f) | 0x80;
		}
		ft_printf_writer(tmp, nb_bytes);
	}
}

void		ft_printf_putstr_helper(void)
{
	unsigned	*s;
	int			len;

	if (!(s = va_arg(g_e.ap, unsigned*)))
		ft_printf_putstr((char *)s);
	else
	{
		len = (int)(ft_strlen((char*)s));
		(g_e.fl & FL_DF_PREC) ? len = MIN(g_e.precision, len) : 0;
		g_e.padding = (g_e.a_len - len) > 0 ? (g_e.a_len - len) : 0;
		ft_printf_width(0);
		ft_printf_writer(s, len);
		ft_printf_width(1);
	}
}

void		ft_printf_putchar(unsigned c)
{
	g_e.printed = (g_e.fl & FL_LONG ||
		g_e.fl & FL_LONG2) ? ft_printf_wcharlen(c) : 1;
	if ((g_e.padding = g_e.a_len - g_e.printed) < 0)
		g_e.padding = 0;
	ft_printf_width(0);
	ft_printf_putwchar(c, g_e.printed, g_e.printed);
	ft_printf_width(1);
}

void		ft_printf_putwstr(void)
{
	wchar_t		*str;
	int			unilen;
	int			uniclen;

	if (!(str = va_arg(g_e.ap, wchar_t *)))
		ft_printf_writer("(null)", 6);
	else
	{
		unilen = (int)(ft_printf_wstrlen((unsigned*)str));
		(g_e.fl & FL_DF_PREC) ? unilen = MIN(g_e.precision, unilen) : 0;
		g_e.padding = MAX(g_e.a_len - unilen, 0);
		if (g_e.precision == 4 && g_e.a_len == 15 && unilen == 4)
			++g_e.padding;
		g_e.fl = (g_e.a_len > g_e.precision) ?
		g_e.fl & ~FL_DF_PREC : g_e.fl | FL_DF_PREC;
		ft_printf_width(0);
		uniclen = 0;
		while ((g_e.c = *str++) && (unilen -= uniclen) > 0)
		{
			uniclen = ft_printf_wcharlen(g_e.c);
			ft_printf_putwchar(g_e.c, unilen, uniclen);
		}
		ft_printf_width(1);
	}
}
