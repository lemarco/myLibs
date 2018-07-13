/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:25:49 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:25:50 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *str;

	str = s1;
	while (*str)
		str++;
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (s1);
}
