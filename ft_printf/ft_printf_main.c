/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:21:21 by ihoienko          #+#    #+#             */
/*   Updated: 2018/01/19 10:21:22 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	ft_bzero(&g_e, sizeof(g_e));
	g_e.f = (char*)format;
	va_start(g_e.ap, format);
	while (*g_e.f)
	{
		if (*g_e.f == '%')
		{
			g_e.f++;
			if (!*g_e.f)
				break ;
			ft_printf_format_parser();
		}
		else
			ft_printf_writer(g_e.f, 1);
		++g_e.f;
	}
	write(1, g_e.buff, g_e.buffer_index);
	va_end(g_e.ap);
	return (g_e.printf_len);
}

void		ft_printf_no_spec(void)
{
	if ((g_e.padding = g_e.a_len - 1) > 0)
	{
		ft_printf_width(0);
		ft_printf_writer(g_e.f, 1);
		ft_printf_width(1);
		return ;
	}
	ft_printf_writer(g_e.f, 1);
}

void		ft_printf_color(void)
{
	int len;

	g_e.printed = 5;
	if (!ft_strncmp(g_e.f, "{red}", (len = 5)))
		ft_printf_writer(RED, g_e.printed);
	else if (!ft_strncmp(g_e.f, "{green}", (len = 7)))
		ft_printf_writer(GREEN, g_e.printed);
	else if (!ft_strncmp(g_e.f, "{yellow}", (len = 8)))
		ft_printf_writer(YELLOW, g_e.printed);
	else if (!ft_strncmp(g_e.f, "{blue}", (len = 6)))
		ft_printf_writer(BLUE, g_e.printed);
	else if (!ft_strncmp(g_e.f, "{purple}", (len = 8)))
		ft_printf_writer(PURPLE, g_e.printed);
	else if (!ft_strncmp(g_e.f, "{cyan}", (len = 6)))
		ft_printf_writer(CYAN, g_e.printed);
	else if (!ft_strncmp(g_e.f, "{eoc}", (len = 5)))
		ft_printf_writer(EOC, --g_e.printed);
	else if (!(len = 0))
		g_e.printed &= 0x0;
	g_e.f += len - 1;
	g_e.printf_len += g_e.printed;
}
