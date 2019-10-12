/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

//permutate()

unsigned long long		permutate(unsigned long long in, int *permutation,
														int tab_size, int size)
{
	unsigned long long	out;
	int					i;

	out = 0;
	i = tab_size;
	while (i-- > 0)
	{
		if ((in >> (size - permutation[i])) & 1)
			out = (unsigned long long)1 << (tab_size - 1 - i) | out;
	}
	return (out);
}
