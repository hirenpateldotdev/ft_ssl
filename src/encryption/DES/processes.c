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

void		des_processes(t_ssl *ssl, t_input **input,\
						uint64_t block_s)
{
	unsigned char	blk[9];
	int				j;
	int				len;

	ft_bzero(blk, 9);
	len = 8;
	if (ssl->mode == 1)
		decryption_depadding(&block_s, &len);
	if (block_s != 0)
	{
		if (ssl->des_cbc && ssl->mode == 0)
			ssl->des_iv = block_s;
		j = 8;
		while (--j >= 0)
			blk[7 - j] = block_s / ft_exponent(256, j) % 256;
		write(input[0]->output_file, blk, len);
	}
}
