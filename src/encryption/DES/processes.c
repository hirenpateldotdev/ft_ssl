/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

void		remove_padding_for_decryption(unsigned long long *s_blk, int *len)
{
	int	j;

	j = *s_blk % 256;
	if (j > 0 && j <= 8)
	{
		*s_blk = (j == 8) ? 0 : *s_blk / ft_power(256, j) * ft_power(256, j);
		*len = 8 - j;
	}
}

void		des_processes(t_ssl *ssl, t_input **input, unsigned long long s_blk)
{
	unsigned char	blk[9];
	int				j;
	int				len;

	// ft_printf("des_processes\n");
	ft_bzero(blk, 9);
	len = 8;
	if (ssl->mode == 1)
		remove_padding_for_decryption(&s_blk, &len);
	if (s_blk != 0)
	{
		if (ssl->des_cbc && ssl->mode == 0)
			ssl->des_iv = s_blk;
		j = 8;
		while (--j >= 0)
			blk[7 - j] = s_blk / ft_power(256, j) % 256;
		write(input[0]->output_file, blk, len);
	}
}
