/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:07:40 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/21 14:26:48 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*first;
	t_list		*part;

	if (lst == NULL || f == NULL)
		return (NULL);
	part = f(lst);
	if ((new = ft_lstnew(part->content, part->content_size)) == NULL)
		return (NULL);
	lst = lst->next;
	first = new;
	while (lst != NULL)
	{
		part = f(lst);
		if ((new->next = ft_lstnew(part->content, part->content_size)) == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
