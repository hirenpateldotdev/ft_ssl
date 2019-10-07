/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:17:21 by hirenpat          #+#    #+#             */
/*   Updated: 2018/12/17 14:17:25 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *str, size_t len)
{
	ft_memset(str, 0, len);
}

long long		ft_exponent(long long nbr, int power)
{
	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	else if (power >= 2)
	{
		nbr *= ft_exponent(nbr, power - 1);
	}
	return (nbr);
}