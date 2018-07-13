/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 13:56:43 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/25 13:56:44 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] &&
		(unsigned char)s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
