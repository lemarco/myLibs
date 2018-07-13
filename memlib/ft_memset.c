/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:29:01 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:29:01 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memlib.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	size_t			static_len;

	static_len = len;
	if (static_len == 0)
		return (b);
	a = (unsigned char *)b;
	while (static_len-- > 0)
		*a++ = (unsigned char)c;
	return (b);
}
