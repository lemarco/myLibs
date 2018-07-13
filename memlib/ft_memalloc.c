/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:46:10 by ihoienko          #+#    #+#             */
/*   Updated: 2017/10/26 14:46:10 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memlib.h"

void	*ft_memalloc(size_t size)
{
	void *memory;

	memory = malloc(size);
	if (memory == NULL)
		return (NULL);
	ft_memset(memory, 0, size);
	return (memory);
}
