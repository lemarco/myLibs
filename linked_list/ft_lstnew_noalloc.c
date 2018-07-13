/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_noalloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:10:04 by ihoienko          #+#    #+#             */
/*   Updated: 2018/02/07 18:10:04 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_list		*ft_lstnew_noalloc(void const *content, size_t content_size)
{
	t_list	*alst;

	alst = (t_list *)malloc(sizeof(t_list));
	if (alst == NULL)
		return (NULL);
	alst->next = NULL;
	if (content == NULL)
	{
		alst->content = NULL;
		alst->content_size = 0;
		return (alst);
	}
	alst->content = (void *)content;
	alst->content_size = content_size;
	return (alst);
}
