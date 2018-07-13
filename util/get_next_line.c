/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:07:42 by ihoienko          #+#    #+#             */
/*   Updated: 2017/12/26 11:07:42 by ihoienko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static t_gnl	*find_fd_list(int fd, t_gnl **lst)
{
	t_gnl *data;

	data = *lst;
	while (data)
	{
		if (data->fd == fd)
		{
			if (!(data->content))
				data->content = ft_strnew(0);
			return (data);
		}
		data = data->next;
	}
	if (!(data = malloc(sizeof(*data))))
		return (NULL);
	data->fd = fd;
	data->content = ft_strnew(0);
	data->next = *lst;
	*lst = data;
	return (data);
}

static int		read_fd(int fd, t_gnl *lst)
{
	char	str[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret] = ENDO;
		temp = lst->content;
		if (!(lst->content = ft_strjoin(lst->content, str)))
			return (-1);
		ft_strdel(&temp);
		if (ft_strchr(lst->content, ENDL))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ft_strlen(lst->content) == 0)
		return (0);
	return (1);
}

static int		fill_line(t_gnl *current, char **line)
{
	char	*tmp;
	char	*ptr;

	if (*(current->content))
	{
		if (!(ptr = ft_strchr(current->content, '\n')))
		{
			*line = current->content;
			current->content = NULL;
		}
		else
		{
			*line = ft_strnew(ptr - current->content);
			ft_memcpy(*line, current->content, ptr - current->content);
			tmp = current->content;
			current->content = ft_strdup(++ptr);
			ft_strdel(&tmp);
		}
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl	*data;
	t_gnl			*current;
	int				ans;

	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ans = read(fd, "", 0)) < 0)
		return (-1);
	current = find_fd_list(fd, &data);
	if (!(ft_strchr(current->content, ENDL)))
	{
		ans = read_fd(fd, current);
		if (ans < 0)
			return (-1);
		if (ans == 0)
			return (0);
	}
	return (fill_line(current, line) > 0 ? 1 : 0);
}
