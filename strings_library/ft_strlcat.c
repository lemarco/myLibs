/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:25:03 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:25:04 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t		i;
	int			j;
	size_t		s1_len;
	size_t		s2_len;

	i = ft_strlen(s1);
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (size < s1_len + 1)
		return (s2_len + size);
	if (size > s1_len + 1)
	{
		while (i < size - 1)
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
		s1[i] = '\0';
	}
	return (s1_len + s2_len);
}
