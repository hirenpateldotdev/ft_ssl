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

int		g_ip[] = {58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7};

int		g_e[] = {32, 1, 2, 3, 4, 5,
	4, 5, 6, 7, 8, 9,
	8, 9, 10, 11, 12, 13,
	12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21,
	20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29,
	28, 29, 30, 31, 32, 1};

int		g_p[] = {16, 7, 20, 21,
	29, 12, 28, 17,
	1, 15, 23, 26,
	5, 18, 31, 10,
	2, 8, 24, 14,
	32, 27, 3, 9,
	19, 13, 30, 6,
	22, 11, 4, 25};

int		g_fp[] = {40, 8, 48, 16, 56, 24, 64, 32,
	39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41, 9, 49, 17, 57, 25};

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


unsigned long long		permutate_choice_1(unsigned long long in)
{
	unsigned long long	out;
	int					i;

	out = 0;
	i = 64;
	while (i-- > 0)
	{
		if ((in >> (64 - g_ip[i])) & 1)
			out = (unsigned long long)1 << (64 - 1 - i) | out;
	}
	return (out);
}

unsigned long long		permutate_choice_2(unsigned long long in)
{
	unsigned long long	out;
	int					i;

	out = 0;
	i = 48;
	while (i-- > 0)
	{
		if ((in >> (32 - g_e[i])) & 1)
			out = (unsigned long long)1 << (48 - 1 - i) | out;
	}
	return (out);
}

unsigned long long		permutate_choice_3(unsigned long long in)
{
	unsigned long long	out;
	int					i;

	out = 0;
	i = 32;
	while (i-- > 0)
	{
		if ((in >> (32 - g_p[i])) & 1)
			out = (unsigned long long)1 << (32 - 1 - i) | out;
	}
	return (out);
}

unsigned long long		permutate_choice_4(unsigned long long in_1, unsigned long long in_2)
{
	unsigned long long in;
	unsigned long long	out;
	int					i;

	in = in_1 * 4294967296 + in_2;
	out = 0;
	i = 64;
	while (i-- > 0)
	{
		if ((in >> (64 - g_fp[i])) & 1)
			out = (unsigned long long)1 << (64 - 1 - i) | out;
	}
	return (out);
}