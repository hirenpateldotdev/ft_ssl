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

int g_shifts[] = { 1, 1, 2, 2, 2, 2, 2, 2,
	1, 2, 2, 2, 2, 2, 2, 1 };

static int			circular_swift(unsigned int num, int i)
{
	int				dropped;
	int				rot;

	rot = 0;
	while (rot < g_shifts[i])
	{
		dropped = (num >> (32 - 1 - 4)) & 1;
		num = (num << 1) | dropped;
		rot++;
	}
	num %= B28;
	return (num);
}

void				set_subkeys(t_ssl *ssl)
{
	unsigned int	c;
	unsigned int	d;
	int				i;

	i = 0;
	ssl->des_key = permutate_choice_5(ssl->des_key, 0);
	c = ssl->des_key / B28;
	d = ssl->des_key % B28;
	while (i < 16)
	{
		c = circular_swift(c, i);
		d = circular_swift(d, i);
		ssl->des_subkeys[i] = (uint64_t)(c) * B28 + d;
		ssl->des_subkeys[i] = permutate_choice_5(ssl->des_subkeys[i], 1);
		i++;
	}
}

char				*get_input(char *prompt)
{
	char			*pass1;
	char			*pass2;

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

void				check_hex(t_ssl *ssl, char *s)
{
	int				i;
	uint64_t		tmp;

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
			ft_printf("Error, enter hex digits");
			exit(1);
		}
		i++;
	}
	while (i++ < 16)
		tmp *= 16;
	if (!ssl->key && (ssl->key = 1))
		ssl->des_key = tmp;
	else if (ssl->des_cbc && !ssl->vector && (ssl->vector = 1))
		ssl->des_iv = tmp;
}
