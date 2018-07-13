/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:52:15 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/26 19:52:15 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	if (s == NULL)
		return (NULL);
	sub = (char*)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
