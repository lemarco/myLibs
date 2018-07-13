/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:22:49 by ihoienko          #+#    #+#             */
/*   Updated: 2018/01/19 10:22:50 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_printf_parse_flags(void)
{
	while ((g_e.iter = ft_printf_str_chr_iter("# +-0*", *g_e.f, -1)) > -1 &&
		++g_e.f)
		g_e.fl |= (1 << g_e.iter);
	((g_e.fl & FL_MINUS) && !(g_e.fl & FL_WILDCARD)) ? g_e.fl &= ~FL_ZERO : 0;
	(g_e.fl & FL_PLUS) ? g_e.fl &= ~FL_SPACE : 0;
	if (g_e.fl & FL_WILDCARD)
	{
		g_e.fl &= ~FL_WILDCARD;
		if ((g_e.n = (int)va_arg(g_e.ap, int)) < 0)
		{
			g_e.fl |= FL_MINUS;
			g_e.n = -g_e.n;
		}
		else
			g_e.fl &= ~FL_MINUS;
		if (!(g_e.fl & FL_DF_PREC))
			g_e.a_len = g_e.n;
		else
		{
			g_e.precision = (!(g_e.fl & FL_MINUS)) ? g_e.n : 0;
			g_e.fl = (!g_e.n) ? g_e.fl | FL_DF_PREC : g_e.fl & ~FL_DF_PREC;
		}
	}
}

static	void	ft_printf_parse_precision(void)
{
	if (*g_e.f > 48 && *g_e.f < 58)
	{
		g_e.a_len = MAX(1, ft_atoi(g_e.f));
		while (*g_e.f > 47 && *g_e.f < 58)
			++g_e.f;
	}
	if (*g_e.f == 46)
	{
		++g_e.f;
		g_e.precision = MAX(ft_atoi(g_e.f), 0);
		while (*g_e.f > 47 && *g_e.f < 58)
			++g_e.f;
		g_e.fl |= FL_DF_PREC;
	}
}

static	void	ft_printf_parce_specifier(void)
{
	g_e.c = *g_e.f;
	if (g_e.c == 's')
		(g_e.fl & FL_LONG || g_e.fl & FL_LONG2) ?
	ft_printf_putwstr() : ft_printf_putstr_helper();
	else if (g_e.c == 'c' || g_e.c == 'C')
		ft_printf_putchar(va_arg(g_e.ap, unsigned));
	else if (ft_strchr("dDi", g_e.c))
		ft_printf_putnbr();
	else if (g_e.c == 'S')
		ft_printf_putwstr();
	else if (g_e.c == 'n')
		*va_arg(g_e.ap, int *) = g_e.printf_len;
	else if (ft_strchr("oOuUbBxX", g_e.c))
		ft_printf_putnb_base(
			ft_printf_strchr_iter_all(".b..ou..x", g_e.c, -1) << 1);
	else if (g_e.c == 'p')
		ft_printf_put_pointer();
	else if (g_e.c == '{')
		ft_printf_color();
	else
		ft_printf_no_spec();
}

void			ft_printf_format_parser(void)
{
	g_e.fl &= 0x0;
	g_e.a_len &= 0x0;
	g_e.precision &= 0x0;
	g_e.precision |= 0x1;
	ft_printf_parse_flags();
	ft_printf_parse_precision();
	while (1)
	{
		if (*g_e.f == 'l')
			g_e.fl |= (*(g_e.f + 1) == 'l' && ++g_e.f) ? FL_LONG2 : FL_LONG;
		else if (*g_e.f == 'h')
			g_e.fl |= (*(g_e.f + 1) == 'h' && ++g_e.f) ? FL_SHORT2 : FL_SHORT;
		else if (*g_e.f == 'j')
			g_e.fl |= FL_INTMAX;
		else if (*g_e.f == 'z')
			g_e.fl |= FL_SIZE_T;
		else
			break ;
		++g_e.f;
	}
	ft_printf_parse_flags();
	(g_e.fl & FL_PLUS) ? g_e.fl &= ~FL_SPACE : 0;
	if (ft_strchr("CDSUOBX", *g_e.f))
		g_e.fl |= (*g_e.f != 'X') ? FL_LONG : FL_UPLETTER;
	ft_printf_parce_specifier();
}
