/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:28:03 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:28:04 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memlib.h"

void	*ft_memmove(void *s1, const void *s2, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)s2;
	str2 = (char *)s1;
	if (str1 < str2)
		while ((int)(--len) >= 0)
			*(str2 + len) = *(str1 + len);
	else
		while (i < len)
		{
			*(str2 + i) = *(str1 + i);
			i++;
		}
	return (s1);
}
