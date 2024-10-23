/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:13:16 by mhotting          #+#    #+#             */
/*   Updated: 2024/04/03 12:56:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_if(
		t_list **lst, void *data_ref, int (*cmp)(), void (*del)(void *)
)
{
	t_list	*node;
	t_list	*prev;

	if (lst == NULL || *lst == NULL || cmp == NULL || del == NULL)
		return ;
	prev = NULL;
	node = *lst;
	while (node != NULL)
	{
		if (cmp(node->content, data_ref) == 0)
		{
			if (prev == NULL)
			{
				*lst = (*lst)->next;
				ft_lstdelone(node, del);
				node = *lst;
				continue ;
			}
			prev->next = node->next;
			ft_lstdelone(node, del);
		}
		else
			prev = node;
		node = prev->next;
	}
}
