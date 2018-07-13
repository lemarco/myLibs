/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:01:42 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/26 18:01:43 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = ft_memalloc(size + 1);
	if (!str)
		return (NULL);
	ft_memset(str, '\0', size);
	return ((char *)str);
}
