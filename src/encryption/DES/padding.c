/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

void		decryption_depadding(uint64_t *block_s, int *len)
{
	int		j;

	j = *block_s % 256;
	if (j > 0 && j <= 8)
	{
		*block_s = (j == 8) ? 0 : *block_s / ft_exponent(256, j) *\
											ft_exponent(256, j);
		*len = 8 - j;
	}
}