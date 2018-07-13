/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:25:11 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/27 17:25:13 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static void	ft_itoa_isneg(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char		*ft_itoa(int n)
{
	int		tmp_n;
	int		len;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp_n = n;
	len = 2;
	neg = 0;
	ft_itoa_isneg(&n, &neg);
	while (tmp_n /= 10)
		len++;
	len += neg;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
