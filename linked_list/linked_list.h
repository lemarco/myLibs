#ifndef LINKED_LIST_H
# define LINKED_LIST_H
# include <stdlib.h>
# include "../memlib/memlib.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void		ft_lstadd(t_list **alst, t_list *new);
t_list		*ft_lstnew_noalloc(void const *content, size_t content_size);
t_list		*ft_lstnew(void const *content, size_t content_size);
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void		ft_lstaddend(t_list **alst, t_list *new);

#endif