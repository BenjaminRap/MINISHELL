/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:21:34 by mhotting          #+#    #+#             */
/*   Updated: 2024/04/03 02:23:34 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst, void (*print)(void *))
{
	if (lst == NULL || print == NULL)
		return ;
	while (lst != NULL)
	{
		print(lst->content);
		lst = lst->next;
	}
}
