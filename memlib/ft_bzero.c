/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:28:46 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:28:47 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			len;

	len = n;
	if (len == 0)
		return ;
	str = (unsigned char *)s;
	while (len-- > 0)
		*str++ = 0;
}
