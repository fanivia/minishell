/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 22:18:00 by fanivia           #+#    #+#             */
/*   Updated: 2020/09/11 22:18:07 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	**begin;
	t_list	*temp1;
	t_list	*temp2;

	if (!(begin = (t_list **)malloc(sizeof(t_list))))
		return (NULL);
	if (!lst || !(*begin = ft_lstnew(f(lst->content))) || f == NULL)
		return (NULL);
	lst = lst->next;
	temp1 = *begin;
	while (lst)
	{
		temp2 = temp1;
		if (!(temp1 = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(begin, del);
			return (NULL);
		}
		temp2->next = temp1;
		lst = lst->next;
	}
	temp1->next = NULL;
	return (*begin);
}
