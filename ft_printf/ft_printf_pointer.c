/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_poiner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:27:20 by ihoienko          #+#    #+#             */
/*   Updated: 2018/01/19 10:27:21 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_put_pointer(void)
{
	void	*pointer;

	pointer = va_arg(g_e.ap, void *);
	g_e.fl &= ~FL_SHP;
	g_e.a_len -= (g_e.fl & FL_ZERO ? 2 : 0);
	g_e.padding = (g_e.printed > g_e.a_len - 3) ? 0 :
		g_e.a_len - 3 - g_e.printed;
	g_e.fl |= FL_SHP;
	g_e.fl |= FL_PTR;
	ft_printf_itoa_base((uintmax_t)pointer, HEX);
}
