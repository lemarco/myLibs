/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:26:35 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:26:36 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

char	*ft_strncpy(char *s1, const char *s2, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (s2[i])
			s1[i] = s2[i];
		else
			while (i < len)
			{
				s1[i] = '\0';
				i++;
			}
		i++;
	}
	return (s1);
}
