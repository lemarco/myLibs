/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:39:56 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 12:39:56 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] &&
		(unsigned char)s1[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
