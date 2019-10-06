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

// int g_pc1[] =
// {
// 	57, 49, 41, 33, 25, 17, 9,
// 	1, 58, 50, 42, 34, 26, 18,
// 	10, 2, 59, 51, 43, 35, 27,
// 	19, 11, 3, 60, 52, 44, 36,
// 	63, 55, 47, 39, 31, 23, 15,
// 	7, 62, 54, 46, 38, 30, 22,
// 	14, 6, 61, 53, 45, 37, 29,
// 	21, 13, 5, 28, 20, 12, 4
// };

// int g_pc2[] =
// {
// 	14, 17, 11, 24, 1, 5,
// 	3, 28, 15, 6, 21, 10,
// 	23, 19, 12, 4, 26, 8,
// 	16, 7, 27, 20, 13, 2,
// 	41, 52, 31, 37, 47, 55,
// 	30, 40, 51, 45, 33, 48,
// 	44, 49, 39, 56, 34, 53,
// 	46, 42, 50, 36, 29, 32
// };

// int g_shifts[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

// void					check_hex(t_ssl *ssl, char *s)
// {
// 	int					i;
// 	unsigned long long	tmp;

// 	i = 0;
// 	while (s[i] != '\0' && i < 16)
// 	{
// 		if (s[i] >= 'a' && s[i] <= 'f')
// 			tmp = tmp * 16 + (10 + s[i] - 'a');
// 		else if (s[i] >= '0' && s[i] <= '9')
// 			tmp = tmp * 16 + (s[i] - '0');
// 		else if (s[i] >= 'A' && s[i] <= 'F')
// 			tmp = tmp * 16 + (10 + s[i] - 'A');
// 		else
// 		{
// 			ft_printf("Error, enter hex digit");
// 			exit(1);
// 		}
// 		i++;
// 	}
// 	while (i++ < 16)
// 		tmp *= 16;
// 	if (!ssl->key && (ssl->key = 1))
// 		ssl->des_key = tmp;
// 	else if (ssl->des_cbc && !ssl->vector && (ssl->vector = 1))
// 		ssl->des_iv = tmp;
// }

// char					*get_input(char *prompt)
// {
// 	char				*pass1;
// 	char				*pass2;

// 	ft_printf("\n%s", prompt);
// 	ft_read_fd(0, &pass1);
// 	ft_printf("\nVerifying - %s", prompt);
// 	ft_read_fd(0, &pass2);
// 	ft_printf("\n");
// 	if (ft_strcmp(pass1, pass2) != 0)
// 	{
// 		ft_printf("\nVerifying failure");
// 		free(pass1);
// 		free(pass2);
// 		exit(1);
// 	}
// 	free(pass1);
// 	return (pass2);
// }

int g_pc1[] =
{
	57, 49, 41, 33, 25, 17, 9,
	1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27,
	19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,
	7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29,
	21, 13, 5, 28, 20, 12, 4
};

int g_pc2[] = 
{
	14,	17,	11,	24,	1,	5,
	3,	28,	15,	6,	21,	10,
	23,	19,	12,	4,	26,	8,
	16,	7,	27,	20,	13,	2,
	41,	52,	31,	37,	47,	55,
	30,	40,	51,	45,	33,	48,
	44,	49,	39,	56,	34,	53,
	46,	42,	50,	36,	29,	32
};

int g_ip[] = 
{
	58,	50,	42,	34,	26,	18,	10,	2,
	60,	52,	44,	36,	28,	20,	12,	4,
	62,	54,	46,	38,	30,	22,	14,	6,
	64,	56,	48,	40,	32,	24,	16,	8,
	57,	49,	41,	33,	25,	17,	9,	1,
	59,	51,	43,	35,	27,	19,	11,	3,
	61,	53,	45,	37,	29,	21,	13,	5,
	63,	55,	47,	39,	31,	23,	15,	7
};

//permutate()
unsigned long long		permutate_choice_1(unsigned long long p)
{
	unsigned long long	out;
	int					i;

	out = 0;
	i = 56;
	while (i-- > 0)
	{
		if ((p >> (64 - g_pc1[i])) & 1)
			out = (unsigned long long)1 << (56 - 1 - i) | out;
	}
	return (out);
}

unsigned long long		permutate_choice_2(unsigned long long p)
{
	unsigned long long	out;
	int					i;

	out = 0;
	i = 64;
	while (i-- > 0)
	{
		if ((p >> (64 - g_ip[i])) & 1)
			out = (unsigned long long)1 << (64 - 1 - i) | out;
	}
	return (out);
}

unsigned long long		permutate_choice_3(unsigned long long p)
{
	unsigned long long	out;
	int					i;

	out = 0;
	i = 48;
	while (i-- > 0)
	{
		if ((p >> (56 - g_ip[i])) & 1)
			out = (unsigned long long)1 << (48 - 1 - i) | out;
	}
	return (out);
}


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
