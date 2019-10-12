/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 23:44:14 by hirenpat          #+#    #+#             */
/*   Updated: 2019/06/07 23:44:20 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "des.h"

int		g_pc1[] = {57, 49, 41, 33, 25, 17, 9,
	1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27,
	19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,
	7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29,
	21, 13, 5, 28, 20, 12, 4};

int		g_rot[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int		g_pc2[] = {14, 17, 11, 24, 1, 5,
	3, 28, 15, 6, 21, 10,
	23, 19, 12, 4, 26, 8,
	16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55,
	30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53,
	46, 42, 50, 36, 29, 32};

int g_shifts[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

static int				circular_swift(unsigned int num, int i)
{
	int					dropped;
	int					rot;

	rot = 0;
	while (rot < g_shifts[i])
	{
		dropped = (num >> (32 - 1 - 4)) & 1;
		num = (num << 1) | dropped;
		rot++;
	}
	num %= 268435456;
	return (num);
}

void					set_subkeys(t_ssl *ssl)
{
	unsigned int		c;
	unsigned int		d;
	int					i;

	i = 0;
	ssl->des_key = permutate(ssl->des_key, g_pc1, 56, 64);
	c = ssl->des_key / 268435456;
	d = ssl->des_key % 268435456;
	while (i < 16)
	{
		c = circular_swift(c, i);
		d = circular_swift(d, i);
		ssl->des_subkeys[i] = (unsigned long long)(c) * 268435456 + d;
		ssl->des_subkeys[i] = permutate(ssl->des_subkeys[i], g_pc2, 48, 56);
		i++;
	}
}

void					check_hex(t_ssl *ssl, char *s)
{
	int					i;
	unsigned long long	tmp;

	i = 0;
	while (s[i] != '\0' && i < 16)
	{
		if (s[i] >= 'a' && s[i] <= 'f')
			tmp = tmp * 16 + (10 + s[i] - 'a');
		else if (s[i] >= '0' && s[i] <= '9')
			tmp = tmp * 16 + (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			tmp = tmp * 16 + (10 + s[i] - 'A');
		else
		{
			ft_printf("Error, enter hex digit");
			exit(1);
		}
		i++;
	}
	// ft_printf("key = %d",ssl->key);
	while (i++ < 16)
		tmp *= 16;
	// ft_printf("\ncase %d\n",!ssl->key);
	if (!ssl->key && (ssl->key = 1))
	{
		// ft_printf("key is being set");
		ssl->des_key = tmp;
	}
	else if (ssl->des_cbc && !ssl->vector && (ssl->vector = 1))
		ssl->des_iv = tmp;
	// ft_printf("\nssl->key is set to = %s\n",ssl->des_key);
}

char					*get_input(char *prompt)
{
	char				*pass1;
	char				*pass2;

	ft_printf("\n%s", prompt);
	ft_read_fd(0, &pass1);
	ft_printf("\nVerifying - %s", prompt);
	ft_read_fd(0, &pass2);
	ft_printf("\n");
	if (ft_strcmp(pass1, pass2) != 0)
	{
		ft_printf("\nVerifying failure");
		free(pass1);
		free(pass2);
		exit(1);
	}
	free(pass1);
	return (pass2);
}
