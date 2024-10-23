/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:14:10 by mhotting          #+#    #+#             */
/*   Updated: 2024/03/18 13:59:19 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol_base(char *nbr, char *base)
{
	unsigned long	res;
	long			sign;
	size_t			base_len;

	if (nbr == NULL || base == NULL || !ft_is_valid_base(base))
		return (0);
	res = 0;
	sign = 1;
	base_len = ft_strlen(base);
	while (ft_isspace(*nbr))
		nbr++;
	if (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	while (*nbr && ft_strchr(base, *nbr) != NULL)
	{
		res *= base_len;
		res += ft_strchr(base, *nbr) - base;
		nbr++;
	}
	return (sign * res);
}
