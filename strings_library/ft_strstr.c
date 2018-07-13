/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:01:19 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 14:01:20 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return ((char*)s1);
	if (s1[i] == '\0')
		return (NULL);
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
