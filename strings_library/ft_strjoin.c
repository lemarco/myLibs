/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:09:42 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/26 21:09:42 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings_library.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*con;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	con = ft_strnew(len1 + len2);
	if (!con)
		return (NULL);
	con = ft_strcat(con, s1);
	con = ft_strcat(con, s2);
	return (con);
}
