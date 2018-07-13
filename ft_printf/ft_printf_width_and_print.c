/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:20:31 by ihoienko          #+#    #+#             */
/*   Updated: 2018/01/15 13:20:32 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_writer(void *elem, size_t size)
{
	int			diff;
	long long	i;

	i = 0;
	while (BUF_SIZE - g_e.buffer_index < (int)size)
	{
		diff = BUF_SIZE - g_e.buffer_index;
		ft_memcpy(&(g_e.buff[g_e.buffer_index]), &(elem[i]), diff);
		size -= diff;
		i += diff;
		g_e.buffer_index += diff;
		g_e.printf_len += diff;
		write(1, g_e.buff, g_e.buffer_index);
		g_e.buffer_index = 0;
	}
	ft_memcpy(&(g_e.buff[g_e.buffer_index]), &(elem[i]), size);
	g_e.buffer_index += size;
	g_e.printf_len += size;
}

void	ft_printf_width(int n)
{
	if (!g_e.padding)
		return ;
	g_e.c = 32 | (g_e.fl & FL_ZERO);
	if (!n && !(g_e.fl & FL_MINUS))
		while (g_e.padding--)
			ft_printf_writer(&g_e.c, 1);
	else if (n && (g_e.fl & FL_MINUS))
		while (g_e.padding--)
			ft_printf_writer(&g_e.c, 1);
}
