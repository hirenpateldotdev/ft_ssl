/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

int	g_sbox[32][16] = {{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
	{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
	{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
	{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},
	{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
	{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
	{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
	{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},
	{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
	{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
	{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
	{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},
	{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
	{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
	{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
	{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},
	{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
	{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
	{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
	{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3},
	{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
	{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
	{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
	{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},
	{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
	{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
	{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
	{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},
	{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
	{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
	{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
	{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}};

static unsigned long long	des_encrypt_handler(unsigned long long l,
					unsigned long long r, unsigned long long *subkeys, int i)
{
	unsigned long long		tmp_l;
	unsigned long long		tmp_box;
	unsigned long long		tmp_subkey;
	int						row_col[2];
	int						j;

	while (i++ < 16)
	{
		tmp_l = l;
		l = r;
		r = permutate_choice_2(r);
		tmp_subkey = subkeys[i - 1] ^ r;
		j = 8;
		tmp_box = 0;
		while (--j >= 0)
		{
			row_col[1] = (tmp_subkey % 64) / 2 % 16;
			row_col[0] = (tmp_subkey % 64) / 32 * 2 + (tmp_subkey % 64) % 2;
			tmp_box += g_sbox[row_col[0] + j * 4][row_col[1]]
						* ft_exponent(16, 7 - j);
			tmp_subkey /= 64;
		}
		r = permutate_choice_3(tmp_box) ^ tmp_l;
	}
	return (permutate_choice_4(r, l));
}

static unsigned long long	des_decrypt_handler(unsigned long long l,
					unsigned long long r, unsigned long long *subkeys, int i)
{
	unsigned long long		tmp_r;
	unsigned long long		tmp_box;
	unsigned long long		tmp_subkey;
	int						row_col[2];
	int						j;

	while (--i >= 0)
	{
		tmp_r = r;
		r = l;
		l = permutate_choice_2(l);
		tmp_subkey = subkeys[i] ^ l;
		j = 8;
		tmp_box = 0;
		while (--j >= 0)
		{
			row_col[1] = (tmp_subkey % 64) / 2 % 16;
			row_col[0] = (tmp_subkey % 64) / 32 * 2 + (tmp_subkey % 64) % 2;
			tmp_box += g_sbox[row_col[0] + j * 4][row_col[1]]
						* ft_exponent(16, 7 - j);
			tmp_subkey /= 64;
		}
		l = permutate_choice_3(tmp_box) ^ tmp_r;
	}
	return (permutate_choice_4(l, r));
}

static unsigned long long	crypt_des(t_ssl *ssl, unsigned long long block_s)
{
	unsigned long long		tmp;

	tmp = block_s;
	block_s = permutate_choice_1(block_s);
	if (ssl->encrypt)
		block_s = des_encrypt_handler(block_s / 4294967296,\
					block_s % 4294967296, ssl->des_subkeys, 0);
	else
		block_s = des_decrypt_handler(block_s % 4294967296,\
					block_s / 4294967296, ssl->des_subkeys, 16);
	if (ssl->des_cbc && !ssl->encrypt)
	{
		block_s = block_s ^ ssl->des_iv;
		ssl->des_iv = tmp;
	}
	return (block_s);
}

static void					valid_des(t_ssl *ssl, t_input **input, int i, int j)
{
	unsigned long long		block_s;

	while (i < (int)INPUT->length || (ssl->encrypt && ssl->padded == 0))
	{
		j = 0;
		block_s = 0;
		while (i < (int)INPUT->length && j++ < 8)
			block_s = block_s * 256 + (unsigned char)INPUT->content[i++];
		if (i == (int)INPUT->length && j < 8 && (ssl->padded = 8 - j))
		{
			while (j++ < 8)
				block_s = block_s * 256 + ssl->padded;
		}
		if (ssl->des_cbc && ssl->encrypt)
			block_s = block_s ^ ssl->des_iv;
		block_s = crypt_des(ssl, block_s);
		des_processes(ssl, input, block_s);
	}
}

int							des_handler(t_ssl *ssl, t_input **input)
{
	ft_printf("\ndes_handler\n");
	if (!ssl->key)
		check_hex(ssl, get_input("Enter your key: "));
	if (ssl->des_cbc && !ssl->vector)
		check_hex(ssl, get_input("Enter your initial vector: "));
	set_subkeys(ssl);
	valid_des(ssl, input, 0, 0);
	if (input[0]->output_file == 0)
		ft_printf("\n");
	return (1);
}
