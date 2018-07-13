/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:22:37 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 15:22:38 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen((char *)s);
	while (len != 0 && s[len] != (char)c)
		len--;
	if (s[len] == (char)c)
		return ((char *)&s[len]);
	return (NULL);
}
