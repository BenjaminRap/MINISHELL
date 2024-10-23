/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:11:31 by mhotting          #+#    #+#             */
/*   Updated: 2024/04/03 11:45:56 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *data_ref, int (*cmp)())
{
	if (lst == NULL || cmp == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (cmp(lst->content, data_ref) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
