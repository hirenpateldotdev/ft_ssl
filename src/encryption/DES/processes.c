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

void		decryption_depadding(unsigned long long *block_s, int *len)
{
	int	j;

	j = *block_s % 256;
	if (j > 0 && j <= 8)
	{
		*block_s = (j == 8) ? 0 : *block_s / ft_exponent(256, j) * ft_exponent(256, j);
		*len = 8 - j;
	}
}

void		des_processes(t_ssl *ssl, t_input **input, unsigned long long block_s)
{
	unsigned char	blk[9];
	int				j;
	int				len;

	// ft_printf("des_processes\n");
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
		// (void)input;
		// ft_printf("\noutput_file = %d | content = %s | len = %d\n",input[0]->output_file, blk, len);
		write(input[0]->output_file, blk, len);
	}
}
