/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:15:07 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/31 22:15:08 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\r' || c == '\v')
		return (1);
	else if (c == '\t' || c == '\f' || c == '\n')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long long	result;
	int					i;
	int					sign;

	i = 0;
	result = 0;
	while (ft_isspace(*str))
		str++;
	sign = ((*str == '-') ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10 + (str[i] - '0'));
		i++;
	}
	if ((i > 19) || (result > 9223372036854775807))
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return ((int)(result * sign));
}
