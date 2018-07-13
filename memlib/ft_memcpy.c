/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:28:34 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:28:35 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memlib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *nsrc;
	unsigned char *ndst;

	nsrc = (unsigned char *)src;
	ndst = (unsigned char *)dst;
	while (n--)
		*ndst++ = *nsrc++;
	return (dst);
}
