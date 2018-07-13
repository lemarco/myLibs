/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:27:35 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:27:35 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memlib.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *buf1;
	unsigned char *buf2;

	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (n--)
	{
		if (*buf1 != *buf2)
			return (*buf1 - *buf2);
		if (n)
		{
			buf1++;
			buf2++;
		}
	}
	return (0);
}
