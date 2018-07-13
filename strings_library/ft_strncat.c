/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:25:32 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:25:36 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = (int)ft_strlen(s1);
	while (i < n && s2[i] != '\0')
	{
		s1[last + i] = s2[i];
		i++;
	}
	s1[last + i] = '\0';
	return (s1);
}
