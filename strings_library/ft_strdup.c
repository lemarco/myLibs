/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:27:04 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:27:05 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = ft_strlen(s1);
	str = (char*)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
