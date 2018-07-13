/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:21:50 by ihoienko          #+#    #+#             */
/*   Updated: 2018/01/19 10:21:50 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_str_chr_iter(char *s, int c, int i)
{
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

int		ft_printf_strchr_iter_all(char *s, int c, int i)
{
	while (s[++i])
		if (s[i] == c || s[i] == c + 32)
			return (i);
	return (-1);
}

size_t	ft_printf_wcharlen(unsigned wc)
{
	if (wc < 0x100)
		return (1);
	else if (wc < 0x1000)
		return (2);
	else if (wc < 0x10000)
		return (3);
	return (4);
}

size_t	ft_printf_wstrlen(unsigned *s)
{
	size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len += ft_printf_wcharlen(*s);
		++s;
	}
	return (len);
}
