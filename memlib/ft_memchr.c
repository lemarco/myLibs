/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:27:48 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:27:49 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memlib.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}
